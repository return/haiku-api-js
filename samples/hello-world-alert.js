const haiku = require('../build/Release/nbind');

// Create a BApplication Instance
let app = haiku.BeApplication("application/x-vnd.dw-MyApp")
// Create an BAlert
let alert = haiku.BAlert("Hello World Alert", "This is an alert called from Node.JS", "Yay!")
// Run!
alert.Go()
