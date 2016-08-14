var gpio = require("rpi-gpio");
var pin;
var delay = 100;
var max = 40;
var count = 0;

function test(array[]){
	if (count >= max){
		 gpio.destroy(function() {
            console.log("Test Complete");
        });
        return;
	}
	setTimeout(function(){
		for (var i = 0; array.length <= i; i++){
			pin = array[i];
			gpio.setup(pin, gpio.DIR_OUT, write);
			gpio.write(pin, true, function(err){
				if (err) throw err;
				console.log(pin + " ON");
			});
		}
		count += 1;
	}, delay);
	
	
}