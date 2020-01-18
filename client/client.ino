#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define ip "http://192.168.X.X"
#define pin 4 // D2

const char* ssid = "SSID";
const char* password = "PASSWORD";

void setup () {
  pinMode(pin, INPUT_PULLUP);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }
}

void loop() {
  if (!digitalRead(pin)) {
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(ip);
      int httpCode = http.GET();
      http.end();
      delay(5000);
    }
  }
  delay(100);
}
