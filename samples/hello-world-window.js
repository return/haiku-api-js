const haiku = require('../build/Release/nbind');

// Create a BApplication Instance
app = haiku.BeApplication("application/x-vnd.dw-MyApp")

// Create a BWindow

win = haiku.BeWindow("Node.JS Test Window", 100, 100, 500, 400, 1, 0x00080000)

// Constants with enums are not binded yet, so use proxy classes and fixed constants
// for now.

// Constant 1 is window_type enum with constant B_TITLED_WINDOW
// Constant '0x00080000' is B_ASYNCHRONOUS_CONTROLS

// Show the window.
win.Show()

// Start the App.
app.run()