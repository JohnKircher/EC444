# Code Readme

Lines 18-24 setup the pulsewidth's for driving and steering which are very important for this skill and for the driving the car. The ones for steering can be found on the servo datasheet from the class site. Additionally the values for the driving pulsewidths were also calculated from the class site. 

Lines 78-88 is the calibrateESC code from the class site and is needed to drive the car. These lines setup a high, low, neutral, and reset for the car. 

Lines 93-122 is the drive control task. Using three for loops we call the 'mcpwm_set_duty_in_us' to speed the car to drive backwards, then sit neutral, and then forwards. 

Fianlly, Lines 127-151 is the steering task. This task continuosoly turns the wheels the right, center, left, center using angle vlues that we calcualted for our servo.


Also
- Please provide your name and date in any code submitted
- Indicate attributrion for any code you have adopted from elsewhere
