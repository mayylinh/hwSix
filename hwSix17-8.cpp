// Chapter 17 Programming Challenge #8 Prime Number Generation

/* Write a program that asks the user to enter an integer greater than 1, then displays all of the prime
numbers that are less than or equal to the number entered.
	•	Once the user has entered a number, the program should populate a vector with all of the integers
	from 2, up through the value entered.
	•	The program should then use the STL’s for_each function to step through the vector.The for_each
	function should pass each element to a function object that displays the element if it is a prime number. */

#include "stdafx.h" 
#include <iostream> 
#include <vector> 
#include <algorithm>

void printv(std::vector<int> &v)
{
	if (v.empty())
		return;
	for (int &i : v)
		std::cout << i << " ";
	std::cout << std::endl;
} 

void prime(int i)
{
	bool isPrime = true;
	for (int n = 2; n <= (i / 2); ++n)
	{
		if (i % n == 0)
			isPrime = false;
	}
	if (isPrime)
	std::cout << i << " ";
}

int main()
{
	int number;
	std::vector<int> numbers = { };

	std::cout << "enter an integer greater than 1: ";
	std::cin >> number;

	for (int i = 2; i <= number; i++)
		numbers.push_back(i);
	std::cout << "\nvector of integers from 2 through integer entered: \n";
	printv(numbers);

	std::cout << "\nvector of PRIME integers from 2 through integer entered: \n";
	std::for_each(numbers.begin(), numbers.end(), prime);
	std::cout << std::endl;

	return 0;
}