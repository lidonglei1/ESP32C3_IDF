#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define GPIO_OUTPUT_IO_13   GPIO_NUM_13
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_13)

static const char *TAG = "GPIO47_OUTPUT";

void app_main(void)
{
    ESP_LOGI(TAG, "开始初始化GPIO 47");
    
    // 配置GPIO
    gpio_config_t io_conf = {};
    // 设置为输出模式
    io_conf.mode = GPIO_MODE_OUTPUT;
    // 设置GPIO引脚掩码
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    // 禁用下拉
    io_conf.pull_down_en = 0;
    // 禁用上拉
    io_conf.pull_up_en = 0;
    // 配置GPIO
    gpio_config(&io_conf);
    
    ESP_LOGI(TAG, "GPIO 47初始化完成");
    
    // 设置GPIO 47为高电平
    gpio_set_level(GPIO_OUTPUT_IO_13, 1);
    ESP_LOGI(TAG, "GPIO 47已设置为高电平");
    
    // 保持程序运行
    while(1) {
        ESP_LOGI(TAG, "GPIO 47保持高电平状态");
        vTaskDelay(5000 / portTICK_PERIOD_MS); // 延迟5秒
    }
}

