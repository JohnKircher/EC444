#  Skill 25

Author: John Kircher

Date: 2020-11-13
-----

## Summary
For this skill, we built two identical versions of the IR transmitter/receiver. Using the provided ir car beacon codebase, we were able to identify "myID" as the key variable that would need to be transmitted in order to tell the receiving board which LED to turn on. Every time the button is pressed, the "myID" variable is incremented within the range [0:3], looping back to 0. After discussing with Professor Little and getting his approval, I chose to implement this skill with just a single button, and constantly streaming the state of the "myID" variable over IR. As seen in the video below, this results in an almost immediate update of the receiving board's LEDs.

## Sketches and Photos
<img width="735" alt="image1 (1)" src="https://user-images.githubusercontent.com/50682462/99135254-72e5b400-25ef-11eb-9784-158385ec5e72.png">


![image2](https://user-images.githubusercontent.com/50682462/99135256-737e4a80-25ef-11eb-830f-9283e7dafd8c.jpeg)

Link to video: https://drive.google.com/file/d/1QfP5FV8mRffrts7YgRpvjD5S4NcV_R5G/view?usp=sharing

## Modules, Tools, Source Used Including Attribution
RTOS, uart, timer, code-examples codebase

## Supporting Artifacts


-----
