/*
  FUNDACION KINAL
  CENTRO EDUCATIVO TECNICO LABORAL KINAL
  PEROTO EN ELECTRONICA
  QUINTO PERITO
  SECCION: A
  CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
  ALUMNOS:PABLO DAVID HERNANDEZ AJIATAZ
  CARNETS:2022472
  PRACTICA 6 
*/

#include <LiquidCrystal_I2C.h>//incluimos la libreria 
LiquidCrystal_I2C crystal(0x27, 16, 2);//colocamos la direccion I2C y sos columnas y filas
byte block[8] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000
};//creamos un bloque


void  PENTRADA(void); //Definimos una funcion para salidas y entradas de los pines.
void  PSALIDA(void);
int TRIG = 11; //Definimos El Pin 2 para Triger.
int ECHO = 12; //Definimos El Pin 3 para Echo.
int DURATION; //Definimos una variable de duracion.
int DISTANCE; //Definimos una variable DISTANCE.


void setup() {
  crystal.init();//iniciamos el lcd con el protocolo I2C
  crystal.backlight();
  crystal.createChar(0, block);
  PENTRADA();//funciones de entradas y salidas
  PSALIDA();
  

}
void loop() {
  dis();
  distancia();
}



/////////////////////FUNCIONES/////////////////////


void PENTRADA(void) {
  pinMode(ECHO, INPUT);
}


void PSALIDA(void)
{
  pinMode(TRIG, OUTPUT);
}



void dis() { //funcion con retorna para la lectura de distancia
  digitalWrite(TRIG, LOW); //Apaga el Pin de Trig.
  delay(50);
  digitalWrite(TRIG, HIGH);//Enciende el Pin Trig.
  delay(50);
  digitalWrite(TRIG, LOW);//Apaga el Pin Trig.
  DURATION = pulseIn(ECHO, HIGH);
  DISTANCE= DURATION * 0.034 / 2; //Convierte la distancia en centimetros .
  
}


void distancia(void) {

  if (DISTANCE > 20 && DISTANCE >= 30) {
    crystal.setCursor(7, 0);
    crystal.print("50");
    crystal.setCursor(0, 0);
    crystal.write(byte(0));
    crystal.setCursor(1, 0);
    crystal.write(byte(0));
    crystal.setCursor(2, 0);
    crystal.write(byte(0));
    crystal.setCursor(3, 0);
    crystal.print("    ");
    crystal.setCursor(15, 0);
    crystal.write(byte(0));
    crystal.setCursor(14, 0);
    crystal.write(byte(0));
    crystal.setCursor(13, 0);
    crystal.write(byte(0));
    crystal.setCursor(9, 0);
    crystal.print("    ");
    crystal.setCursor(6, 1);
    crystal.print("libre");

    crystal.setCursor(0, 1);
    crystal.print("      ");
    crystal.setCursor(11, 1);
    crystal.print("     ");
      
  }
  if (DISTANCE > 10 && DISTANCE <= 20) {
    crystal.setCursor(7, 0);
    crystal.print("30");
    crystal.setCursor(0, 0);
    crystal.write(byte(0));
    crystal.setCursor(1, 0);
    crystal.write(byte(0));
    crystal.setCursor(2, 0);
    crystal.write(byte(0));
    crystal.setCursor(3, 0);
    crystal.write(byte(0));
    crystal.setCursor(4, 0);
    crystal.write(byte(0));
    crystal.setCursor(5, 0);
    crystal.print("  ");
    crystal.setCursor(15, 0);
    crystal.write(byte(0));
    crystal.setCursor(14, 0);
    crystal.write(byte(0));
    crystal.setCursor(13, 0);
    crystal.write(byte(0));
    crystal.setCursor(12, 0);
    crystal.write(byte(0));
    crystal.setCursor(11, 0);
    crystal.write(byte(0));
    crystal.setCursor(9, 0);
    crystal.print("  ");
    crystal.setCursor(5, 1);
    crystal.print("CUIDADO");
    
    crystal.setCursor(0, 1);
    crystal.print("     ");
    crystal.setCursor(12, 1);
    crystal.print("    ");
  }
  if (DISTANCE > 1 && DISTANCE <= 10) {
    crystal.setCursor(7, 0);
    crystal.print("10");
    crystal.setCursor(0, 0);
    crystal.write(byte(0));
    crystal.setCursor(1, 0);
    crystal.write(byte(0));
    crystal.setCursor(2, 0);
    crystal.write(byte(0));
    crystal.setCursor(3, 0);
    crystal.write(byte(0));
    crystal.setCursor(4, 0);
    crystal.write(byte(0));
    crystal.setCursor(5, 0);
    crystal.write(byte(0));
    crystal.setCursor(6, 0);
    crystal.write(byte(0));

    crystal.setCursor(15, 0);
    crystal.write(byte(0));
    crystal.setCursor(14, 0);
    crystal.write(byte(0));
    crystal.setCursor(13, 0);
    crystal.write(byte(0));
    crystal.setCursor(12, 0);
    crystal.write(byte(0));
    crystal.setCursor(11, 0);
    crystal.write(byte(0));
    crystal.setCursor(10, 0);
    crystal.write(byte(0));
    crystal.setCursor(9, 0);
    crystal.write(byte(0));

    crystal.setCursor(6, 1);
    crystal.print("ALTO");

    crystal.setCursor(0, 1);
    crystal.print("      ");
    crystal.setCursor(10, 1);
    crystal.print("      ");
  }
}
