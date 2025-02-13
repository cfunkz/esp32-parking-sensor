# esp32-parking-sensor

Basic parking sensor functionality for ESP32.

Things needed:

1. x1 Piezo Buzzer
2. x1 RGB Led
3. x1 HC-SR04 Ultrasonic
4. ESP32
5. Arduino IDE

| HC-SR04 Pin  | ESP32 Pin |
| ------------- | ------------- |
| -  | GND  |
| VCC  | 3.3v or 5v  |
| TRIG  | GPIO12  |
| ECHO  | GPIO13  |

| RGB Led  | ESP32 Pin |
| ------------- | ------------- |
| -  | GND  |
|  RED | GPIO4  |
| GREEN  | GPIO2  |
| BLUE  | GPIO15  |

| Piezo Buzzer  | ESP32 Pin |
| ------------- | ------------- |
| -  | GND  |
| VCC | 3.3v or 5v  |
| Signal | GPIO17  |
