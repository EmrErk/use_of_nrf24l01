#include<SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define led 2
int mesaj[1] ;

RF24 alici(9,8); // CE CSN

const int kanal = 111;

void setup() {
  Serial.begin(9600);
  alici.begin();
  alici.openReadingPipe(1,kanal);
  alici.startListening();
  pinMode(led, OUTPUT);

}

void loop() {
 
  if (alici.available()){
    bool done = false;
    while(!done){
      
      done = alici.read(&mesaj, sizeof(mesaj));
      
      if(mesaj[0] == 1){
        delay (10);
        digitalWrite(led,HIGH);
      }
      delay(10);
    }
   
  }
  Serial.print("mesaj : ");
  Serial.println(mesaj[0]);
}