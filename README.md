# Tuya-gas-alarm
Gas alarm based on Tuya intelligence
This project is developed using Tuya SDK, which enables you to quickly develop branded apps connecting and controlling smart scenarios of many devices.For more information, please check Tuya Developer Website.
# Project introduction
This is a gas alarm device based on WR3S of graffiti module. The gas detection part adopts MQ-5 module for detection, and it is matched with 0.96 inch OLED display screen to display relevant data.Because the MQ-5 module only leads out the relevant MCU pins, other modules of the MQ series can also be replaced according to their own needs, and compatible with most 4-pin modules.
# Introduction to the project using the tutorial
Use lighter to ignite and blow out the simulated gas, detect the gas, the buzzer will send out an alarm, and display on the graffiti APP.As there is only one button and one LED light, this button is used to switch SMART mode and AP mode, and the LED light displays fast flash and slow flash respectively.
# Corollary equipment
MQ-5 combustible gas sensor;Tuya WB3S WiFi&BLE dual protocol module;0.96 inch OLED display;MCU board based on STC8A chip, with a button, an LED light and a buzzer, using Micro USB interface.
# Finally
(At present, the display part is not available, and the corresponding gas value is not understood when measuring the analog quantity pin of the MQ series module, and the graffiti module also has some data transceiver problems, which will be improved in the future.)
