# OLED Voltage Readout

This code is used to display voltage measurements on an OLED display using an analog input and a voltage divider circuit with resistors R1 and R2. 

## Hardware requirements

- Arduino board

- OLED display compatible with the Adafruit_SSD1306 library

- Voltage divider circuit with R1 and R2 resistors

## Libraries used

- SPI.h

- Adafruit_SSD1306.h

## Pin assignments

- OLED_RESET is connected to pin 4

- The analog input pin is assigned to the variable 'analogInput'

## Functionality

- The code uses the analogRead() function to read the voltage at the analog input

- The voltage is then calculated using the voltage divider formula and the values of R1 and R2

- The calculated voltage is then displayed on the OLED display

- The OLED display is updated every 1000 milliseconds

## Customization

- The resistance values of R1 and R2 can be modified to match the specific voltage divider circuit being used

- The OLED display's I2C address can be modified as per requirement

