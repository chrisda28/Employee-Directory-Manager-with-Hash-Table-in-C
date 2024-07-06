# Employee Directory Manager with Hash Table in C

## Brief Description
This C program loads sample csv data into a hash table and then allows the user to find an employee, delete an employee, or print out all employees. The user will navigate a basic interface, allowing them to work with the program.

## Goals
 My goal is to show that I can work with dynamic memory allocation in C, implement and work with hash tables, use file I/O, handle errors, and use both structs and pointers.

## Features
- Load employee data from CSV file into a hash table
- Find an employee by ID
- Delete an employee record
- Print all employee information
- Efficient data retrieval using hash table with chaining for collision resolution


## File Structure
- `main.c`: Contains the main program logic and user interface. It utilizes the functionality defined in other files to create an interactive employee management system.
- `functions.c`: Implements core functionality including hash table operations, file I/O, and employee data management.
- `functionality.h`: Defines key data structures (like employee and node structs) and declares function prototypes.
- `sampledata.csv`: Contains sample employee data for testing and demonstration purposes.

## Prerequisites
- GCC compiler
- Standard C libraries


## How to run program
1. navigate to project directory
2. compile code by typing gcc -o main main.c
3. run program by typing ./main
4. Follow on screen prompts to either find an employee by ID, delete an employee by their ID, print all employees, or exit the program


## Error Handling
The program includes basic error handling for file operations, memory allocation, and user input validation.

## Future Improvements
Error handling could be improved for edge cases, and for user inputs. Also, error messages could be more descriptive. 

## Author
Christian Asimou