/* main.cpp */
/* DO NOT CHANGE ANYTHING */
#include "address.h"
#include <vector>
#include <string>
#include <iostream>

int main(){
  std::vector<std::string> arguments;
  std::string temp{};
  while (true){
	arguments.clear();
	std::string line{};
	std::getline(std::cin, line);
	std::istringstream iss(line);
    while (!iss.eof()){
      iss >> temp;
      arguments.push_back(temp);
    };
    if (!Address::parse_arg(arguments)) std::cout << "Invalid input" << std::endl;
    Address::print_data();
  };
  return 0;
}
