#include <array>
#include <utility>
#include <string>

void processInputFile( int arr[], int size, std::ifstream& fin );

int search( int key, int arr[], int size );
	// Call sort function
	// Implement search of sorted array

std::pair<int, int> modify( int index, int newValue, int arr[], int size );
	// Verify index holds non-zero value
	// Store value at index
	// Update value
	// Return pair of ints

int append( int value, int arr[], int size );
	// Get size of array
	// Check that last item is nonzero
	// 	If zero, iterate backwards until first nonzero number
	// 	Place value after number
	// 	Return array
	// Returns new array

void removeFromArray( int index, int arr[], int size );
	// Verifies that the index is within the size
	// Iterate over array starting at index until the end
	// Switch arr[i] with arr[j]

void printArray( int arr[], int size );
	// Print through array

void printMenu();

bool processInput(int arr[], int size);

int getInt(std::string prompt);