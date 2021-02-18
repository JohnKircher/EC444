# Code Readme

For this skill, we primarily used the http, express, and socket.io modules to handle the web server and passing of data between frontend and backend. On line 18 of CanvasJS.js, we begin parsing the provided CSV for relevant stock data. Navigating through the CSV, we search for the Amazon, Facebook, Google, and Microsoft data fields, and populate their closing prices in arrays of the same name. Then, on line 54 we set up the chartSettings object for use with the CanvasJS.chart method, passing the chartSettings object as a parameter to the method function. Next, on line 105 we set up our default Express route to load the canvasJS.html file. On line 112, we open a socket connection using the socket.io module, sending the chartSettings object through this socket connection. Lastly, we initialize the http server on line 119, running on port 8080.

Finally, we copy all of the code from CanvasJS.js into CanvasJS2.js, and simply modify the chartSettings object on line 54 to display the data in the form of a line graph instead of a bar graph.

Also
- Please provide your name and date in any code submitted
- Indicate attributrion for any code you have adopted from elsewhere
