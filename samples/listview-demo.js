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

//let textView = haiku.BTextView(win.Bounds(), "txtView", rect.OffsetToCopy(0,20).InsetByCopy(10,10), 0)

var listview = haiku.BListView(win.Bounds(), "myListView")

let scrollView = haiku.BScrollView("scrollview", listview, B_FOLLOW_ALL, 0x20000000, false, true)


win.AddChild(scrollView)

listview.AddItem(haiku.BStringItem("Test 1"))
listview.AddItem(haiku.BStringItem("Test 2"))
listview.AddItem(haiku.BStringItem("Test 3"))
listview.AddItem(haiku.BStringItem("Test 4"))
listview.AddItem(haiku.BStringItem("Test 5"))
listview.AddItem(haiku.BStringItem("Test 6"))
listview.AddItem(haiku.BStringItem("Test 7"))
listview.AddItem(haiku.BStringItem("Test 8"))
listview.AddItem(haiku.BStringItem("Test 9"))
listview.AddItem(haiku.BStringItem("Test 10"))
listview.AddItem(haiku.BStringItem("Test 11"))
listview.AddItem(haiku.BStringItem("Test 12"))
listview.AddItem(haiku.BStringItem("Test 13"))
listview.AddItem(haiku.BStringItem("Test 14"))
//textView.SetText("HAIKU ROCKS\n\n", null)



// Show the window.
win.Show()

// Start the App.
app.run()