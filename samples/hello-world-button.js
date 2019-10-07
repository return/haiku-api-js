const haiku = require('../build/Release/nbind');

// Create a BApplication Instance
let app = haiku.BeApplication("application/x-vnd.dw-MyApp")

// Create a BWindow

let win = haiku.BeWindow("Node.js Test Window", 100, 100, 500, 400, 4, 0x00080000)

// Constants with enums are not binded yet, so use proxy classes and fixed constants
// for now.

// Constant 1 is window_type enum with constant B_TITLED_WINDOW
// Constant '0x00080000' is B_ASYNCHRONOUS_CONTROLS


// Counter Example
let counter = 0


//construct<BRect, const char *, const char *, BMessage*>();


// Create a Button with a BMessage 
let Button = haiku.BButton(win.Bounds(), "resetlabel", "Test",  haiku.BeMessage('bcd'))
let dr = app.AppMessenger()

Button.SetTarget(dr)


// Button.ResizeToPreferred()

// Create a String View 
let stringview = haiku.BStringView(haiku.BRect(145,-200,300,150), "myLabel", "Button not clicked yet.")


// Add the string into the windows's view
win.AddChild(Button)
//let.AddChild(stringview)



// Use the messaging system to detect the button clicks. 
app.onMessageReceived((msg)=>{

    counter += 1
    
    console.log(counter)

    let text = `Text Clicked ${counter}`

    Button.SetLabel(text)

})



// Show the window.
win.Show()

// Start the App.
app.run()
