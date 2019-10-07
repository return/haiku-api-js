const haiku = require('../build/Release/nbind');

// Create a BApplication Instance
let app = haiku.BeApplication("application/x-vnd.dw-MyApp")

// Create a BWindow

let win = haiku.BeWindow("Node.JS Window", 100, 100, 500, 400, 4, 0x00080000)

// Constant 1 is window_type enum with constant B_TITLED_WINDOW
// Constant '0x00080000' == B_ASYNCHRONOUS_CONTROLS

// Create a Button with a BMessage 
let Button = haiku.BButton(win.Bounds(), "btn1", "Send Test Notification",  
	haiku.BeMessage(1290))

let app_msgr = app.AppMessenger()

Button.SetTarget(app_msgr)

// Add the string into the windows's view
win.AddChild(Button)

// Create the Notification 
var note = haiku.BNotification(haiku.BeMessage(1290))
note.SetTitle(haiku.BString("Test Notification"))
note.SetContent(haiku.BString("This is a Notification Sent from JavaScript!"))

// Use the messaging system to detect the button clicks. 
app.onMessageReceived((msg)=>{
    switch(msg){
        case 1290:
            note.Send(-1)
            break;
        default:
            break;
    }
})

// Show the window.
win.Show()

// Start the App.
app.run()

