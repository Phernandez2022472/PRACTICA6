#include <LiquidCrystal_I2C.h>
#define L1 2
#define L2 3
#define L3 4
#define L4 5
#define L5 6
#define L6 7
#define L7 8
#define L8 A0
#define L9 10
#define L10 A1 
#define buzzer 9


int TRIG = 11; //Definimos El Pin 2 para Triger.
int ECHO = 12; //Definimos El Pin 3 para Echo.
int DURATION; //Definimos una variable de duracion.
int DISTANCE; //Definimos una variable distancia.
int CONT=0; //Definimos una variable para contar.
LiquidCrystal_I2C lcd_1(0x27,16,2);

void setup()
{
 lcd_1.init();
 lcd_1.backlight();
 pinMode(ECHO, INPUT);
 entrada();
 
 
}

void loop()
{
  SENSCONFIG();
  int A;
  A=44-DISTANCE;
  lcd_1.setCursor(0, 0);
  lcd_1.print(A);
  lcd_1.setCursor(2, 0);
  lcd_1.print("              ");
  
  if(DISTANCE>35){
  lcd_1.setCursor(1, 0);
  lcd_1.print("              ");
  }
 
 if(DISTANCE>=44){//0%
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
  digitalWrite(L5,LOW);
  digitalWrite(L6,LOW);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
  BUZZERCON();
  
 }
 else if(DISTANCE>=40 && DISTANCE<=44){//10%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
  digitalWrite(L5,LOW);
  digitalWrite(L6,LOW);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }
 else if(DISTANCE>=36 && DISTANCE<=40){//20%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
  digitalWrite(L5,LOW);
  digitalWrite(L6,LOW);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }
 else if(DISTANCE>=32 && DISTANCE<=36){//30%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,LOW);
  digitalWrite(L5,LOW);
  digitalWrite(L6,LOW);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }
 else if(DISTANCE>=28 && DISTANCE<=32){//40%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,LOW);
  digitalWrite(L6,LOW);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }
 else if(DISTANCE>=24 && DISTANCE<=28){//50%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,LOW);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }
 else if(DISTANCE>=20 && DISTANCE<=24){//60%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }
 else if(DISTANCE>=16 && DISTANCE<=20){//70%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L7,HIGH);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }
 else if(DISTANCE>=12 && DISTANCE<=16){//80%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L7,HIGH);
  digitalWrite(L8,HIGH);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
 }

  else if(DISTANCE>=8 && DISTANCE<=12){//90%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L7,HIGH);
  digitalWrite(L8,HIGH);
  digitalWrite(L9,HIGH);
  digitalWrite(L10,LOW);
 }
else if(DISTANCE>=4 && DISTANCE<=8){//100%
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L7,HIGH);
  digitalWrite(L8,HIGH);
  digitalWrite(L9,HIGH);
  digitalWrite(L10,HIGH);
 }
else if(DISTANCE>=1 && DISTANCE<=4){//+100%
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
  digitalWrite(L5,LOW);
  digitalWrite(L6,LOW);
  digitalWrite(L7,LOW);
  digitalWrite(L8,LOW);
  digitalWrite(L9,LOW);
  digitalWrite(L10,LOW);
  BUZZERCON();
 }
}
void entrada(){
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(L5,OUTPUT);
  pinMode(L6,OUTPUT);
  pinMode(L7,OUTPUT);
  pinMode(L8,OUTPUT);
  pinMode(L9,OUTPUT);
  pinMode(L10,OUTPUT);
  pinMode(TRIG, OUTPUT);    
  
}
void SENSCONFIG(void){ //Configuracion del Sensor.
   digitalWrite(TRIG, LOW); //Apaga el Pin de Trig.
  delay(60); 
  digitalWrite(TRIG, HIGH);//Enciende el Pin Trig. 
  delay(60);
  digitalWrite(TRIG, LOW);//Apaga el Pin Trig.
   DURATION = pulseIn(ECHO, HIGH); /* Lee la informacion del pin eco,
  y la guarda en la variable duracion */
  
  DISTANCE= DURATION*0.034/2;  //Convierte la distancia en centimetros . 
  Serial.print(String(DISTANCE)); // La variable String guarda tipo de datos en cadenas
  Serial.println(" cm");
  delay(400);
}
void BUZZERCON(void){ //Configuracion del buzzer.
            tone(buzzer, 500, 1500);   
           delay(750);
           noTone(buzzer);
}
