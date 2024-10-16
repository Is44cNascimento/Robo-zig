
#include <Ultrasonic.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
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
  
  
  while (true){
    display.println (distancia + "CM" );
    display.clearDisplay();
  }



  while (distancia<= 5){
     trezentos_e_sessenta;
     delay (1000);

  }
  


   if (distancia >= 8 ) {
     
     frente;
      delay(0);

     esquerda;
     delay (100); 
      
    } 


    if (distancia >= 50 ){
        esquerda;
        delay (300);
    }

    if (distancia >= 30){
      direita;
      delay(300);
    }

    
  if (distancia <= 8) {
    
    para;
    delay(100);
    
    voltar;
    delay(450);

    direita;
    delay (500);
    
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


void  trezentos_e_sessenta(void){
   
    analogWrite ( pinMot1B, 200);
    analogWrite ( pinMot2A, 200); 
    delay (500);

    analogWrite ( pinMot2B, 200);
     analogWrite ( pinMot1A, 200);

     delay(500);
  }
