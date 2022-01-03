#include "Arduino.h"
#include <String.h>
#include "config.h"

String incomingString;  // for incoming serial data
String stringSplit[MAX_COMMANDS] = {""};   // arrary to save values
char delimitadores[] = " ,;!()";    //elementos a excluir
char *resultado = nullptr;
char *strtok( char *str1, const char *str2 ); 


String readCommands(){
    if (SerialUSB.available()){
           // read the incoming byte:
          incomingString = Serial.readString() ;
          //Serial.print("I received: ");
          //Serial.println(stringSplit[0]);
          char colle[MAX_CHAR];
          uint8_t i = 0;
          
          incomingString.toCharArray(colle, MAX_CHAR);
          resultado = strtok( colle, delimitadores );
          stringSplit [i] = resultado;
          
          while( resultado != NULL ) 
          {
              i++;
              resultado = strtok( NULL, delimitadores );
              stringSplit[i] = resultado;
          }
          //imprimir array de palabras
          for (i = 0; i < MAX_COMMANDS; i++){
              if (stringSplit[i] == "")     break;
              //Serial.print("  stringSplit["); Serial.print(i); Serial.print("]: "); Serial.println(stringSplit[i]);
          }
          //revisamos cual es el ultimo lugar del array
          //Serial.print("Ultimo valor de array util = ");   Serial.print (--i);    
          //Serial.println("\n");
          return stringSplit[0];
    }    
}


void limpiarComandos(){
    //Serial.println("limpiando registros...");
    for(uint8_t i = 0; i < MAX_COMMANDS; i++)  { 
        stringSplit[i] = "";    //LIMPIA REGISTRO
        //Serial.print("  stringSplit["); Serial.print(i); Serial.print("]: "); Serial.println(stringSplit[i]);
    }
    //Serial.println("limpiado listo...");     
}
