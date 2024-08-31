#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "array.h"

void processInputFile(int arr[], int size, std::ifstream& fin) 
	/*
	Reads Input File and Stores in Array
	Parameters:
		int arr[]: integer array to store values in
		int size: integer size of array
		std::ifstrream& fin: ifstream input file object to read from

	Returns:
		None
	*/
{
	std::string line, tempStr;
	while (std::getline(fin, line)) 
	{
		std::stringstream inSS(line);
		while (std::getline(inSS, tempStr, ' ')) 
		{
			try 
			{
				append(stoi(tempStr), arr, size);
			}
			catch(std::out_of_range& e) {
				std::cout << e.what() << std::endl;
				std::cout << "Aborted file read at " << tempStr << std::endl;
				return;
			}
		}
	}
}

int search(int key, int arr[], int size)
	/*
	Q1.1)
	Linear Search Over Array
	Parameters:
		int key: integer value to find
		int arr[]: integer array to search
		int size: integer size of array

	Returns:
		int: Returns integer index if found, otherwise returns -1
	*/
{
	for (int index = 0; index < size; index++) 
		if (key == arr[index]) return index;
	return -1;
}

std::pair<int, int> modify(int index, int newValue, int arr[], int size)
	/*
	Q1.2)
	Modify Value At Index
	Parameters:
		int index: integer index to modify
		int newValue: integer value to store at index
		int arr[]: integer array to modify
		int size: integer size of array

	Returns:
		pair<int, int>: Returns integer pair (newValue, oldValue)
	*/
{
	if (index >= size) 
	{
		throw std::out_of_range("Error: Index out of range");
	}
	std::pair<int, int> result (newValue, arr[index]);
	arr[index] = newValue;
	return result;	
}

int append(int value, int arr[], int size)
	/*
	Q1.3)
	Append Value to End of Array
	Parameters:
		int value: integer value to append
		int arr[]: integer array to append to
		int size: integer size of array

	Returns:
		int: Returns integer index of new value
	*/
{
	for (int index = 0; index < size; index++ ) {
		if (arr[index] == 0) {
			arr[index] = value;
			return index;
		}
	}
	throw std::out_of_range("Error: Array is full");
}

void removeFromArray(int index, int arr[], int size)
	/*
	Q1.4)
	Remove Value by Index
	Parameters:
		int index: integer index to remove
		int arr[]: integer array to modify
		int size: integer size of array

	Returns:
		None
	*/
{
	for (int iter = index; iter < size - 1; iter++)
	{
		arr[iter] = arr[iter + 1];
	}
	arr[size - 1] = 0;
	return;
}

void printArray( int arr[], int size, int columns = 10)
	/*
	Print Array to Console
	Parameters:
		int arr[]: integer array to display
		int size: integer size of array
		int columns: integer number of columns to display

	Returns:
		None
	*/
{
	if (columns <= 0) columns = 10;
	for( int index = 0; index < size; index++)
	{
		if (index % columns == 0) std::cout << std::endl;
		std::cout << " " << std::setw(3) << std::setfill(' ') << arr[index] << " ";
	}
}

void printMenu()
	/*
	Print Formatted Menu to Console
	Parameters:
		None

	Returns:
		None
	*/
{
	std::cout << std::endl;
	std::cout << std::setfill('=') << std::right << std::setw(10) << "MENU" << std::setw(7) << " " << std::endl;
	std::cout << "1. Modify Array" << std::endl;
	std::cout << "2. Append Value to Array" << std::endl;
	std::cout << "3. Search By Value" << std::endl;
	std::cout << "4. Remove Value By Index" << std::endl;
	std::cout << "5. Print Array" << std::endl;
	std::cout << "Q. Quit" << std::endl;
}

bool processInput(int arr[], int size) 
	/*
	Process Input Based on Menu
	Parameters:
		int arr[]: integer array to process
		int size: integer size of array

	Returns:
		bool: Boolean value to break out of program loop when quitting
	*/
{
	char input;
	int index, key, newValue, columns;
	std::cout << ">>> ";
	std::cin >> input;
	switch(input)
	{
		case '1':
			// Modify Array
			index = getInt("Enter an index: ");
			newValue = getInt("Enter a new value: ");
			// Q2.1 Error Handling
			try
			{
				modify(index, newValue, arr, size);
			}
			catch (const std::out_of_range& e) 
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case '2':
			// Append Value to Array
			newValue = getInt("Enter a value to append: ");
			// Q2.2 Error Handling
			try 
			{
				append(newValue, arr, size);
			}
			catch(const std::out_of_range& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case '3':
			// Search By Value
			key = getInt("Enter a value to find: ");
			index = search(key, arr, size);
			if (index == -1) 
			{
				std::cout << key << " not found." << std::endl;
			}
			else
			{ 
				std::cout << key << " found at index " << index << std::endl;
			}
			break;
		case '4':
			// Remove Value By Index
			index = getInt("Enter an index to delete: ");
			if (index >= size) {
				std::cout << "Index " << index << " out of range." << std::endl;
			}
			else 
			{
				removeFromArray(index, arr, size);
			}
			break;
		case '5':
			// Print Array
			columns = getInt("Enter number of columns: ");
			printArray(arr, size, columns);
			std::cout << std::endl;
			break;
		case 'q':
		case 'Q':
			// Quit
			std::cout << "Goodbye!" << std::endl;
			return true;
		default:
			std::cout << "Invalid Input: " << input << std::endl;
	}
	return false;
}

int getInt(std::string prompt)
	/*
	Gets and Validates Integer Input from User
	Parameters:
		std::string prompt: string for text to display before input

	Returns:
		int: validated integer input
	*/
{
	std::cout << prompt;
	std::string input;
	std::cin >> input;
	try
	{
		int result = stoi(input);
		return result;
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid input: " << input << std::endl;
		return getInt(prompt);
	}
	
}