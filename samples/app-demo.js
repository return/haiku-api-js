const haiku = require('../build/Release/nbind');

// Create a BApplication Instance
let app = haiku.BeApplication("application/x-vnd.dw-MyApp")

console.log(`Application Signature: ${app.signature()}`) 

app.quit()
