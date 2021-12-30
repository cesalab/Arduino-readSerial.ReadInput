#include "Arduino.h"
#include "config.h"
extern int SETDELAY;


void printMenu()
{
    SerialUSB.println("\nMenu:");
    SerialUSB.println("   1 - Capturar Datos");   
    SerialUSB.println("   2 - Modo Manual");   
    SerialUSB.println("   3 - Ayuda   ");
    SerialUSB.println("   m - Mostrar Menu");
}
