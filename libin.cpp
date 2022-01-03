#include "Arduino.h"
#include "config.h"


void printNumberOp(uint32_t numberOp){

  if(numberOp < 10) SerialUSB.print('0');
  if(numberOp < 100) SerialUSB.print('0');
  if(numberOp < 1000) SerialUSB.print('0');
  if(numberOp < 10000) SerialUSB.print('0');
  if(numberOp < 100000) SerialUSB.print('0');
  //if(numberOp < 1000000) SerialUSB.print('0');
  SerialUSB.print(numberOp);  
  SerialUSB.print("_"); 
  
}


void printAddr(uint32_t numberAddr){

  SerialUSB.print("A");  
  if(numberAddr < 0x10) SerialUSB.print('0');
  if(numberAddr < 0x100) SerialUSB.print('0');
  if(numberAddr < 0x1000) SerialUSB.print('0');
  if(numberAddr < 0x10000) SerialUSB.print('0');
  SerialUSB.print(numberAddr, HEX);  
  SerialUSB.print("_"); 
  
}

uint32_t readAddr(uint8_t pinStart, uint8_t pinFinal) {
  uint32_t data = 0;
  uint32_t mask = 0x1;
  for (int i = pinStart; i <= pinFinal; i++) {
    if (digitalRead(i) == HIGH) {
      data |= mask;
    }
    mask = mask << 1;
  }
  return data;
}


int address_mode(){
      uint32_t b = readAddr(ADDR0, ADDR19);
      printAddr(b);
      return b;
}

void data_mode(){
      uint8_t b = readAddr(DATA0, DATA7);
      SerialUSB.print("D");
      if (b < 16)      
          SerialUSB.print("0");
      SerialUSB.print(b, HEX);   SerialUSB.print("_");
}




void control_mode(){

  uint8_t b = readAddr(RPPin, WEPin);
  SerialUSB.print("C");
  switch (b){
      case READ:
            SerialUSB.print("RD");
            break;
      case WRITE:
            SerialUSB.print("WR");
            break;
      case OUTDIS:
            SerialUSB.print("OD");
            break;
      default:
            SerialUSB.print("0");
            SerialUSB.print(b);
            break;     
            
    }
    SerialUSB.print("_");
    
}



void enableDisable_mem(){

  uint8_t b = readAddr(G2APin, G1Pin);
  switch (b){
      case ENABLE_MEM:
            SerialUSB.print("E");
            break;
      case DISABLE_MEM:
            SerialUSB.print("D");
            break;
      default:  //Other disable option
            SerialUSB.print("x");
            break;     
            
    }
    SerialUSB.print(b);
}

void selection_mem(){

  uint8_t b = readAddr(A138Pin, C138Pin);

  switch (b){
      case M0:
            SerialUSB.print("M0");
            break;
      case M1:
            SerialUSB.print("M1");
            break;
      case M2:
            SerialUSB.print("M2");
            break;
      case M3:
            SerialUSB.print("M3");
            break;
      case M4:
            SerialUSB.print("M4");
            break;
      case M5:
            SerialUSB.print("M5");
            break;
      case M6:
            SerialUSB.print("M6");
            break;
      case M7:
            SerialUSB.print("M7");
            break;
      default:
            //SerialUSB.println("NO select memory... ");  
            break;     
            
    }
    
}
