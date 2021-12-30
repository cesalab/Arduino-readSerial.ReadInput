#ifndef libin_h
#define libin_h

#include "Arduino.h"

void printNumberOp(uint32_t );
void printAddr(uint32_t );
uint32_t readAddr(uint8_t , uint8_t );
int address_mode();
void data_mode();
void control_mode();
void enableDisable_mem();
void selection_mem();


#endif
