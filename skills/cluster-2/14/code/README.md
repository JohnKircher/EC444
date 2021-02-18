# Code Readme

In this code I utilized the MaxSonar Datasheet for the Ultrasonic sensor. I needed this because to convert voltage to engineering units I need the conversion equation to get volts per centimeter. So for standard XL-Sonar Sensors when using a 5V input the conversion is 5V / 1024 which is about
4.883mv per cm. So the range can be found by dividing 4.883 by the calculated voltage from the ADC program. This allowed me to print
out the distance in cm that the sensor was reading.

Also
- Please provide your name and date in any code submitted
- Indicate attributrion for any code you have adopted from elsewhere
