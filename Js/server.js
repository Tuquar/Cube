var express = require("express");
var server = express();
var path = require("path");
var bodyParser = require('body-parser');
//var flash = require("./gpiocycle");

//Pin list:
// 7, 11, 12, 13, 15, 16, 18, 22, 29, 31, 32, 33, 35, 36, 37, 38, 40

var pinArr = [15, 16, 18, 29, 31, 32, 33, 35, 36, 37, 38, 40]



// parse application/x-www-form-urlencoded
server.use(bodyParser.urlencoded({ extended: false }))

// parse application/json
server.use(bodyParser.json())


server.use(express.static(__dirname + "/public"));

server.post("/flash", function (req, res) {
	console.log("Post received");
//	console.log(req.body.on);
	//flash.toggle();
	res.redirect(302,"/index.html");	
});

var port = 1586;
server.listen(port, function(){
	console.log("Listening on port: " + port);
});