### plant control
#### a (house)plant control system 🌱
##### semester project for the Microprocessor Systems laboratory

this repository is a project built on a STM32 Nucleo F767ZI board. it is a prototype of an automated houseplant pot. it allows for monitoring the soil moisture and the ambient brightness, and also for PID control of a lamp (I'm using an IKEA JANSJÖ lamp, which looks really cool. plants don't actually really care for that kind of light, but it looks cool nonetheless).

there are two ways of setting the brightness setpoint: through the serial port or using the rotary encoder. with the serial port, you can just send a 4-digit (zero padded) string with the value (in lux) *or* use [the web app I made](https://tusindfryd.github.io/plant-control/). it's deployed using GitHub pages and uses the [JavaScript Web Serial API](https://developer.mozilla.org/en-US/docs/Web/API/Web_Serial_API) and [Chart.js](https://www.chartjs.org). it allows for reading the measurements and setting the setpoint. the serial communication is a tiny bit buggy and sometimes requires pressing the reset button on the board or reconnecting, but overall *works*. because it is a web app, it would be really simple to add wireless features in the future: if the board ever runs an HTTP server for example, adding a fetch request would be fairly easy.

with the rotary encoder you just turn the knob and the value increments or decrements depending on the direction. 

there is a tiny OLED screen in the prototype too, which displays the measurements, the setpoint, and a simple menu that allows for turning the lamp on or off.

![alt text](/photos.png)
