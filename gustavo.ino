#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int SetPoint = 260;
int RELAY1 = 10; // Relay 1 -> PIN 10
int RELAY2 = 11; // Relay 2 -> PIN 12
int ciclo1 = 0;
int ciclo2 = 0;
int sensorValue;
int actual;
int treinta;  // declaro la variable treinta (segundos)
int cientoOchenta; // // declaro la variable cientoOchenta (segundos)

void setup() {
  
  Serial.println("Iniciando sistema .."); // Imprimo por el monitor serial
  Serial.begin(9600);  // Inicio monitor Serial
  pinMode(RELAY1,OUTPUT); // Declaro el pin como salida
  pinMode(RELAY2,OUTPUT);  //Declaro el pin como salida
  digitalWrite(RELAY1,HIGH);  // Enciendo el Rele-1
  Serial.println("Enciendo el Rele 1");
  lcd.begin(16, 2); // Inicio la pantalla
  ciclo1=1;
  Serial.println("Iniciado correctamente"); // Imprimo por el monitor serial

}

void loop() {
/* ESTO LO UITLIZO PARA INGRESAR LA TEMPERATURA POR LE MONITOR SERIAL
   if (Serial.available() > 0) {
      delay(20);
      String bufferString = "";
      while (Serial.available() > 0) {
      bufferString += (char)Serial.read();
    }
    
   Serial.println(bufferString);
   Serial.println(SetPoint);
     
 sensorValue = String(bufferString).toInt();

 
 }
 */

  sensorValue = analogRead(A0); // Igualo la variable sensor a la lectura del Pin A0
  if (ciclo1 == 1){ funcion1(); }// llamo a la funcion "Funcion-1"
  if (ciclo2 == 1){ funcion2(); }// llamo a la funcion "Funcion-2"


}

void funcion1(){ // Funcion 1
 
//Serial.print("Funcion 1 ");
 if (sensorValue >= SetPoint){ Serial.println("Es MAYOR"); }else {Serial.println("Es Menor");}
 delay(1000);
 if (sensorValue >= SetPoint){ 
  
    digitalWrite(RELAY1, LOW);  // Apago el Rele-1
    Serial.println("Apago el Rele 1");// Imprimo por monitor Serial
    digitalWrite(RELAY2, HIGH);  // Enciendo el Rele-2
    Serial.println("Enciendo el Rele 2");// Imprimo por monitor Serial
   
    ciclo2 = 1;
    ciclo1 = 0;
    
    actual = millis()/1000; 
    treinta = actual + 30;
    cientoOchenta = actual + 180;

    Serial.print("ACTUAL");// Imprimo por monitor Serial
    Serial.println(actual);
    Serial.print("treinta");// Imprimo por monitor Serial
    Serial.println(treinta);
    Serial.print("cientoochenta");// Imprimo por monitor Serial
    Serial.println(cientoOchenta);
  } else {

  digitalWrite(RELAY1,HIGH);  // Enciendo el Rele-1
    
  }

}


void funcion2(){ // funcion 2

    actual = millis()/1000;
    Serial.println(actual);// Imprimo por monitor Serial
   // delay(1000);
    
    if ( actual >= treinta){
      digitalWrite(RELAY2, LOW);  // Apago el Rele-2
      Serial.println("Apago el Rele 2"); // Imprimo por monitor Serial
    
      }

    if ( actual >= cientoOchenta){
     ciclo1 = 1;
     ciclo2 = 0;
      }
  
}


