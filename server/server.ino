#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "note.h"

#define pin 4     // D2

const char* ssid        = "SSID";
const char* password    = "PASSWORD";

int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };

int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

ESP8266WebServer server(80);

void handleQuery() {
  char rsp[255];
  sprintf(rsp, "Din D0n");
  server.send(200, "text/plain", rsp);
  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(pin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(pin);
  }
}

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }
  server.on("/", HTTP_GET, handleQuery);
  server.begin();
}

void loop() {
  server.handleClient();
}
