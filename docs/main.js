/* bookmark (thank you kind stranger): https://web.dev/serial/ */

let data = {
    moisture: [],
    brightness: [],
    times: []
};

class LineBreakTransformer {
    constructor() {
        // a container for holding stream data until a new line
        this.chunks = "";
    }

    transform(chunk, controller) {
        // append new chunks to existing chunks
        this.chunks += chunk;
        // for each line breaks in chunks, send the parsed lines out
        const lines = this.chunks.split("\r\n");
        this.chunks = lines.pop();
        lines.forEach((line) => controller.enqueue(line));
    }

    flush(controller) {
        // when the stream is closed, flush any remaining chunks out
        controller.enqueue(this.chunks);
    }
}

let connect = async () => {
    const port = await navigator.serial.requestPort();
    await port.open({
        baudRate: 9600,
        bufferSize: 50
    });
    let decoder = new TextDecoderStream();
    inputDone = port.readable.pipeTo(decoder.writable);
    inputStream = decoder.readable.pipeThrough(new TransformStream(new LineBreakTransformer()));;
    reader = inputStream.getReader();
}

let connectDevice = async () => {
    await connect();
    while (true) {
        const {
            value,
            done
        } = await reader.read();
        if (value) {
            try {
                let reading = JSON.parse(value);
                // console.log(reading);
                // data.moisture.push(parseInt(reading.moisture));
                // data.times.push(((new Date()).toLocaleString()));
                let date = (new Date()).toLocaleString();
                addData(moistureChart, date, [parseInt(reading.moisture)]);
                addData(brightnessChart, date, [parseInt(reading.brightness), parseInt(reading.brightness_setpoint)]);
                // addData(myChart, date, parseInt(reading.brightness));

            } catch (error) {
                console.log(error);
            }
        }
        if (done) {
            // allow the serial port to be closed later
            reader.releaseLock();
            break;
        }
    }
}

let saveChartData = async () => {
    console.log(moistureChart.data, brightnessChart.data)
    // todo

}

let addData = (chart, label, data) => {
    chart.data.labels.push(label);
    chart.data.datasets.map((dataset, i) => {
        dataset.data.push(data[i])
    })
    chart.update();
}

const moistureChartData = {
    labels: data.times,
    datasets: [{
        label: 'Soil moisture',
        backgroundColor: 'rgb(150, 193, 23)',
        borderColor: 'rgb(150, 193, 23)',
        data: data.moisture,
    }]
}

const brightnessChartData = {
    labels: data.times,
    datasets: [{
            label: 'Brightness',
            backgroundColor: 'rgb(204, 181, 24)',
            borderColor: 'rgb(204, 181, 24)',
            data: data.brightness,
        },
        {
            label: 'Setpoint',
            backgroundColor: 'rgb(214, 81, 24)',
            borderColor: 'rgb(214, 81, 24)',
            data: data.brightness_setpoint,
        }
    ]
}

const moistureChartConfig = {
    type: 'line',
    data: moistureChartData,
    options: {
        elements: {
            point: {
                radius: 2
            }
        },
        responsive: false,
        animation: {
            duration: 0
        },
        scales: {
            x: {
                ticks: {
                    display: false
                },
                time: {
                    unit: 'second'
                }
            },
            y: {
                min: 0,
                max: 100,
                ticks: {
                    callback: function (value, index, ticks) {
                        return `${value}%`;
                    }
                }
            }
        },
        plugins: {
            legend: {
                position: 'left'
            }
        }
    }
};

const brightnessChartConfig = {
    type: 'line',
    data: brightnessChartData,
    options: {
        elements: {
            point: {
                radius: 2
            }
        },
        layout: {
            padding: {
                left: 19
            }
        },
        responsive: false,
        animation: {
            duration: 0
        },
        scales: {
            x: {
                ticks: {
                    display: false
                },
                time: {
                    unit: 'second'
                }
            },
            y: {
                ticks: {
                    callback: function (value, index, ticks) {
                        return `${value} lx`;
                    }
                }
            }
        },
        plugins: {
            legend: {
                position: 'left'
            }
        }
    }
};

const moistureChart = new Chart(
    document.getElementById('moistureChart'),
    moistureChartConfig,

);

const brightnessChart = new Chart(
    document.getElementById('brightnessChart'),
    brightnessChartConfig
);