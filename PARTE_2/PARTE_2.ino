#include <LiquidCrystal.h> //Incluimos la libreria Liquid Crystal.

#define PHIGH(pin)   digitalWrite(pin, HIGH)//Definimos una pequeña funcion, para abreviar el DigitalWrite HIGH.
#define PLOW(pin)   digitalWrite(pin, LOW)//Definimos una pequeña funcion, para abreviar el DigitalWrite LOW.
#define buzzer 9 //Definimos el pin del buzzer.
#define CDOM 1047 //Definimos el sonido del BUZZER.
LiquidCrystal LCD(7, 6, 5, 4, 3, 2); //Definimos los pines de la LCD.

byte TILIN1[8] = {
  B01110,
  B01010,
  B01110,
  B00100,
  B11111,
  B00100,
  B01110,
  B01010
};

byte TILIN2[8] = {
  B01110,
  B01110,
  B01110,
  B10100,
  B01110,
  B00101,
  B11010,
  B00010
};


void  PENTRADA(void); //Definimos una funcion para salidas y entradas de los pines.
void  PSALIDA(void); 

int TRIG = 11; //Definimos El Pin 2 para Triger.
int ECHO = 12; //Definimos El Pin 3 para Echo.
int DURATION; //Definimos una variable de duracion.
int DISTANCE; //Definimos una variable distancia.
int CONT=0; //Definimos una variable para contar.


void setup() {
  
  LCD.begin(16, 2); //Iniciamos la LCD.
  Serial.begin(9600); //Iniciamos la comunicacion Serial.
  LCD.createChar(0, TILIN1); //Definimos los char de las sprites.
  LCD.createChar(1, TILIN2);
  
PENTRADA(); //Hacemos el llamado a las funciones de Configuracion.
PSALIDA();  

}

void loop() {

SENSCONFIG(); //Llamamos la configuracion del Sensor.
if (CONT>=16) CONT=16; //Definimos que cuando el contador llegue a 16 o mas, valga 16 siempre, para que no suba infinitamente.
if (CONT>=16) BUZZERCON(); //Definimos que cuando el contador llegue a 16 o mas, inicie la configuracion del buzzer.

switch(CONT){ //Abrimos un switch case para almacenar los casos.
          
          case(0): //0
          LCD.setCursor(0,0);
          LCD.write("LUGAR VACIO");
          delay(500);
          LCD.clear(); 
          LCD.setCursor(0,1);
          LCD.write("PASE ADELANTE");      
            break;
          case(1): //1 
          LCD.clear();
          LCD.setCursor(0,0);
          LCD.write(byte(0));
          LCD.setCursor(0,1);         
          LCD.write("PERSONAS:1");
         break;
           case(2): //2
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:2");
         break;
          case(3): //3
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:3");
         break;
          case(4): //4
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:4");          
         break;                
          case(5): //5 
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:5");  
         break;       
          case(6): //6
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:6");           
         break;        
          case(7): //7
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:7");          
         break;
          case(8): //8  
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:8");            
         break;
           case(9): //9  
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:9");                 
         break; 
           case(10): //10  
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:10");
         break;   
           case(11): //11  
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:11");
         break;     
           case(12): //12 
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:12");
         break;     
           case(13): //13
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:13");
         break;     
           case(14): //14  
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:14");
         break;     
           case(15): //15  
          LCD.setCursor(0,1);  
          LCD.write("PERSONAS:15");
         break;     
           case(16): //16
          LCD.clear();
          LCD.setCursor(0,1);  
          LCD.write("AFORO LLENO"); 
          FINAL();                    
         break;                                     
    }
           
             
}

 void PENTRADA(void){ //Setup de entradas.
  pinMode(ECHO, INPUT);
  
 }

void PSALIDA(void) //Setup de salidas.

{
     pinMode(TRIG, OUTPUT);    
                     
}

void BUZZERCON(void){ //Configuracion del buzzer.
            tone(buzzer, CDOM, 1500);   
           delay(750);
           noTone(buzzer);
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
    if(DISTANCE>=6 && DISTANCE <=10) //Si la distancia es entre 6cm o 10cm Ejecutara lo de las llaves.
  {
  CONT++;
  }   
}

void FINAL(void){ //Secuencia de animacion final.
   LCD.setCursor(0,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(0,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(0,0);
   LCD.write(" ");

   LCD.setCursor(1,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(1,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(1,0);
   LCD.write(" ");


    LCD.setCursor(2,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(2,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(2,0);
   LCD.write(" ");


   LCD.setCursor(3,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(3,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(3,0);
   LCD.write(" ");
    
    
   LCD.setCursor(4,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(4,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(4,0);
   LCD.write(" ");

    LCD.setCursor(5,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(5,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(5,0);
   LCD.write(" ");


    LCD.setCursor(6,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(6,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(6,0);
   LCD.write(" ");


    LCD.setCursor(7,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(7,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(7,0);
   LCD.write(" ");


    LCD.setCursor(8,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(8,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(8,0);
   LCD.write(" ");


     LCD.setCursor(9,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(9,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(9,0);
   LCD.write(" ");


     LCD.setCursor(10,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(10,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(10,0);
   LCD.write(" ");
     
     
     LCD.setCursor(11,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(11,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(11,0);
   LCD.write(" ");

     LCD.setCursor(12,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(12,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(12,0);
   LCD.write(" ");


     LCD.setCursor(13,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(13,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(13,0);
   LCD.write(" ");


     LCD.setCursor(14,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(14,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(14,0);
   LCD.write(" ");


     LCD.setCursor(15,0);
   LCD.write(byte(0));
   delay(500);
   LCD.setCursor(15,0);
   LCD.write(byte(1));
   delay(500);
   LCD.setCursor(15,0);
   LCD.write(" ");
  
}
