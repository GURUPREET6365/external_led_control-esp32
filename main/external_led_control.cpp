#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GPIO_OUTPUT_IO_18 GPIO_NUM_18

extern "C" void app_main()
{
    gpio_reset_pin(GPIO_OUTPUT_IO_18);
    gpio_set_direction(GPIO_OUTPUT_IO_18, GPIO_MODE_OUTPUT);
    while (true){
        gpio_set_level(GPIO_OUTPUT_IO_18, 1); // Turn LED ON
        vTaskDelay(pdMS_TO_TICKS(100));     // Keep it ON for 2 seconds 
        
        gpio_set_level(GPIO_OUTPUT_IO_18, 0); // Turn LED OFF
        vTaskDelay(pdMS_TO_TICKS(100)); 

    }

}