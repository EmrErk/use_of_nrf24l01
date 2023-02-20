
#include<SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define buton 7
int mesaj[1];
int x = 0; 
RF24 verici(9,8);   // CE CSN

const int kanal = 111;

void setup() {
  Serial.begin(9600);
  verici.begin();
  verici.openWritingPipe(kanal);

}

void loop() {
  x = digitalRead(buton);

  if(x == HIGH){

    mesaj[0] = 1;
    verici.write(&mesaj, sizeof(mesaj));
  }
  Serial.println(x);
}