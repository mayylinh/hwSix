#include "hwSix16-13.h"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Creating default ProductionWorker object...\n";
	ProductionWorker worker;
	std::cout << "Done! All data set to default values!\n\n";

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "Now displaying data...\n";
	std::cout << "Name: " << worker.getName() << std::endl;
	std::cout << "Employee Number: " << worker.getNumber() << std::endl;
	std::cout << "Hire Date: " << worker.getHireDate() << std::endl;
	std::cout << "Working shift: " << worker.getShift() << std::endl;
	std::cout << "Pay rate: $" << worker.getPayRate() << "/hr" << std::endl;

	std::cout << "\nNow setting name to John Smith...\n";
	worker.setName("John Smith");
	std::cout << "Done!\n";

	std::cout << "\nNow setting employee number to 1234...\n";
	worker.setNumber(1234);
	std::cout << "Done!\n";

	std::cout << "\nNow setting hire date to 23/12/2010...\n";
	worker.setHireDate(23, 12, 2010);
	std::cout << "Done!\n";

	std::cout << "\nNow setting shift to Night...\n";
	worker.setShift(2);
	std::cout << "Done!\n";

	std::cout << "\nNow setting pay rate to $15.5/hr...\n";
	worker.setPayRate(15.5);
	std::cout << "Done!\n";

	std::cout << "\nNow displaying data again...\n";
	std::cout << "Name: " << worker.getName() << std::endl;
	std::cout << "Employee Number: " << worker.getNumber() << std::endl;
	std::cout << "Hire Date: " << worker.getHireDate() << std::endl;
	std::cout << "Working shift: " << worker.getShift() << std::endl;
	std::cout << "Pay rate: $" << worker.getPayRate() << "/hr" << std::endl;

	std::cout << "\nTrying to set employee number to -5";
	std::cout << " (Invalid value)...\n";
	try {
		worker.setNumber(-5);
	}
	catch (Employee::InvalidEmployeeNumber e) {
		std::cout << "Error caught!\n";
		std::cout << e.getNumber() << " is not a valid number!\n";
	}

	std::cout << "\nTrying to set shift to 3";
	std::cout << " (Invalid value)...\n";
	try {
		worker.setShift(3);
	}
	catch (ProductionWorker::InvalidShift e) {
		std::cout << "Error caught!\n";
		std::cout << e.getShift() << " is not a valid shift!\n";
	}

	std::cout << "\nTrying to set pay rate to -10";
	std::cout << " (Invalid value)...\n";
	try {
		worker.setPayRate(-10);
	}
	catch (ProductionWorker::InvalidPayRate e) {
		std::cout << "Error caught!\n";
		std::cout << e.getPayRate() << " is not a valid rate!\n";
	}

	return 0;
}