#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#define RE 8
#define DE 7

const byte SpW[] = {0x01 , 0x03 , 0x00 , 0x00 , 0x00 , 0x01 , 0x84 , 0x0A};

byte values[20];
SoftwareSerial mod(2, 3);

void setup() {
  Serial.begin(9600);
  mod.begin(9600);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
}


void loop() {
  float val1 = 0 ;
  Calculate();
  val1 = (values[4] * 0.1);
  //Serial.print("ความเร็วลม: ");
 // Serial.print(val1);
 // Serial.println(" m/s");
  // Create a JSON object
  DynamicJsonDocument doc(1024);
  //doc["speed"] = "172";
  doc["speed"] = val1;

  // Convert the JSON object to a string
  String jsonString;
  serializeJson(doc, jsonString);

  // Print the JSON string to the serial monitor
  Serial.println(jsonString);

  delay(2000);
}

byte Calculate() {
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  if (mod.write(SpW, sizeof(SpW)) == 8) {
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 11; i++) {
      //Serial.print(mod.read(),HEX);
      values[i] = mod.read();
      //Serial.print(values[i], HEX);
      //Serial.print(" ");
    }
    Serial.println();
  }
  return values[6];
}
