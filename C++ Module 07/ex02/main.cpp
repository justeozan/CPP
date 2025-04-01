
#include "Array.hpp"

int main() {
	std::cout << YELLOW "======== TEST WITH INT ========" << RESET << std::endl;

    try {
        Array<int> array1(10);
        for (unsigned int i = 0; i < array1.getSize(); ++i) {
            array1[i] = i * 10;
			std::cout << "array1[" << i << "] : "<< array1[i] << std::endl;
        }
		
		std::cout << YELLOW "==== Copy constructor + modif :" << RESET << std::endl;
        Array<int> array2 = array1; // Test du constructeur de copie
        array2[0] = 100; // Modifie la copie

        std::cout << "array1[0]: " << array1[0] << std::endl; // Devrait être 0
        std::cout << "array2[0]: " << array2[0] << std::endl; // Devrait être 100

		std::cout << YELLOW "==== Assignement operator :" << RESET << std::endl;
        Array<int> array3(5);
        array3 = array1; // Test de l'opérateur d'assignation
        std::cout << "array1[3]: " << array1[3] << std::endl; // Devrait être 30
        std::cout << "array3[3]: " << array3[3] << std::endl; // Devrait être 30

        std::cout << "array1 size: " << array1.getSize() << std::endl;
        std::cout << "array3 size: " << array3.getSize() << std::endl;

		std::cout << YELLOW "==== Test Access out of boundaries :" << RESET << std::endl;
        std::cout << array1[10] << std::endl; // Devrait lancer une exception
    } 
	catch (const std::exception& e)
	{
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }



	std::cout << YELLOW "======== TEST WITH CHAR ========" << RESET << std::endl;
	try {
        Array<char> array1(10);
        for (unsigned int i = 0; i < array1.getSize(); ++i) {
            array1[i] = static_cast<char>(i + 'a');
			std::cout << "array1[" << i << "] : "<< array1[i] << std::endl;
        }


		std::cout << YELLOW "==== Copy constructor + modif :" << RESET << std::endl;
        Array<char> array2 = array1; 
        array2[0] = 'm';
        std::cout << "array1[0]: " << array1[0] << std::endl; // Should be a
        std::cout << "array2[0]: " << array2[0] << std::endl; // Should be m


		std::cout << YELLOW "==== Assignement operator :" << RESET << std::endl;
        Array<char> array3(5);
        array3 = array1;
        std::cout << "array1[1]: " << array1[1] << std::endl; // Should be b
        std::cout << "array3[1]: " << array3[1] << std::endl; // Should be b
        std::cout << "array1 size: " << array1.getSize() << std::endl;
        std::cout << "array3 size: " << array3.getSize() << std::endl;


		std::cout << YELLOW "==== Test Access out of boundaries :" << RESET << std::endl;
        std::cout << array1[10] << std::endl; // Should throw an exception
    } 
	catch (const std::exception& e)
	{
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}