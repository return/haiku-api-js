const haiku = require('../build/Release/nbind');

const B_FOLLOW_ALL =  ((1 << 12) | (2 << 8) | (3 << 4) | 4)

// Create a BApplication Instance
app = haiku.BeApplication("application/x-vnd.dw-MyApp")

// Create a BWindow

win = haiku.BeWindow("Node.JS Test Window", 100, 100, 500, 400, 1, 0x00080000)

// Constants with enums are not binded yet, so use proxy classes and fixed constants
// for now.

// Constant 1 is window_type enum with constant B_TITLED_WINDOW
// Constant '0x00080000' is B_ASYNCHRONOUS_CONTROLS

let rect = haiku.BRect(15, 15, win.Bounds().Height(), 0)

let textView = haiku.BTextView(win.Bounds(), "txtView", rect.OffsetToCopy(0,20).InsetByCopy(10,10), 0)

let scrollView = haiku.BScrollView("scrollview", textView, B_FOLLOW_ALL, 0x20000000, false, true)

win.AddChild(scrollView)

textView.SetText("Hello World\n\n Type anything in this box.", null)

// Show the window.
win.Show()

// Start the App.
app.run()