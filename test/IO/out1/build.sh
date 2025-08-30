#!/bin/bash

# ESP32P4 GPIO47输出高电平项目编译脚本
echo "设置ESP-IDF环境..."
source /Users/dlgg/esp/v5.4.2/esp-idf/export.sh

echo "设置目标芯片为ESP32P4..."
idf.py set-target esp32p4

echo "开始编译项目..."
idf.py build

echo "编译完成！"
echo "烧录命令: idf.py -p PORT flash monitor"
echo "请将PORT替换为实际的串口号，例如: /dev/cu.usbserial-0001"

