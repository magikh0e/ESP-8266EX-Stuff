// WeMos D1 Mini Pro-16 Wireless AP Scanner 
// By: magikh0e

#include "ESP8266WiFi.h"
WiFiClient client;

void setup() {
  Serial.begin(57600);
}

void loop() {
  SSID_scan();
  delay(10000);
}

void SSID_scan() {
  Serial.println("");
  Serial.println("wifi scan started");
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(") ");
      Serial.print(" [");
      Serial.print(WiFi.channel(i));
      Serial.print("] ");
      Serial.println((String) encryptionTypeStr(WiFi.encryptionType(i)));
      delay(10);
    }
  }
  Serial.println("scan complete");
  Serial.println("");
}

String encryptionTypeStr(uint8_t authmode) {
  switch (authmode) {
    case ENC_TYPE_NONE:
      return "NONE";
    case ENC_TYPE_WEP:
      return "WEP";
    case ENC_TYPE_TKIP:
      return "TKIP";
    case ENC_TYPE_CCMP:
      return "CCMP";
    case ENC_TYPE_AUTO:
      return "AUTO";
    default:
      return "?";;
  }
}