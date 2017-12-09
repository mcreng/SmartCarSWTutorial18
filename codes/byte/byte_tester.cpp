#include <iostream>
#include "byte.h"

int main(){
	std::cout << (int)set_bit(0b101110, 4) << std::endl;
	std::cout << (int)set_bit(0b111011, 1) << std::endl;
	std::cout << (int)reset_bit(0b1111, 0) << std::endl;
	std::cout << (int)reset_bit(0b1001, 2) << std::endl;
	std::cout << (int)get_bit(0b1111, 0) << std::endl;
	std::cout << (int)get_bit(0b10100, 3) << std::endl;
	print_bin(0b11110110);
	print_bin(0b1010);
	print_hex(0xF5);
	print_hex(0x0D);
	return 0;
}
