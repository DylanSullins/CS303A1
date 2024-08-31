#include <iostream>
#include <fstream>
#include <sstream>
#include "array.h"

int main(int argc, char* argv[])
{
	// Check arguments for proper amount
	// Arguments past the necessary three will be ignored
	if (argc < 3) 
	{
		std::cout << "Error: Not enough arguments provided to the program. " << argc - 1 
				  << " arguments passed, expected input-file and array-size." << std::endl;
		return -1;
	}

	std::ifstream fin;
	// Get size from command line arguments
	std::stringstream ss(argv[2]);
	int size;
	ss >> size;

	// Validate size
	if (size <= 0)
	{
		std::cout << size << " is not a valid size for the array." << std::endl;
		return -1;
	}

	// Open File and Validate
	fin.open(argv[1]);
	if (!fin.is_open()) {
		std::cout << "Error: File " << argv[1] << " not found." << std::endl;
		return -1;
	}
	// Initialize array 
	int arr[size] {};

	// Store input values in array
	processInputFile(arr, size, fin);

	// Close file
	fin.close();

	// Get inpput for displaying
	int columns = getInt("Enter number of columns to display: ");
	printArray(arr, size, columns);
	std::cout << std::endl;

	// Main Loop
	while (true)
	{
		printMenu();
		// processInput returns true if input is 'q'/'Q'
		if(processInput(arr, size)) break;
	}

	
}
