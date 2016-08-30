var gpio = require('rpi-gpio');
 
var pin   = 16;
var delay = 50;
var count = 0;
var max   = 30;

var on;
gpio.destroy(function() {
        gpio.setup(pin, gpio.DIR_OUT, console.log.bind(console, 'Pin Ready!'));
});


exports.toggle = function() {
	console.log("toggle");
	if(on) {
		gpio.write(pin, 0);
	} else {
		gpio.write(pin, 1);
	}
	on = !on;
};
 