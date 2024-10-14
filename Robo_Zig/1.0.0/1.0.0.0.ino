
#include <Ultrasonic.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define pinMot1A  13
#define pinMot1B 12
#define pinMot2A  14
#define pinMot2B  27


Ultrasonic ultrassom (21,19);

long distancia;



void setup() {
  

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);

  pinMode(pinMot1A , OUTPUT);
  pinMode(pinMot1B , OUTPUT);
  pinMode(pinMot2A , OUTPUT);
  pinMode(pinMot2B , OUTPUT);
  
display.clearDisplay();
}

void loop() {


const int velocidade = 200;
distancia = ultrassom.Ranging (CM);

  Serial.print(distancia);
  Serial.println("CM");
  delay(100);

display.println ("Zig");
display.println (distancia + "CM" );



   if (distancia >= 10 ) {
     
     frente;
      delay(100);

     esquerda;
     delay (100); 
      
    }


    
  if (distancia <= 5) {
    
    para;
    delay(100);
    
    voltar;
    delay(100);

    direita;
    delay (100);
    
  } 
  
  
}



void para (void) {
  analogWrite ( pinMot1A, 0);
  analogWrite ( pinMot1B, 0);
  analogWrite ( pinMot2A, 0); 
  analogWrite ( pinMot2B, 0);

}

void frente (void) {

 analogWrite ( pinMot1A, 200);
  analogWrite ( pinMot1B, 0);
  analogWrite ( pinMot2A, 200); 
  analogWrite ( pinMot2B, 0);

}

void esquerda (void) {
 analogWrite ( pinMot1A, 150);
  analogWrite ( pinMot1B, 0);
  analogWrite ( pinMot2A, 0); 
  analogWrite ( pinMot2B, 100);
}


void direita (void) {
 analogWrite ( pinMot1A, 0);
  analogWrite ( pinMot1B, 150);
  analogWrite ( pinMot2A, 100); 
  analogWrite ( pinMot2B, 0);
}

void voltar (void) {
   analogWrite ( pinMot1A, 0);
  analogWrite ( pinMot1B, 200);
  analogWrite ( pinMot2A, 0); 
  analogWrite ( pinMot2B, 200);
}
