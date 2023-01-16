# OLED Voltage and Frequency Readout

This code is used to display voltage and frequency measurements on an OLED display. The voltage measurement is done by using an analog input and a voltage divider circuit with resistors R1 and R2, while the frequency measurement is done using a frequency counting library.

## Hardware requirements

- Arduino board

- OLED display compatible with the Adafruit_SSD1306 library

- Voltage divider circuit with R1 and R2 resistors

- Frequency measuring circuit (to be connected to the analog input pin)

## Libraries used

- Wire.h

- SPI.h

- Adafruit_SSD1306.h

- FreqCount.h

## Pin assignments

- OLED_RESET is connected to pin 4

- The analog input pin is assigned to the variable 'analogInput'

## Functionality

- The code uses the analogRead() function to read the voltage at the analog input

- The voltage is then calculated using the voltage divider formula and the values of R1 and R2

- The calculated voltage is then displayed on the OLED display

- The frequency is measured using the FreqCount library, the period and frequency are then calculated and displayed on the OLED display

- The OLED display is updated every 1000 milliseconds

## Customization

- The resistance values of R1 and R2 can be modified to match the specific voltage divider circuit being used

- The OLED display's I2C address can be modified as per requirement

- The sampling time for frequency counting can be adjusted in the FreqCount.begin() function.

## Explanation

This code is a combination of two codes, one for measuring voltage and the other for measuring frequency. The voltage measurement is done by using an analog input and a voltage divider circuit with resistors R1 and R2, voltage divider circuit is used to convert high voltage to lower voltage for arduino to read it. The resistance values of R1 and R2 can be modified to match the specific voltage divider circuit being used.

The frequency measurement is done using a frequency counting library, which counts the number of pulses in a set time period, and the period and frequency are then calculated and displayed on the OLED display. The OLED display is updated every 1000 milliseconds and the sampling time for frequency counting can be adjusted in the FreqCount.begin() function.

The OLED display is used to show the measured values of voltage and frequency, OLED display is a simple and low power display which can be easily integrated to any project.

