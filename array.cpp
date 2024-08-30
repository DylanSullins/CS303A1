#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "array.h"

void processInputFile(int arr[], int size, std::ifstream& fin) 
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
{
	for (int index = 0; index < size; index++) 
		if (key == arr[index]) return index;
	return -1;
}

std::pair<int, int> modify(int index, int newValue, int arr[], int size)
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
{
	for (int iter = index; iter < size - 1; iter++)
	{
		arr[iter] = arr[iter + 1];
	}
	arr[size - 1] = 0;
	return;
}

void printArray( int arr[], int size )
{
	for( int index = 0; index < size; index++)
	{
		if (index % 10 == 0) std::cout << std::endl;
		std::cout << " " << std::setw(3) << std::setfill(' ') << arr[index] << " ";
	}
}

void printMenu()
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
{
	char input;
	int index, key, newValue;
	std::cout << ">>> ";
	std::cin >> input;
	switch(input)
	{
		case '1':
			// Modify Array
			index = getInt("Enter an index: ");
			newValue = getInt("Enter a new value: ");
			modify(index, newValue, arr, size);
			break;
		case '2':
			// Append Value to Array
			newValue = getInt("Enter a value to append: ");
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
			printArray(arr, size);
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