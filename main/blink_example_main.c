#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"


#define LED_PIN 2
TaskHandle_t ledhandle = NULL;
void blink_task(void *pvParams) {
    ESP_LOGI("BLINK_TASK", "Blink task started");
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED_PIN, 1); 
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN, 0); 
        vTaskDelay(500 / portTICK_PERIOD_MS); 
    }
}
void app_main() {
    ESP_LOGI("APP_MAIN", "Application started");
    xTaskCreate(blink_task, "blink_task", 2048, NULL, 5, &ledhandle);
}

 