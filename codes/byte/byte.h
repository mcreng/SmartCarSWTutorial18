/* byte.h */
/* Do not alter */
#include <cstdint>
#ifndef __BYTE_H_
#define __BYTE_H_
typedef uint8_t Byte; // defining a new type 'Byte' to be equivalent to uint8_t

Byte set_bit(Byte byte, uint8_t n);
Byte reset_bit(Byte byte, uint8_t n);
bool get_bit(Byte byte, uint8_t n);
void print_bin(int bytes);
void print_hex(int bytes);
#endif
