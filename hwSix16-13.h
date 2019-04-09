// Chapter 16 Programming Challenge #13 Exception Project 

/* Employee and ProductionWorker Classes

Modify the Employee and ProductionWorker classes so they throw exceptions when the following errors occur:
	• The Employee class should throw an exception named InvalidEmployeeNumber
	when it receives an employee number that is less than 0 or greater than 9999.
	• The ProductionWorker class should throw an exception named InvalidShift
	when it receives an invalid shift.
	• The ProductionWorker class should throw an exception named InvalidPayRate
	when it receives a negative number for the hourly pay rate. */

#include <iostream>
#include <string>

/* Design a class named Employee. The class should keep the following information in
	• Employee name
	• Employee number
	• Hire date */
class Employee 
{
	private:
		std::string name;
		int number, hireMonth, hireDay, hireYear;

	public:
		/* Write one or more constructors and the appropriate accessor and mutator functions
		for the class. */
		class InvalidEmployeeNumber 
		{
			private:
				int num;
			public:
				InvalidEmployeeNumber(int n) 
				{
					num = n;
				}
				int getNumber() const { return num; }
		};
		Employee() 
		{
			name = "";
			number = 0;
			hireMonth = 0;
			hireDay = 0;
			hireYear = 0;
		}
		Employee(std::string nombre, int numero, int month, int day, int year)
		{
			name = nombre;
			if (numero < 0 || numero > 9999)
			{
				throw InvalidEmployeeNumber(numero);
			}
			else
			{
				number = numero;
			}
			if (month < 0 || month > 12 || day < 0 || day > 31 || year < 1900 || year > 2018)
			{
				std::cout << "Error! Invalid hire date! Now terminating!\n";
				exit(EXIT_FAILURE);
			}
			else
			{
				hireMonth = month;
				hireDay = day;
				hireYear = year;
			}
		}
		std::string getName() const { return name; }
		int getNumber() const { return number; }
		std::string getHireDate() const 
		{ 
			std::string date = "";
			date += std::to_string(hireDay) + "/" + std::to_string(hireMonth) + "/" + std::to_string(hireYear);
			return date;
		}

		void setName(std::string nombre) { name = nombre; }
		void setNumber(int numero) 
		{ 
			if (numero < 0 || numero > 9999) 
			{
				throw InvalidEmployeeNumber(numero);
			}
			else 
			{
				number = numero;
			}
		}
		void setHireDate(int month, int day, int year)
		{
			if (month < 0 || month > 12 || day < 0 || day > 31 || year < 1900 || year > 2018) {
				std::cout << "Error! Invalid hire date! Now terminating!\n";
				exit(EXIT_FAILURE);
			}
			else 
			{
				hireMonth = month;
				hireDay = day;
				hireYear = year;
			}
		}
};

/* Next, write a class named ProductionWorker that is derived from the Employee class.
The ProductionWorker class should have member variables to hold the following
information:
	• Shift (an integer)
	• Hourly pay rate (a double ) */

/* The workday is divided into two shifts: day and night. The shift variable will hold an
integer value representing the shift that the employee works. The day shift is shift 1, and
the night shift is shift 2. Write one or more constructors and the appropriate accessor
and mutator functions for the class. Demonstrate the classes by writing a program that
uses a ProductionWorker object. */
class ProductionWorker : public Employee
{
	private:
		int shift;
		double payRate;
	public:
		class InvalidShift 
		{
			public:
				int sh;
			public:
				InvalidShift(int s) 
				{
					sh = s;
				}
				int getShift() const { return sh; }
		}; 
		class InvalidPayRate 
		{
			private:
				double pr;
			public:
				InvalidPayRate(double p) 
				{
					pr = p;
				}
				double getPayRate() const { return pr; }
		};  
		ProductionWorker() : Employee()
		{
			shift = 1;
			payRate = 0.0;
		}
		ProductionWorker(std::string n, int num, int d,
						int m, int y, int sh, double p) : Employee(n, num, d, m, y)
		{
			if (sh != 1 && sh != 2) 
			{
				throw InvalidShift(sh);
			}
			else if (p < 0) 
			{
				throw InvalidPayRate(p);
			}
			else 
			{
				shift = sh;
				payRate = p;
			}
		}
		std::string getShift() const 
		{
			if (shift == 1)
				return "Day";
			return "Night";
		}
		double getPayRate() const { return payRate; }
		void setShift(int sh) 
		{
			if (sh != 1 && sh != 2) 
			{
				throw InvalidShift(sh);
			}
			else 
			{
				shift = sh;
			}
		}
		void setPayRate(double p) 
		{
			if (p < 0) 
			{
				throw InvalidPayRate(p);
			}
			else 
			{
				payRate = p;
			}
		}
};