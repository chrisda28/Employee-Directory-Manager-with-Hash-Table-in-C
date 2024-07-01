#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "functionality.h"

// sets each bucket of hash table to NULL
void initialize_table()
{
    for (int i = 0; i < HASH_MAX; i++)
            table[i] = NULL;   // indicate that no employees have been recorded yet
}


int hash(int id)
{
    return id % HASH_MAX;  // taking remainder of ID divided by HASH_MAX
}
    


void insert_employee(employee emp)
{
    int hash_index = hash(emp.id);  // finds hash index
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)  // error handling
        {
            printf("Memory allocation error\n");
            exit(EXIT_FAILURE);  // Terminate the program upon malloc failure
        }
    // prepend new_node to beginning of linked list by implementing chaining
    new_node->emp = emp;
    new_node->next = table[hash_index];  // links new_node into linked list
    table[hash_index] = new_node;  // updates new_node as head of linked list
}


employee *find_employee(int id)
{
    int index = hash(id);
    node *trav = table[index];



}


void delete_employee(int id)
{

}


void print_table()
{

}