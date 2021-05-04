#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*Bluetooth*/
#include <stdio.h>
#include <SoftwareSerial.h>
#define rxPin 10
#define txPin 11
#define baudrate 9600
#define periode 20

//OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

SoftwareSerial mySerial(rxPin ,txPin); //definition du software serial 

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/*Signal de sortie*/
#define Tension_entree A0 //entrée analogique après etre passé dans R_sensor et AOP//

byte adc;
int res;
float tension;
unsigned long temps_ref;


#define SERIAL_DEBUG

volatile unsigned int encoder0Pos = 0;
unsigned long myTime;
float Vcc = 5.0;
float Rsensor = 0.0;
float R1 = 100000.0;
float R2 = 10000.0;
float R3 = 100000.0;
float R5 = 10000.0;
float count = 0.0;





void setup() {
  //Bluetooth
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  myTime = millis();

  mySerial.begin(baudrate);
  Serial.begin(baudrate);

//OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  initialisation();

}

void(* reset) (void) = 0;

void initialisation(){
  delay(2000);
  display.clearDisplay();
  display.println("Init., pls wait.");
  display.display(); 
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();
}

void affichage(){
    byte Vadc = map(analogRead(Tension_entree),0,1023,0,255);
    float Vv= Vadc*5.0/255.0;
    display.clearDisplay();
    display.setCursor(0, 10);
    display.print("Tension : ");
    display.print(Vv);
    display.println(" V");
    display.println("");
    display.print("Res : ");
    display.print(Rsensor);
    display.println(" Ohm");
    display.println("");
    display.display();
}



void loop() {
  /*lecteur U - Bluetooth*/
  if(abs(millis()- myTime)>=periode) {
  byte Vadc = map(analogRead(Tension_entree),0,1023,0,255); //map prend tension_entree qui est codée en bit de 0 à 1023 puis on lui demande de nous la coder entre 0 et 255
  mySerial.write(Vadc);
  #ifdef SERIAL_DEBUG 
    Serial.println("Vadc =");
    Serial.println(Vadc);
    Serial.print("Vadc_en_Volt =");
    float Vv= Vadc*5.0/255.0;
    Serial.println(Vv);
    Rsensor = ((1+R3/R2)*R1*(Vcc/Vv))-R1-R5;
    Serial.print("resistance mesuree est :");
    Serial.print(Rsensor);  
  #endif 
  myTime=0;

//ecran OLED
    affichage(); 
  }
  //Tension_entree=Tension_entree*5.0/1024;
  //double resistance=101.0*100000.0*
  
}
