#include <iostream>
#include "dictionary.hpp"

int main(void){
	Key a=*(new Key);
	std::cout<<a;
	return 0;
}
