#include "polynomial.h"
#include <iostream>

int main(int argc, char** argv)
{
	    Linux103::Polynomial polynomial(argc, argv);
	        polynomial.print();
		std::cout << "\n";
		std::cout << polynomial.calculate(72);
		    std::cout << "\n";
		        polynomial.derive().print();
			std::cout << "\n";
			    return 0;
}
