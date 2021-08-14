#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//RF MODULE
#define PIN_CSE 10
#define PIN_MOSI 11
#define PIN_CE 9
#define PIN_SCK 13
#define PIN_MISO 12
// MOTOR DRIVERS
#define PIN_MD_ENL 6
#define PIN_MD_LF 7
#define PIN_MD_LB 5
#define PIN_MD_ENR 3
#define PIN_MD_RF 4
#define PIN_MD_RB 2

int MD_SPEED_LEFT = 0;
int MD_SPEED_RIGHT = 0;

RF24 radio(PIN_CE, PIN_CSE);
uint8_t address[][6] = {"1Node", "2Node"};

void setup() {
    Serial.begin(9600);
    pinMode(PIN_MD_ENL, OUTPUT);
    pinMode(PIN_MD_LF, OUTPUT);
    pinMode(PIN_MD_LB, OUTPUT);
    pinMode(PIN_MD_ENR, OUTPUT);
    pinMode(PIN_MD_RF, OUTPUT);
    pinMode(PIN_MD_RB, OUTPUT);

    radio.begin();
    radio.openReadingPipe(1, address[0]);   //Setting the address at which we will receive the data
    //radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
    radio.startListening();
}//setup

int rfData[2];
void listenRF(){
    if(radio.available()){
        radio.read(&rfData, sizeof(rfData));
        Serial.println(rfData[0]);
        Serial.println(rfData[1]);
    }
} //listenRF

void loop() {
    listenRF();
    delay(250);
/*
  if(MD_SPEED_LEFT > 500){
      analogWrite(PIN_MD_ENL, map(MD_SPEED_LEFT, 510, 1023, 0, 255));
  }else{
      analogWrite(PIN_MD_ENL, map(MD_SPEED_LEFT, 490, 0, 0, 255));
  }

  if(MD_SPEED_RIGHT > 500){
      analogWrite(PIN_MD_ENR, map(MD_SPEED_RIGHT, 510, 1023, 0, 255));
  }else{
      analogWrite(PIN_MD_ENR, map(MD_SPEED_RIGHT, 490, 0, 0, 255));
  }
  */
}//loop
