/* bookmark (thank you kind stranger): https://web.dev/serial/ */

let data = {
    moisture: [],
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
        bufferSize: 20
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
                // data.moisture.push(parseInt(reading.moisture));
                // data.times.push(((new Date()).toLocaleString()));
                addData(myChart, (new Date()).toLocaleString(), parseInt(reading.moisture));

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

let addData = (chart, label, data) => {
    chart.data.labels.push(label);
    chart.data.datasets.forEach((dataset) => {
        dataset.data.push(data);
    });
    chart.update();
}

const chartData = {
    labels: data.times,
    datasets: [{
        label: 'Soil moisture',
        backgroundColor: 'rgb(150, 193, 23)',
        borderColor: 'rgb(150, 193, 23)',
        data: data.moisture,
    }]
}

const config = {
    type: 'line',
    data: chartData,
    options: {
        animation: {
            duration: 0
        },
        scales: {
            xAxis: {
                // type: 'time',
            },
            yAxis: {
                max: 100
            }
        }
    }
};

const myChart = new Chart(
    document.getElementById('myChart'),
    config
);