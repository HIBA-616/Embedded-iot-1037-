Assignment 1 � Embedded IoT Systems

Name: Hiba Fatima
Reg No: 23-NTU-CS-1037
Course: Embedded IoT Systems
Instructor: Sir Nasir Mehmood
Date: 26-Oct-2025

Overview

This contains two ESP32-based projects demonstrating fundamental concepts in embedded systems, including I/O control, state management, timing, and OLED interfacing. All code was developed and tested using the Wokwi online simulator.

?? Hardware & Software Environment

Development Platform: Arduino Framework (Wokwi/PlatformIO)

Simulation: Wokwi Simulator

Task 1 � Device Control using ESP32 (LEDs, Buttons, Buzzer & OLED)

Description:
The ESP32 controls three LEDs, two buttons, and a buzzer with real-time visual messages displayed on an OLED.
Buttons toggle the LEDs and buzzer states, and the OLED updates accordingly.

Components Used:

ESP32 DevKitC V4

OLED 128x64 (I2C)

LEDs � 3

Buzzer � 1

Push Buttons � 2

420? Resistors � 3

Jumper Wires

Component	Pin Name	GPIO No.
LED 1	D25	GPIO 25
LED 2	D27	GPIO 27
LED 3	D26	GPIO 26
Button 1	D32	GPIO 32
Button 2	D33	GPIO 33
Buzzer	D14	N/A
OLED SDA	SDA	GPIO 21
OLED SCL	SCL	GPIO 22

Wokwi Project Link:
https://wokwi.com/projects/445873016530129921

loom vedio link:
https://www.loom.com/share/f5a0f906af794c0ab559880db1026b48

Screenshots:
project running:
"C:\Users\Dell\Pictures\Screenshots\on.png"
"C:\Users\Dell\Pictures\Screenshots\Screenshot (111).png"
"C:\Users\Dell\Pictures\Screenshots\Screenshot (112).png"
"C:\Users\Dell\Pictures\Screenshots\Screenshot (113).png"

code screenshot:
"C:\Users\Dell\Pictures\Screenshots\Screenshot (104).png"

diagram .json:
"C:\Users\Dell\Pictures\Screenshots\Screenshot (108).png"

Task 2 � Button Press Duration Detection (Short / Long Press with OLED)

Description:
This task detects short and long button presses using the ESP32.
A short press toggles the LED, while a long press activates the buzzer. The OLED displays corresponding feedback.

Components Used:

ESP32 DevKitC V4

OLED 128x64 (I2C)

Push Button � 1

LED � 1

Buzzer � 1

Resistor � 1

Pin Map:

Component	Pin Name	GPIO No.
LED 1	D25	GPIO 25
LED 2	D27	GPIO 27
LED 3	D26	GPIO 26
Button 1	D32	GPIO 32
Button 2	D33	GPIO 33
Buzzer	Not Used	N/A
OLED SDA	SDA	GPIO 21
OLED SCL	SCL	GPIO 22

Wokwi Project Link:
?? View Simulation on Wokwi
https://wokwi.com/projects/445873593457762305

loom vedio link:
https://www.loom.com/share/28a3c60e49ba4aefb3ebd774c85f3a5d

Screenshots:
project screenshot:
"C:\Users\Dell\Pictures\Screenshots\Screenshot (106).png"

code screenshot:
"C:\Users\Dell\Pictures\Screenshots\Screenshot (103).png"

diagram .json:
"C:\Users\Dell\Pictures\Screenshots\Screenshot (108).png"

