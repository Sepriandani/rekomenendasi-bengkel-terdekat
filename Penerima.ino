#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "sim808"
#define WIFI_PASSWORD "informatika" 

String cekData;
String latitude, longitude;

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

}

void loop() {
  terimaData();
   if(cekData == "Ada"){
      tampilSerial();
    }else{
      Serial.print(".");
    }
}
