//John Kircher 9/19/2020
//Attribution from Quora: Int to Hex function *link can be found in attributions in report

#include <stdio.h>
#include <string.h>
#include "driver/uart.h"
#include "esp_vfs_dev.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include <stdlib.h>
#include <ctype.h>

#define BLINK_GPIO CONFIG_BLINK_GPIO
#define EX_UART_NUM UART_NUM_0
#define ECHO_TEST_TXD (UART_PIN_NO_CHANGE)
#define ECHO_TEST_RXD (UART_PIN_NO_CHANGE)
#define ECHO_TEST_RTS (UART_PIN_NO_CHANGE)
#define ECHO_TEST_CTS (UART_PIN_NO_CHANGE)
#define BUF_SIZE (1024)
void app_main()
{
    /* Install UART driver for interrupt-driven reads and writes */
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_0,
                                        256, 0, 0, NULL, 0));

    /* Tell VFS to use UART driver */
    esp_vfs_dev_uart_use_driver(UART_NUM_0);

    gpio_pad_select_gpio(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    /* Configure parameters of the UART driver,
     * communication pins and install the driver */
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    uart_param_config(EX_UART_NUM, &uart_config);
    uart_set_pin(EX_UART_NUM, ECHO_TEST_TXD, ECHO_TEST_RXD, ECHO_TEST_RTS, ECHO_TEST_CTS);
    uart_driver_install(EX_UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);

    // Configure a temporary buffer for the incoming data
    uint8_t *data = (uint8_t *)malloc(BUF_SIZE);

    // char str[20];
    // char num;
    bool Flag = false;
    char hexNum[100];

    printf("toggle mode\n");
    int currentMode = 0;
    while (1)
    {

        if (currentMode == 0)
        {
            int len = uart_read_bytes(EX_UART_NUM, data, BUF_SIZE, 20 / portTICK_RATE_MS);
            if (len > 0)
            {
                printf("Read: %c \n", *data);
                if (*data == 's')
                {
                    currentMode = 1;
                    printf("echo mode");
                }
                else if (*data == 't')
                {
                    if (Flag == false)
                    {
                        Flag = true;
                        gpio_set_level(BLINK_GPIO, 1);
                    }
                    else if (Flag == true)
                    {
                        Flag = false;
                        gpio_set_level(BLINK_GPIO, 0);
                    }
                }
            }
        }
        else if (currentMode == 1)
        {
            printf("\nEcho:");
            char buf[5];
            gets(buf);
            if (buf[0] != '\0')
            {
                if (buf[0] == 's' && buf[1] == '\0')
                {
                    currentMode = 2;
                    printf("s\nhex mode");
                }
                else
                {
                    printf("%s", buf);
                }
            }
        }
        else if (currentMode == 2)
        {
            printf("\nEnter an integer:");
            char bufNum[5];
            gets(bufNum);

            long decimal, remainder;

            int i, j = 0;

            if (bufNum[0] != '\0')
            {
                if (bufNum[0] == 's')
                {
                    currentMode = 0;
                    printf("s\ntoggle mode");
                }
                else if (isdigit(bufNum[0]))
                {
                    decimal = atoi(bufNum);
                    printf("%ld \n", decimal);

                    while (decimal != 0)
                    {
                        remainder = decimal % 16; //step 1
                        if (remainder < 10)
                        {
                            hexNum[j++] = 48 + remainder; //step 2
                        }
                        else
                        {
                            hexNum[j++] = 55 + remainder; //step 3
                        }

                        decimal = decimal / 16; //step 4
                    }

                    printf("Hex:");

                    for (i = j - 1; i >= 0; i--)
                        printf("%c", hexNum[i]);
                }
            }
        }
    }
}
