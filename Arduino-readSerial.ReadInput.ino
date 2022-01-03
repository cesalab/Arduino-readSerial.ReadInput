/*
 * PROGRAMA FUNCIONAL AL 29/12/2021
 * teensy 4.1 
 * Opera el RTC, solo funciona en teensy 3.0 y adelante
 * JASAVM 
 */
#include "config.h"

uint32_t counterOp = 0;         //
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)


void setup() {

    //Inicializamos I/O
    for (int i = 0; i <= 45; i++) {
        pinMode(i, INPUT);
    }
    
    SerialUSB.begin(921600); // opens Serial8 port, sets data rate to 9600 bps
    //Serial8.setTimeout(10);
    while (!SerialUSB);  // Wait for Arduino Serial Monitor to open
     delay(100);

    // set the Time library to use Teensy 3.0's RTC to keep time
    SetTimeInit();
    
    SerialUSB.println("Iniciando... "); 
    Serial.println("\n" " " __DATE__ "_" __TIME__);
   // SerialUSB.setTimeout(200);
     //  while (!Serial);  // Wait for Arduino Serial8 Monitor to open
       //  delay(100);

    SerialUSB.println();  
    SerialUSB.print("MAX_ADDR: ");     SerialUSB.println(MAX_ADDR);
    
    address_mode();
    data_mode();
    control_mode();
    enableDisable_mem();
    selection_mem();
    printMenu();
}

void loop() {
  
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
              digitalClockDisplay();
              //SerialUSB.println(Teensy3Clock.get());  
    }//end if
    //SerialUSB.println(" ");
    //delayMicroseconds(10);

    delay(100);
    //readCommands();     // read the commands:

    uint32_t addr1 = address_mode();
    uint32_t addr2 = address_mode();
   
    if(addr1 == addr2){
        printNumberOp(counterOp);
        printAddr(132);
        data_mode();
        control_mode();
        enableDisable_mem();
        selection_mem();
        //delay(500);
    }
    
    counterOp++;
    SerialUSB.println();  
}
