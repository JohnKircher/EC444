#  Skill 23

Author: John Kircher

Date: 2020-10-19
-----

## Summary

In this skill I was required to fill out the functions writeRegister, ReadRegister, and Read16. As well as the roll and pitch calculations. To do this, I utilized the ADXL343 datasheet so I knew which registers I was using to store data. Additionally, I had to understand how to communicate with a master and slave. So writing I2C code allowed me to use the i2c_master functions. This simplified my code greatly. Furthermore, I followed the steps to reassemble 2 bytes into a 16 bit signed word. Lastly, I used conversions to make static acceleration values into correct roll and pitch. Sample video of my program working can be found below.

## Sketches and Photos

Link to video: https://youtu.be/I4gaaAObTdo

## Modules, Tools, Source Used Including Attribution

Attributions:

Tilt_Sensing: https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing

ADXL343 Sample Code: https://github.com/BU-EC444/code-examples/tree/master/i2c-accel

ADXL343 Datasheet: https://cdn-learn.adafruit.com/assets/assets/000/070/556/original/adxl343.pdf?1549287964

## Supporting Artifacts


-----
