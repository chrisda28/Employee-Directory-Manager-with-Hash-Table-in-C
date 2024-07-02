
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

    while (program_on == true)
    {
        printf(" Type a number below\n 1. Add new employee\n 2. Find employee\n 3. Update employee information\n 4. Delete employee\n 5. Print all employees\n 6. Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
            {
                printf("HIII");
                program_on = false;
            }
        else if (choice == 2)
        {

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

        }

        else
        {
            printf("Invalid input. Rerun the program and closely follow directions")
            program_on = false;
            return 1;
        }
        
    }

    
}