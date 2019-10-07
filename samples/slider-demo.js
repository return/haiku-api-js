
const haiku = require('../build/Release/nbind');

const B_FOLLOW_ALL =  ((1 << 12) | (2 << 8) | (3 << 4) | 4)

// Create a BApplication Instance
app = haiku.BeApplication("application/x-vnd.dw-MyApp")

// Create a BWindow

win = haiku.BeWindow("Node.JS Test Window", 100, 100, 500, 200, 1, 0x00080000)

// Constant 1 is window_type enum with constant B_TITLED_WINDOW
// Constant '0x00080000' is B_ASYNCHRONOUS_CONTROLS

let rect = haiku.BRect(0, 0, win.Bounds().Width(), win.Bounds().Height())

// Create a slider
var slider = haiku.BSlider(rect, "bSlider", "Node JS Slider", haiku.BeMessage(1923), 0, 100)

slider.SetLimitLabels("Less","More")

let dr = app.AppMessenger()

slider.SetTarget(dr)

win.AddChild(slider)

// Use the messaging system to detect the button clicks. 
app.onMessageReceived((msg)=>{
    switch(msg){
        case 1923:
            console.log(`Value of slider is ${slider.Position()}`)
            break;
        default:
            break;
    }
})


// Show the window.
win.Show()

// Start the App.
app.run()