# Arduino Serial Bridge to Tasmota 

This example is for Arduino communication with Wind Speed via RS485 then send data ubti tasmota via Software Serial (SSerialReceived)

1. Activate Serial Receiver via Tasmota Console ```SerialSend [withspace]```

- Example Receive : {"Speed":25.6}
 
2. Set Serial Delimiter to 128 (to make JSON output as 1 line) https://tasmota.github.io/docs/Commands/#serial-bridge

3. Console : ```baudrate 9600```
   
4. Set GPIO RX in case of "HW Serial" for "Serial Tx" from Arduino or use another GPIO for SW Serial as "SerBr Tx"         
   
   
TODO:
Try to activate Serial Receiver from void setup() but not working yet. So I use Tasmota Console to activate Serial Receiver with ```SerialSend ``` first.

