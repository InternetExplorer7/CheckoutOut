var express = require('express');

var app = express();

var Promise = require('bluebird');

var bodyParser = require("body-parser");

var mongoose = require('mongoose');

var cfenv = require('cfenv');
// get the app environment from Cloud Foundry
var appEnv = cfenv.getAppEnv();

var routes = require('./routes');

mongoose.connect("mongodb://localhost:27017/att");

// parse application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({ extended: false }))

// parse application/json
app.use(bodyParser.json())


app.post('/addItemToDB', routes.add);

app.get('/getItemsFromDB', routes.get);




app.listen(3000);