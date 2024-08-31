#include <array>
#include <utility>
#include <string>

void processInputFile( int arr[], int size, std::ifstream& fin );

int search( int key, int arr[], int size );
	/*
	Linear Search Over Array
	Parameters:
		int key: integer value to find
		int arr[]: integer array to search
		int size: integer size of array

	Returns:
		int: Returns integer index if found, otherwise returns -1
	*/

std::pair<int, int> modify( int index, int newValue, int arr[], int size );
	/*
	Modify Value At Index
	Parameters:
		int index: integer index to modify
		int newValue: integer value to store at index
		int arr[]: integer array to search
		int size: integer size of array

	Returns:
		pair<int, int>: Returns integer pair (newValue, oldValue)
	*/

int append( int value, int arr[], int size );
	/*
	Append Value to End of Array
	Parameters:
		int value: integer value to append
		int arr[]: integer array to search
		int size: integer size of array

	Returns:
		int: Returns integer index of new value
	*/

void removeFromArray( int index, int arr[], int size );
	/*
	Remove Value by Index
	Parameters:
		int index: integer index to remove
		int arr[]: integer array to search
		int size: integer size of array

	Returns:
		None
	*/
void printArray( int arr[], int size, int columns );
	/*
	Print Array
	Parameters:
		int arr[]: integer array to search
		int size: integer size of array
		int columns: integer number of columns to display

	Returns:
		None
	*/

void printMenu();

bool processInput(int arr[], int size);

int getInt(std::string prompt);