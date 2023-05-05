/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PEROTO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO GARELERIEL MABSILLA DIEGUEZ y PABLO DAVID HERNANDEZ AJIATAZ
CARNETS: 2022380 y 2022472
PRACTICA 4 DISEÑO DE FIRMWARE
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C crystal(0x27,20,4);




#define buzzer 10
#define L0 2
#define L1 3
#define L2 4
#define L3 5
#define L4 6
#define L5 7
#define L6 8
#define L7 9
#define L8 A0
#define L9 A1
#define CDO 523
#define FFA 698

byte monitotranquilo[8] = {
  B01110,
  B01010,
  B01110,
  B00100,
  B01110,
  B10101,
  B01110,
  B01010
};

byte monitocorriendo[8] = {
  B01110,
  B01010,
  B01110,
  B10100,
  B11110,
  B00101,
  B01100,
  B10011
};

byte monitoalejese[8] = {
  B11100,
  B10100,
  B11100,
  B01010,
  B11110,
  B11000,
  B11110,
  B11010
};









void  PENTRADA(void); //Definimos una funcion para salidas y entradas de los pines.
void  PSALIDA(void);


int TRIG = 11; //Definimos El Pin 2 para Triger.
int ECHO = 12; //Definimos El Pin 3 para Echo.
int DURATION; //Definimos una variable de duracion.
int DISTANCE; //Definimos una variable DISTANCE.


void setup() {
  crystal.init();
  crystal.backlight();
  crystal.createChar(0, monitotranquilo);
  crystal.createChar(1, monitocorriendo);
  crystal.createChar(2, monitoalejese);
  pinMode (buzzer, OUTPUT);
  pinMode (TRIG, OUTPUT);
  pinMode (ECHO, INPUT);

  PENTRADA(); //Hacemos el llamado a las funciones de Configuracion.
  PSALIDA();  

 
}

void loop() {
  SENSCONFIG();
  
 if(DISTANCE>45 && DISTANCE >=45){
  crystal.setCursor(0,0);
  crystal.print("FUERA DE ALCANCE"); 
  delay(50);
  crystal.setCursor(0,1); 
  crystal.write(byte(0));
  crystal.setCursor(1,1);
  crystal.print("               ");   
  BLINK();  
     
 }
 if(DISTANCE>30 && DISTANCE <=45){
  crystal.setCursor(0,0);
  crystal.print("PERSONA VINIENDO ");
  delay(50);
  crystal.setCursor(0,1); 
  crystal.write(byte(0));
  crystal.setCursor(15,1);
  crystal.write(byte(1));
  crystal.setCursor(4,1);
  crystal.print(" ");
  crystal.setCursor(9,1);
  crystal.print(" ");
  LEJOS();
 }
 if(DISTANCE>15 && DISTANCE <=30){
  crystal.setCursor(0,0);
  crystal.print("ESPACIO PRIVADO ");
  delay(50);
  crystal.setCursor(0,1); 
  crystal.write(byte(0));
  crystal.setCursor(9,1);
  crystal.write(byte(1));
  crystal.setCursor(15,1);
  crystal.print(" ");
  crystal.setCursor(15,1);
  crystal.print(" ");
  NUMERO1();


  LEJOS();  
     
 }
 if(DISTANCE>5 && DISTANCE <=15){
  crystal.setCursor(0,0);
  crystal.print("ALTO, MUY CERCA");
   crystal.setCursor(0,1); 
  crystal.write(byte(2));
  delay(50);
  crystal.setCursor(2,1);
  crystal.write(byte(1));
  crystal.setCursor(9,1);
  crystal.print(" ");
  crystal.setCursor(15,1);
  crystal.print(" ");
  LEJOS();
  NUMERO2();


 }
}

 void PENTRADA(void){
  pinMode(ECHO, INPUT);
  
 }
 void PSALIDA(void)
{

     pinMode(TRIG, OUTPUT);  
     pinMode(2, OUTPUT);
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT);
     pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT);   
     pinMode(A0, OUTPUT);   
     pinMode(A1, OUTPUT);   
            
                     
}
 void SENSCONFIG(void){ //Configuracion del Sensor.
   digitalWrite(TRIG, LOW); //Apaga el Pin de Trig.
  delay(50); 
  digitalWrite(TRIG, HIGH);//Enciende el Pin Trig. 
  delay(50);
  digitalWrite(TRIG, LOW);//Apaga el Pin Trig.
   DURATION = pulseIn(ECHO, HIGH); /* Lee la informacion del pin eco,
  y la guarda en la variable duracion */
  
  DISTANCE= DURATION*0.034/2;  //Convierte la distancia en centimetros . 
  Serial.print(String(DISTANCE)); // La variable String guarda tipo de datos en cadenas
  Serial.println(" cm");
  delay(400);
}
void BLINK(void){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, HIGH);
  digitalWrite(L6, HIGH);
  digitalWrite(L7, HIGH);
  digitalWrite(L8, HIGH);
  digitalWrite(L9, HIGH);

  delay(500);

  digitalWrite(L0, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);  

  
}
void LEJOS(void) {
  if(DISTANCE>40 && DISTANCE<=45){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
}


if(DISTANCE>35 && DISTANCE<=40){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
}
if(DISTANCE>30 && DISTANCE<=35){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
}
if(DISTANCE>25 && DISTANCE<=30){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
}
if(DISTANCE>20 && DISTANCE<=25){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
}
if(DISTANCE>15 && DISTANCE<=20){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, HIGH);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
}
if(DISTANCE>10 && DISTANCE<=15){
  digitalWrite(L0, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, HIGH);
  digitalWrite(L6, HIGH);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);
  digitalWrite(L9, LOW);
}
if(DISTANCE>5 && DISTANCE<=10){
BLINK();
}
}
void NUMERO1 (void) {
    tone(10, CDO, 2500);
    delay(2500);
    noTone(buzzer);
}

void NUMERO2 (void) {
    tone(10, FFA, 5000);
    delay(5000);
    noTone(buzzer);
  
}












            
     
