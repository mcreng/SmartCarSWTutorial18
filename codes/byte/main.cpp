#include <iostream>
#include "byte.h"

int main(){
	std::cout << (int)set_bit(14, 0) << std::endl;
	std::cout << (int)reset_bit(0b1111, 0) << std::endl;
	std::cout << (int)get_bit(0b1111, 0) << std::endl;
	return 0;
}
