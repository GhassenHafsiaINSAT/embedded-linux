#!/bin/bash

sudo insmode /opt/csf/labs/aht10/driver/aht10.ko

if [ -e /dev/aht10 ]; then
    echo "AHT10 sensor is connected."
else
    echo "AHT10 sensor is not connected."
    exit 1
fi

sensor_data=$(cat /dev/aht10)

mosquitto_pub -t "sensor/data" -m "$sensor_data"

echo "$sensor_data" > sensor_data.txt

echo "Data published and updated successfully."
