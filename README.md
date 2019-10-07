# Node.js Bindings to the Haiku API 

This is a JavaScript and TypeScript wrapper around the Haiku API for the Haiku Operating System, a BeOS inspired OS targeting desktop computing. This allows developers to easily create apps using Node.js just as if they were written in C++.

# Building 

You need to be running a Haiku machine in order to build this binding with a recent version of Node.js (at least 12.4.0) to run this binding. You also need TypeScript to build the TypeScript version.

Run these commands:

`git clone https://github.com/return/haiku-api-js`

`cd haiku-api.js`

`npm install`

`npm run -- build`

Once built, you should now see a 'nbind.node' library in the build/Release/ folder.


## TypeScript Support

The bindings can also be used from TypeScript.

# Examples
After building it, you can directly run the examples using node.

To run either of the examples below run:

`node src/hello-world-alert.js`

Here are a few:

* `app-demo.js` - Prints the Application signature of the running app in the 'application/x-vnd.dw-MyApp' format.

* `hello-world-alert.js` - Displays an alert showing 'Hello World'.

* `hello-world-alert-buttons.js` - Displays an alert showing 'Hello World' but with more buttons.

* `hello-world-button.js` - Displays a button with the text 'Hello World'.

* `hello-world-window.js` - Shows a Haiku Window with a custom title.

* `listview-demo.js` - A Haiku GUI with a ListView inside of a Haiku Window.

* `menu-demo.js` - Examples of using a menubar in a Haiku GUI app.

* `notification-demo.js` - Displays a Haiku Notification with a message.

* `scrollview-demo.js` - Displays a ScrollView in the GUI.

* `slider-demo.js` - Shows an example of using a slider.


## Todo
[] - Support the Haiku Layout Engine

[] - Support enum types (via TypeScript)

[] - Clean up the bindings to allow more sophisticated usage.

[] - Create convenience wrappers around boilerplate code.

# License

MIT
