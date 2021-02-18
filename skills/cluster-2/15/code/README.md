# Code Readme

In this code I utilized the IR Rangefinder model (GP2Y0A02YK0F) Datasheet for the IR rangefinder. I utilized the distance to voltage graphs which allowed me to average slope and the y intercept to convert voltage to centimeters. Using the algorithms referred to from the datasheet I was able to estimate the new conversion algorithm from distance = 12343.85 * (voltage reading)^-1.15 to distance = 146060 * (voltage reading)^-1.19. Additionally I included Math.h which allowed me to use the pow method as follows: 146060 * (pow(voltage,-1.19)); This is done on line 89 in the program. 

Also
- Please provide your name and date in any code submitted
- Indicate attributrion for any code you have adopted from elsewhere
