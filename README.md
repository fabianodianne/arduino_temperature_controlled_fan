# Arduino Fan Control with Temperature Display

This Arduino sketch controls the operation of a fan based on temperature readings from a DHT11 sensor. The temperature readings are displayed on a 16x2 LCD screen. When the temperature exceeds a certain threshold (30°C in this case), the fan is turned on; otherwise, it remains off.

## Components Used
- Arduino board (e.g., Arduino Uno)
- DHT11 temperature and humidity sensor
- Relay module
- 16x2 LCD with I2C interface
- 12V adapter
- 12V fan

## Libraries Required
- `SoftwareSerial.h`: Standard Arduino library for software serial communication.
- `Wire.h`: Standard Arduino library for I2C communication.
- `LiquidCrystal_I2C.h`: Library for interfacing with I2C LCD displays.
- `DHT.h`: Library for interfacing with DHT temperature and humidity sensors.

## Wiring Instructions
1. Connect the DHT11 sensor to the Arduino:
   - DHT11 VCC -> Arduino 5V
   - DHT11 GND -> Arduino GND
   - DHT11 DATA -> Arduino digital pin 7 (or as defined by `DHTPIN`)

2. Connect the relay module to the Arduino:
   - Relay VCC -> Arduino 5V
   - Relay GND -> Arduino GND
   - Relay IN -> Arduino digital pin 8 (or as defined by `RELAY_PIN`)

3. Connect the LCD to the Arduino:
   - LCD SDA -> Arduino A4
   - LCD SCL -> Arduino A5
   - LCD VCC -> Arduino 5V
   - LCD GND -> Arduino GND

4. Connect the fan and adapter to the relay module:
   - Adapter red wire -> Relay COM
   - Adapter black wire -> Fan black wire -> Relay NC
   - Fan red wire -> Relay NO

## Usage
1. Upload the sketch to your Arduino board.
2. Open the serial monitor to view temperature readings and fan status.
3. The fan will turn on automatically when the temperature exceeds 30°C and turn off when it falls below 30°C.

Ensure all connections are correct and secure before powering on your Arduino board. Make sure to handle electrical components safely to prevent damage or injury.

For troubleshooting or customization, refer to the comments in the sketch code.
