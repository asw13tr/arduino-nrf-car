#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
uint8_t address[][6] = {"1Node", "2Node"};


int rfX = 500;
int rfY = 500;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  radio.begin();  // Başlat
  radio.openWritingPipe(address[0]); // Adrese bağlan
  //radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); 

}//setup


int rfData[2];
void loop() {
  rfData[0] = analogRead(A0);
  rfData[1] = analogRead(A1);
  
  boolean status = radio.write(&rfData, sizeof(rfData));
  Serial.println(status);
  Serial.println(rfData[0]);
  Serial.println(rfData[1]);
  delay(250);
  
}//loop
