#include <iostream>
#include <fstream>
#include <sstream>
#include "array.h"

int main(int argc, char* argv[])
{
	// Initialize Array
	// Read from file
	// Do user commands
	//
	if (argc < 3) 
	{
		std::cout << "Error: Not enough arguments provided to the program. " << argc - 1 
				  << " arguments passed, expected input-file and array-size." << std::endl;
		return -1;
	}

	std::ifstream fin;
	std::stringstream ss(argv[2]);
	int size;
	ss >> size;
	if (size <= 0)
	{
		std::cout << size << " is not a valid size for the array." << std::endl;
		return -1;
	}

	fin.open(argv[1]);
	if (!fin.is_open()) {
		std::cout << "Error: File " << argv[1] << " not found." << std::endl;
		return -1;
	}
	int arr[size] {};
	processInputFile(arr, size, fin);
	printArray(arr, size);
	std::cout << std::endl;


	while (true)
	{
		printMenu();
		if(processInput(arr, size)) break;
	}

	
}
