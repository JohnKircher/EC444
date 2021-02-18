# Code Readme

This program has 4 main parts. The first 3 are the read and write register functions, the last is the roll and pitch calculation. First, the writeRegister function starting on line
109 and ending on 123, uses a similar structure to the getDeviceID. First, I start cmd, then I write the slave address, send the register pointer, send the data, and then stop the cmd. Following a similar pattern for readRegister, From line 126 to 146, I start cmd, then write the slave address, send the register pointer, start cmd again so I can send the slave address of the bit I want to read, I then place the data from that register into the bus, and finally stop cmd. The next function Read16 from line 149 to 162 combines 2 bytes and reads into a 16bit word. To do this I ORed the LSB with the MSB shifted to the left by 8. Then I use bitwise operators to do a bitshift operation.

Finally, the roll and pitch conversion function on line 200 to 204 is adopted from the sample code on https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing

Also
- Please provide your name and date in any code submitted
- Indicate attributrion for any code you have adopted from elsewhere
