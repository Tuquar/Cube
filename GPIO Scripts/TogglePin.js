var gpio = require('rpi-gpio');
var pin;
var state;

gpio.setup(pin, gpio.DIR_OUT, readInput);

function readInput() {
	 gpio.read(pin, function(err, value) {
        console.log('The value of ' + pin ' is ' + value);
		state = value;
    });
}

function togglePin() {
	gpio.write(pin, !state, function(err){
		if (err) throw err;
		console.log("Written to Pin");
	});
};

gpio.destroy(function() {
	console.log('Closed pins, now exit');
});