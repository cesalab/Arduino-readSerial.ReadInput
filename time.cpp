
#include "Arduino.h"
#include "config.h"

#ifdef TEENSY4
#include <TimeLib.h>

time_t getTeensy3Time();

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  SerialUSB.print(":");
  if(digits < 10)
    SerialUSB.print('0');
  SerialUSB.print(digits);
}

void digitalClockDisplay() {
  // digital clock display of the time
  SerialUSB.print(hour());
  printDigits(minute());
  printDigits(second());
  /*SerialUSB.print(" ");
  SerialUSB.print(day());
  SerialUSB.print(" ");
  SerialUSB.print(month());
  SerialUSB.print(" ");
  SerialUSB.print(year()); */
  SerialUSB.println(); 
}

time_t getTeensy3Time()
{
  return Teensy3Clock.get();
}


/*  code to process time sync messages from the Serial8 port   */
#define TIME_HEADER  "T"   // Header tag for Serial8 time sync message

unsigned long processSyncMessage() {
  unsigned long pctime = 0L;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013 

  if(SerialUSB.find(TIME_HEADER)) {
     pctime = SerialUSB.parseInt();
     return pctime;
     if( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
       pctime = 0L; // return 0 to indicate that the time is not valid
     }
  }
  return pctime;
}

void SetTimeInit(){
  setSyncProvider(getTeensy3Time);
  if (timeStatus()!= timeSet) {
      SerialUSB.println("Unable to sync with the RTC");
    } else {
      SerialUSB.println("RTC has set the system time");
    }
    digitalClockDisplay();

    delay(100);

    if (SerialUSB.available()) {
            time_t t = processSyncMessage();
         if (t != 0) {
            Teensy3Clock.set(t); // set the RTC
            setTime(t);
      }
    }
}

#endif
