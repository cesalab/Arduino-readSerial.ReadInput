/*
 * PROGRAMA FUNCIONAL AL 29/12/2021
 * teensy 4.1 
 * Opera el RTC, solo funciona en teensy 3.0 y adelante
 * JASAVM 
 */
#include "gpio.h"
#include "librsc.h"
#include "libin.h"
#include "config.h"

#include <TimeLib.h>
uint32_t i = 0;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)

uint32_t previousaddr = 0;

void setup() {
    // set the Time library to use Teensy 3.0's RTC to keep time
     setSyncProvider(getTeensy3Time);
  
    SerialUSB.begin(921600); // opens Serial8 port, sets data rate to 9600 bps
    
        //Serial8.setTimeout(10);
    while (!SerialUSB);  // Wait for Arduino Serial Monitor to open
     delay(100);
    SerialUSB.println("Iniciando... "); 
    Serial.println("\n" " " __DATE__ "_" __TIME__);
   // SerialUSB.setTimeout(200);
     //  while (!Serial);  // Wait for Arduino Serial8 Monitor to open
       //  delay(100);
    if (timeStatus()!= timeSet) {
      SerialUSB.println("Unable to sync with the RTC");
    } else {
      SerialUSB.println("RTC has set the system time");
    }
    digitalClockDisplay();
    SerialUSB.println();  
    SerialUSB.print("MAX_ADDR: ");     SerialUSB.println(MAX_ADDR);
  
    for (int i = 0; i <= 45; i++) {
        pinMode(i, INPUT);
    }

    delay(100);

        if (SerialUSB.available()) {
            time_t t = processSyncMessage();
         if (t != 0) {
            Teensy3Clock.set(t); // set the RTC
            setTime(t);
      }
    }

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
        printNumberOp(i);
        printAddr(132);
        data_mode();
        control_mode();
        enableDisable_mem();
        selection_mem();
        //delay(500);
    }
    
    i++;
    SerialUSB.println();  
}
