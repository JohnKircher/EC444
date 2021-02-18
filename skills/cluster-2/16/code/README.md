# Code Readme

In this skill I read data from the ESP32 through the serial port, which I implemented in the Quest2Skill16.js file. The code for this file was relatively simple, On line 2, I created a SerialPort object called "port" and bind it to COM3. Then I set the baudrate to match the UART driver, 115200. Next, on line 6, I used the .on() method on port to begin reading data coming through serial port COM3. The console then shows the temperature data in plain text, as can be seen in my video.

Also
- Please provide your name and date in any code submitted
- Indicate attributrion for any code you have adopted from elsewhere
