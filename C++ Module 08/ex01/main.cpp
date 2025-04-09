#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
	try {
		// ========= Test with 5 numbers =========
		std::cout << "\nTest with 5 numbers:" << std::endl;
		Span sp1(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.getVector();
		std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp1.longestSpan() << std::endl;

		// ========= Test with 10000 numbers =========
		std::cout << "\nTest with 10000 numbers:" << std::endl;
		Span sp2(10000);
		std::vector<int> numbers(10000);
		for (size_t i = 0; i < 10000; i++)
			numbers[i] = i + 1;
		sp2.addRange(numbers.begin(), numbers.end());
		sp2.getVector();
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
		
		// ========= Test of exceptions =========
		std::cout << "\nTest of exceptions:" << std::endl;
		Span sp3(1);
		sp3.addNumber(42);
		sp3.getVector();
		try {
			sp3.addNumber(43); // Should throw an exception
		} catch (const std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}
		
		Span sp4(2);
		sp4.addNumber(24);
		sp4.getVector();
		try {
			sp4.shortestSpan(); // Should throw an exception
		} catch (const std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}

		Span sp5(10);
		for (size_t i = 0; i < 10; i++)
			sp5.addNumber(i + 1);
		sp5.getVector();
		sp5.addRange(numbers.begin(), numbers.end()); // Should throw an exception
		
		
	} catch (const std::exception& e) {
		std::cerr << RED << "Erreur: " << e.what() << RESET << std::endl;
	}
	
	return 0;
}