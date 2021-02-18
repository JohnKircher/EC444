#  Skill 28

Author: John Kircher

Date: 2020-11-13
-----

## Summary
This program completes all the tasks required in skill 28. The fob is able to communicate to two FOBs and elect a leader with the lowest ID number using a bully algorithm. (Note: The quest adds on and generalizes this code so that many FOBs can run the program simultaneously but this code only tests for two FOBs.) The program can also elect a new leader if the the current leader is "broken" or disconnected. It will also restart a leader election when a new FOB is added into the election even if the election has already started. During the election, the LED will be green. If a FOB realizes it is not a leader, its LED will turn red and if at the end of the election, the last FOB with a green led will turn blue for leader. 

## Sketches and Photos
### Election State:
![electionState](https://user-images.githubusercontent.com/50682462/99134926-e4bcfe00-25ed-11eb-9267-7d47165962ae.jpg)

### Leader Found:
![leaderFound](https://user-images.githubusercontent.com/50682462/99134927-e5ee2b00-25ed-11eb-941a-c80531ac4fce.jpg)

### State Diagram:
![28EEEF9F-35B7-418D-A642-5F61379089DB_1_105_c](https://user-images.githubusercontent.com/50682462/99136132-4e8ad700-25f1-11eb-912b-eb06dab74280.jpeg)

Link to Video: https://drive.google.com/file/d/11nClcgYWpj0cwL-My4nOi-wQYwVZT67v/view?usp=sharing


## Modules, Tools, Source Used Including Attribution


## Supporting Artifacts


-----
