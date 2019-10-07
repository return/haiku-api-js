const haiku = require('../build/Release/nbind');

// Create a BApplication Instance
let app = haiku.BeApplication("application/x-vnd.dw-MyApp")
// Create an BAlert
let alert = haiku.BAlert("Hello World Alert", "Three buttons here, \nPick One:", "Yes", "No", "Cancel")
// Run!
alert.Go()
