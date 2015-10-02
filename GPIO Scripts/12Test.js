var gpio = require('rpi-gpio');
//var pinArr[7, 11, 12, 13      , 15, 16, 18, 22, 29, 31, 32, 33, 36, 37, 38, 40];
//,[29, 0],[31, 0],[32, 0],[33, 0],[36, 0],[37, 0],[38, 0],[40, 0]
var pinArr = [[15, 0],[16, 0],[18, 0],[22, 0]];
var shutdown = false;
var delay = 1000;
var max = 5;

for (var count = 0; count <= max; count++){
	for (var pinCount = 0; pinCount < pinArr.length; pinCount++ ) {

		if (shutdown){
			pinOFF(pinArr[pinCount][0]);
		}
		if (pinArr[pinCount][1] === 1) {
console.log("turning off");
			setTimeout(function(){
				pinOFF(pinArr[pinCount][0]);
			}, delay);
		}
		if (pinArr[pinCount][1] === 0) {
console.log("turning on");
			setTimeout(function(){
				pinON(pinArr[pinCount][0]);			
			}, delay);
		} else {
			console.log("Failed to change pin: " + pinArr[pinCount][0]);
		}
		
	}
}

gpio.destroy(function() {
    console.log('Closed pins, now exit');
});

function pinOFF(pin){
console.log("off");
	gpio.setup(pin, gpio.DIR_OUT);
	
	gpio.write(pin, false, function(err) {
        if (err) throw err;
        console.log('Pin ' + pin + ' off');
    });
}

function pinON(pin){
	console.log("on");
	gpio.setup(pin, gpio.DIR_OUT);
	
	gpio.write(pin, true, function(err) {
        if (err) throw err;
        console.log('Pin ' + pin + ' on');
    });
	
}