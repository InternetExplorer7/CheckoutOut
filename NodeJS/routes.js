var user = require('./models/user');

	exports.add = function (req, res) { // Add (1) item to Database - DONE.
		var product = Object.keys(req.body).toString().split(','); // ['Coca-Cola', '4.99']
		return user.findByIdAndUpdate(
			'Kaveh', {
					$push: {
						"stocks": {
							product: product[0], // 'Coca-Cola'
							price: parseFloat(product[1]) // 4.99
						}
					}
			}, { // Options
				safe: true,
				upsert: true,
				new: true
			}).then(function (response){
				console.log('Response: ' + JSON.stringify(response));
				if(response){ // Error saving item to DB.
					console.log('Sucesfully saved: ' + JSON.stringify(response));
					res.send(true);
				}
			});
	}

	exports.get = function (req, res) { // Get all from database.
		console.log("Req body: " + JSON.stringify(req.body));
		return user.findById("Kaveh").then(function (response){
			res.send(response.stocks);
		})
	}