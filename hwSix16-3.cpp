// Chapter 16 Programming Challenge #3 Minimum / Maximum Templates

/* Write templates for the two functions minimum and maximum. The minimum function
should accept two arguments and return the value of the argument that is the lesser
of the two. The maximum function should accept two arguments and return the value
of the argument that is the greater of the two. Design a simple driver program that
demonstrates the templates with various data types. */


#include "stdafx.h" 
#include <iostream> 
#include <string> 
#include "hwSix16-3.h"
//using namespace std; 

int main() {

	int a = 7, b = 9;
	double c = 27.9, d = 99.99;
	std::string e = "alpha", f = "zeta";

	std::cout << "values: " << a << " and " << b << std::endl;
	std::cout << "maximum: " << maximum<int>(a, b) << std::endl;
	std::cout << "values: " << c << " and " << d << std::endl;
	std::cout << "minimum: " << minimum<double>(c, d) << std::endl;
	std::cout << "values: " << e << " and " << f << std::endl;
	std::cout << "maximum: " << maximum<std::string>(e, f) << std::endl;

	return 0;
}