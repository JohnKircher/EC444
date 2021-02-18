#  Skill 30

Author: John Kircher

Date: 2020-11-19
-----

## Summary

In this skill, we calibrated the crawler using the calibrateESC code from the class site which allows us to drive the car. Using the esp32 we determined the pulsewidths for driving and steering and based on those values. 

We used 2 task functions to cycle the crawler through driving and steering. The steering task turns the wheels right, center, left, center. Additionally, the dirving task drives the car backwards, neutral, and then forwards. \

Explanation and video evidence can be seen at the link below. 

## Sketches and Photos

Link to video: https://drive.google.com/file/d/1mmigCZd0mPi3SxaVNK65OT1-8heDYlMi/view?usp=sharing

## Modules, Tools, Source Used Including Attribution

MCPWM Control: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/mcpwm.html

ESC Setup: http://whizzer.bu.edu/briefs/design-patterns/dp-esc

## Supporting Artifacts


-----
