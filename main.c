#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "functionality.h"




int main( int argc, char *argv[])  // remember to add error checking for CML arguments
{
    bool program_on = true;
    int choice = 0;
    int initial_id = 0;

    while (program_on == true)
    {
        printf(" Type a number below\n 1. Add new employee\n 2. Find employee\n 3. Update employee information\n 4. Delete employee\n 5. Print all employees\n 6. Exit\n");
        int success_indicator = scanf("%d", &choice);
        if (success_indicator != 1)  // error handling. Scanf should return 1 if it read successfully
        {
            printf("Invalid input. Rerun the program and closely follow directions");
            program_on = false;
            return 1;
        }

        if (choice == 1)
            {
                printf("Type 7 digit employee ID below.");
                // int inputted_id = scanf"%d", &initial_id;  // i dont know how to grab the requisite data and pass it in through the correct struct (employee)
                // like i could keep grabbing everything through scanf but how i do i convert it into employee data from that, theres gotta be a better way.

                program_on = false;
            }
        else if (choice == 2)
        {
            printf("Type 7 digit employee ID below.");
            int inputted_id = scanf("%d", &initial_id);
            employee *desired_employee = find_employee(initial_id);
            if (desired_employee == NULL) 
            {
                printf("Employee with ID %d not found.\n", initial_id);
            } 
            else 
            {
                printf("Employee found at address: %p\n", (void *)desired_employee);
        // Print other details of the employee if needed
            }


        }
    
        else if (choice == 3)
        {

        }

        else if (choice == 4)
        {

        }

        else if (choice == 5)
        {

        }

        else if (choice == 6)
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

    
}