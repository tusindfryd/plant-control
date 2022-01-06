/* bookmark (thank you kind stranger): https://web.dev/serial/ */

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
            console.log(value)
        }
        if (done) {
            // allow the serial port to be closed later
            reader.releaseLock();
            break;
        }
    }
}