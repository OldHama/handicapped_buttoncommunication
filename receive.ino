 #include <SPI.h> 

#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); 
const byte address[6] = "00011";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(4, OUTPUT);
}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if (text[0] == '1'){
      for (int i = 0; i< 3; i++){
        digitalWrite(4, HIGH);
        delay(300);
        digitalWrite(4, LOW);
        delay(300);
      }3
    }
  }
}
