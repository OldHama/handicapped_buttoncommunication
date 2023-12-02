#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); 
const byte address[6] = "00011"; 
void setup() {
  pinMode(4, INPUT);
  radio.begin();
  radio.openWritingPipe(address); 
  radio.setPALevel(RF24_PA_MIN); 
  radio.stopListening();  
}
void loop() {
  int sensorValue = digitalRead(4);
  char text[2]; 
  itoa(sensorValue, text, 10); 

  radio.write(&text, sizeof(text)); 
  delay(100);
}
