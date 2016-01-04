var mongoose = require('mongoose');

// Create the Schema
var contactSchema = new mongoose.Schema({
        _id: String,
        stocks: [{
                product: String, // Coca-Cola
                price: Number // $4.50
        }]
});

// create the model
module.exports = mongoose.model('users', contactSchema);