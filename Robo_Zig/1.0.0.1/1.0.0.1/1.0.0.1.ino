#include <Ultrasonic.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LARGURA_OLED 128
#define ALTURA_OLED 64

#define OLED_RESET -1
Adafruit_SSD1306 display(LARGURA_OLED, ALTURA_OLED, &Wire, OLED_RESET);

#define pinMot1A 13
#define pinMot1B 12
#define pinMot2A 14
#define pinMot2B 27

Ultrasonic ultrassom(5, 18);
long distancia;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(115200);

  pinMode(pinMot1A, OUTPUT);
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinMot2A, OUTPUT);
  pinMode(pinMot2B, OUTPUT);

  display.clearDisplay();
}

void loop() {
  const int velocidade = 200;
  distancia = ultrassom.Ranging(CM);

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" CM");

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Zig");
  display.print("Distancia: ");
  display.print(distancia);
  display.println(" CM");
  display.display();  

  delay(500);

 
  if (distancia <= 5) {
    giro();
    delay(1000);
  } else if (distancia >= 50) {
    esquerda();
    delay(300);
  } else if (distancia >= 30) {
    direita();
    delay(300);
  } else if (distancia >= 8) {
    frente();
    delay(100);
  } else {
    para();
    delay(100);
    voltar();
    delay(450);
    direita();
    delay(500);
  }
}

void para() {
  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot1B, LOW);
  digitalWrite(pinMot2A, LOW);
  digitalWrite(pinMot2B, LOW);
}

void frente() {
  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot1B, LOW);
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot2B, LOW);
}

void esquerda() {
  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot1B, LOW);
  digitalWrite(pinMot2A, LOW);
  digitalWrite(pinMot2B, HIGH);
}

void direita() {
  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot1B, HIGH);
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot2B, LOW);
}

void voltar() {
  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot1B, HIGH);
  digitalWrite(pinMot2A, LOW);
  digitalWrite(pinMot2B, HIGH);
}

void giro() {
  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot1B, HIGH);
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot2B, HIGH);
  delay(500);
}
