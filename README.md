# CS303 Assignment 1
## Array functionality
Dylan Sullins

## How to Install
1. In a terminal, navigate to the directory that you want to clone the repository into. 
2. Run the command *"git clone https://github.com/DylanSullins/CS303A1.git"*
3. Run the command *"cd CS303A1"*
4. Run the command *"g++ \*.cpp -o output"*, where output is the filename for the executable

## How to Run
- The CLI command for this software is broken into 3 parts. *Executable Input Size*
- Example call on Windows 11 Powershell: *".\A1.exe A1input.txt 100"*
1. Executable - *A1.exe*: The output of the g++ call during installation. Whatever you chose for "output" executable.
2. Input - *A1input.txt*: Your input text file. See input constraints for more details.
3. Size - *100*: The desired size of your array. See input constraints for more details.

- After calling the command in the terminal, follow the prompt on the console. Enter the number of columns for displaying tthe array.
- After printing the initial array, follow the menu on the console, with valid inputs being 1-5 and q/Q. 
### Menu Options
1. Modify Array
2. Append Value to Array
3. Search by Value
4. Remove Value by Index
5. Print Array
Q. Quit

## Input Constraints
Input file must consist of positive integers separated by either a newline or a space. Other inputs will potentially cause unanticipated behavior. Format your input following the patterns of the sample input file, *A1input.txt*
For size, include at least enough space for the size of your input file. The array's size is fixed; if you supply a size less than the amount of input data, only a portion of the data will be read into the array. For the sample input, ensure size >= 100.