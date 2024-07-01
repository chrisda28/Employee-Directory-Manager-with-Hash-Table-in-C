#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <functionality.h>


void initialize_table();
{// sets each bucket of hash table to NULL
    for (int i = 0; i < HASH_MAX; i++)
        {
            table[i] = NULL;   // indicate that no employees have been recorded yet
        }

}


int index hash(int id)
{
    return id % HASH_MAX;  // taking remainder of ID divided by HASH_MAX
}

void insert_employee(employee emp);
{

}


employee *find_employee(int id);
{

}


void delete_employee(int id);
{

}


void print_table();
{

}