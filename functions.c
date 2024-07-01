#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <functionality.h>

// sets each bucket of hash table to NULL
void initialize_table()
{
    for (int i = 0; i < HASH_MAX; i++)
            table[i] = NULL;   // indicate that no employees have been recorded yet
}


int index hash(int id)
    return id % HASH_MAX;  // taking remainder of ID divided by HASH_MAX

void insert_employee(employee emp)
{
    int hash_index = hash(emp.id);  // finds hash index
    table[hash_index] = emp;
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)  // error handling
        {
            printf("Memory related error\n");
            return NULL;
        }
    if (table[hash_index] != NULL)  // prepend new_node to beginning of linked list
    {
        
    }
    else
        table[hash_index] = new_node;  // directly assign



}


employee *find_employee(int id)
{

}


void delete_employee(int id)
{

}


void print_table()
{

}