# Code Readme

I chose to implement this code following the conditional state machine example in the Whizzer FSM brief. Following this design pattern, I defined two sets of enumerated types, one being the set of all possible states, and another being the set of all possible events. Next, I define the starting state to be the enumerated type "MOLE_DOWN_STATE". Inside the while loop, I have two main conditionals (if and else if) for my two states, "MOLE_DOWN_STATE" and "MOLE_UP_STATE". Inside of these two main conditionals are identical sets of sub-conditionals containing event handlers for every possible event that could occur in these states.

