#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "functionality.h"
#include "functions.c"




int main( int argc, char *argv[])  // remember to add error checking for CML arguments
{
    bool program_on = true;
    int choice = 0;
    initialize_table();
    load_csv();
    
    while (program_on == true)
    {
        printf(" Type a number below\n 1. Add new employee\n 2. Find employee\n 3. Delete employee\n 4. Print all employees\n 5. Exit\n");
        int success_indicator = scanf("%d", &choice);
        if (success_indicator != 1)  // error handling. Scanf should return 1 if it read successfully
        {
            printf("Invalid input. Rerun the program and closely follow directions");
            program_on = false;
            return 1;
        }

        if (choice == 1)
            {
                printf("Type 5 digit employee ID below.");
                // int inputted_id = scanf"%d", &initial_id;  // i dont know how to grab the requisite data and pass it in through the correct struct (employee)
                // like i could keep grabbing everything through scanf but how i do i convert it into employee data from that, theres gotta be a better way.

                program_on = false;
            }
        else if (choice == 2)
        {
            int initial_id = 0;
            printf("Type 5 digit employee ID below.");
            int inputted_id = scanf("%d", &initial_id);
            if (inputted_id != 1)  // error handling. Scanf should return 1 if it read successfully
        {
            printf("Invalid input. Rerun the program and closely follow directions");
            program_on = false;
            return 1;  //exits the program with error status
        }
            employee *desired_employee = find_employee(initial_id);
            if (desired_employee == NULL)  // error check
            {
                printf("Employee with ID %d not found.\n", initial_id);
            } 
            else 
            {   // printing desired employee details
                printf("Employee found at address: %p\n", (void *)desired_employee);
                printf("Employee Name: %s\n", desired_employee->name);
                printf("Employee ID: %d\n", desired_employee->id);
                printf("Employee Department: %s\n", desired_employee->department);
                printf("Employee Position: %s\n", desired_employee->position);

                program_on = false;
            }
        }
    
        else if (choice == 3)
        {
            int initial_id = 0;
            printf("Type 5 digit employee ID below.");
            int inputted_id = scanf("%d", &initial_id);
            if (inputted_id != 1)  // error handling. Scanf should return 1 if it read successfully
            {
                printf("Invalid input. Rerun the program and closely follow directions");
                program_on = false;
                return 1;  //exits the program with error status
            }

            employee *emp_to_be_deleted = find_employee(initial_id);  //finding the employee so we can validate they exist
            if (emp_to_be_deleted == NULL)
                {
                    printf("Employee with ID %d not found\n", initial_id);
                    program_on = false;
                }
            else
            {
                delete_employee(initial_id);  // deleting the employee and giving user feedback
                printf("Employee with ID %d has been deleted\n", initial_id);
                printf("Start the program over if you wish to continue working.\n");
                program_on = false;
            }
            
        }

        else if (choice == 4)
        {
            for (int i = 0; i < table[i], i++)
            {
                while (table[i] != NULL)
                {
                    


                }
            }

        }

        else if (choice == 5)
        {
            program_on = false;
        }

        else
        {
            printf("Invalid input. Rerun the program and closely follow directions");
            program_on = false;
            return 1;
        }
    }
    if (table != NULL)
        free_table();
}