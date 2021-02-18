//John Kircher 9/19/2020
//Attributions from Instructables Binary counting with LEDs
//Attributions from StackOverflow, how to binary count in c
//Atrribution links can be found in the report.

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/

void app_main(void)
{
	int led[4] = {0,0,0,0};
	int carry[3] = {0,0,0};
	int BLINK_GPIO[4] = {13,12,27,33};
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_pad_select_gpio(BLINK_GPIO[0]);
    gpio_set_direction(BLINK_GPIO[0], GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(BLINK_GPIO[1]);
    gpio_set_direction(BLINK_GPIO[1], GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(BLINK_GPIO[2]);
    gpio_set_direction(BLINK_GPIO[2], GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(BLINK_GPIO[3]);
    gpio_set_direction(BLINK_GPIO[3], GPIO_MODE_OUTPUT);
    while(1) {
     carry[0] = led[0]&1;
     led[0] = (!led[0])&1;
     carry[1] = led[1]&carry[0];
     led[1] = ((!carry[0])&led[1])|(carry[0]&(!led[1]));
     carry[2] = led[2]&carry[1];
     led[2] = (led[2]&(!carry[1]))|((!led[2])&carry[1]);
     led[3] = ((!carry[2])&led[3])|(carry[2]&(!led[3]));
        gpio_set_level(BLINK_GPIO[0], !led[0]);
        gpio_set_level(BLINK_GPIO[1], !led[1]);
        gpio_set_level(BLINK_GPIO[2], !led[2]);
        gpio_set_level(BLINK_GPIO[3], !led[3]);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
