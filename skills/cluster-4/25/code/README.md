# Code Readme

This code was adopted from the ir-car-beacon example since it had the framework for sending IR signals using FOBs. One specific thing that we changed in order to have the sample code work was updating the RXD variable to UART_SIGNAL_RXD_INV since the old version was depricated. After this, we removed the timer methods since we wanted to allow the user to control the LED without a timer. We changed the button task to increment the myID variable, which in turn changed the LED light. Then, once the user has chosen the correct LED value they would like to send, they can click the second button to transmit the color over IR. The receiving FOB will then set its own color to the incoming color.

Also
- Please provide your name and date in any code submitted
- Indicate attributrion for any code you have adopted from elsewhere