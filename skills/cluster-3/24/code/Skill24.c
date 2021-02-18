//John Kircher 10/19/2020

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_attr.h"

#include "driver/mcpwm.h"
#include "soc/mcpwm_reg.h"
#include "soc/mcpwm_struct.h"


#define SERVO_MIN_PULSEWIDTH 0 //Minimum pulse width in microsecond
#define SERVO_MAX_PULSEWIDTH 1000 //Maximum pulse width in microsecond
#define MAX_INTENSITY 100 //Maximum angle in degree upto which servo can rotate

static void mcpwm_example_gpio_initialize()
{
    printf("initializing mcpwm servo control gpio......\n");
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, 13);    //Set GPIO 18 as PWM0A, to which servo is connected
}

static uint32_t servo_per_degree_init(uint32_t degree_of_rotation)
{
    uint32_t cal_pulsewidth = 0;
    cal_pulsewidth = (SERVO_MIN_PULSEWIDTH + (((SERVO_MAX_PULSEWIDTH - SERVO_MIN_PULSEWIDTH) * (degree_of_rotation)) / (MAX_INTENSITY)));
    return cal_pulsewidth;
}

void mcpwm_example_led(void *arg)
{
    uint32_t angle;
    mcpwm_example_gpio_initialize(); //initialize GPIO

    //2. initial mcpwm configuration
    printf("Configuring Initial Parameters of mcpwm......\n");
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 1000;
    pwm_config.cmpr_a = 0;    //duty cycle of PWMxA = 0
    pwm_config.cmpr_b = 0;    //duty cycle of PWMxb = 0
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);    //Configure PWM0A & PWM0B with above settings
    while (1) {
        for (int count = 0; count < MAX_INTENSITY; count+=10) {
            printf("Intensity percentage: %d\n", count);
            angle = servo_per_degree_init(count);
            printf("Pulse Width: %dus\n", angle);
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle);
            vTaskDelay(250);     //Add delay, since it takes time for servo to rotate, generally 100ms/60degree rotation at 5V
        }
        for (int count = MAX_INTENSITY-10; count >= 0; count-=10) {
            printf("Intensity percentage: %d\n", count);
            angle = servo_per_degree_init(count);
            printf("Pulse Width: %dus\n", angle);
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle);
            vTaskDelay(250);     //Add delay, since it takes time for servo to rotate, generally 100ms/60degree rotation at 5V
        }
    }
}

void app_main()
{
    xTaskCreate(mcpwm_example_led, "mcpwm_example_led", 4096, NULL, 5, NULL);
}
