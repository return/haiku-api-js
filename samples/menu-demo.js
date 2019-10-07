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

let menubar = haiku.BMenuBar(win.Bounds(), "menubar")

win.AddChild(menubar)



// Menus (Soon to be abstracted.)

let mainmenu = haiku.BMenu("File")

let menu = haiku.BMenuItem('FirstMenu', null)

let second = haiku.BMenuItem('SecondMenu', null)

let d = haiku.BMenuItem("ThirdMenu", null)


mainmenu.AddItem(menu)

mainmenu.AddItem(second)

mainmenu.AddItem(d)

let menubaritem = haiku.BMenu("Edit")

let menuz = haiku.BMenuItem('FirstMenu', null)

let menug = haiku.BMenuItem('SecondMenu', null)

let menus = haiku.BMenuItem('ThirdMenu', null)

menubaritem.AddItem(menuz)

menubaritem.AddItem(menug)

menubaritem.AddSeparatorItem()

menubaritem.AddItem(menus)


let item = haiku.BMenuItem(mainmenu)

let secondItem = haiku.BMenuItem(menubaritem)

menubar.AddItem(item)

menubar.AddItem(secondItem)


// Show the window.
win.Show()

// Start the App.
app.run()