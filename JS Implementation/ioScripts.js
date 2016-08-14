var gpio = require("rpi-gpio");


gpio.setup(7, gpio.DIR_OUT, write);

function write(){
	gpio.write(7, true, function(err) {
		if (err) throw err;
		console.log("Written to pin");
	});
}

gpio.setup(7, gpio.DIR_IN, readInput);
function readInput(){
	gpio.read(7, function(err,value) {
		console.log("The value is " + value);
	});
}