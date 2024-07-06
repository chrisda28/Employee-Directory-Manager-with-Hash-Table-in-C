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
        printf(" Type a number below\n 1. Find employee\n 2. Delete employee\n 3. Print all employees\n 4. Exit\n");
        int success_indicator = scanf("%d", &choice);
        if (success_indicator != 1)  // error handling. Scanf should return 1 if it read successfully
        {
            printf("Invalid input. Rerun the program and closely follow directions");
            program_on = false;
            return 1;
        }

        if (choice == 1)
        {
            int initial_id = 0;
            printf("Type 5 digit employee ID.");
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

        else if (choice == 3)
        {
            for (int i = 0; i < HASH_MAX; i++)  //iterating through each bucket of hash table
            {
                if (table[i] == NULL)   //skipping the iteration where head of linkedlist is empty
                    continue;
                node *trav; // initialize traversal pointer
                trav = table[i];  // set it to table index (head of linked list)
                while (trav != NULL)  //iterating through each linkedlist that makes up each bucket
                {
                    printf("Employee Name: %s\n", trav->emp.name);
                    printf("Employee ID: %d\n", trav->emp.id);
                    printf("Employee Department: %s\n", trav->emp.department);
                    printf("Employee Position: %s\n", trav->emp.position);
                    trav = trav->next;  // move to next node
                }
            }
        }

        else if (choice == 4)
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