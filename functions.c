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


void load_csv()
{
    FILE *file = fopen("sampledata.csv", "r");
    if (file == NULL)
        {
            printf("Couldn't open file\n");
            return;
        }
    char buffer[100];  //sets max length of a line it can read
    while (fgets(buffer, 100, file) != NULL)  //going until the end of file
    {
        char * token;
        employee emp;

        token = strtok(buffer, ",");  // we are splitting the lines into tokens using the comma as delimiter, and this returns a NULL pointer. 
        emp.id = atoi(token); // turning the token to an integer
        token = strtok(NULL, ",");  // gets the next token
        strcpy(emp.name, token); //copy token to name field
        insert_employee(emp);  // insert it to hash table
    }
    fclose(file);
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
    int index = hash(id);  //finding hash index
    node *trav = table[index];  //starting the traversal   //do i need to malloc space for this node? NO
    while (trav != NULL)
    {
        if (trav->emp.id == id)  // checking for inputted id
        {
            return &(trav->emp);  //returning address of employee struct within the node
        }
        trav = trav->next;  // traversing through the linked list
    }
    return NULL;  // if nothing is found, return NULL
}


void delete_employee(int id)
{
    int delete_index = hash(id);
    node *trav = table[delete_index]; //starting the traversal
    node *prev = NULL;  // has to point to NULL because there is nothing before the head of the linkedlist
    while (trav != NULL)
    {
        if(trav->emp.id == id)
        {
            break;

        }
        prev = trav;  // keeping prev pointer one step behind trav
        trav = trav->next;  // traversing through the linkedlist
        
    
    }
    if (trav == NULL)
    {
        printf("Could not find desired employee");
        return;
    }
    if (prev = NULL)  // if the node to be deleted is the head of linked list, then have to update head of the linkedlist
    {
        table[delete_index] = trav->next;
    }
    else
        prev->next = trav->next;  // prev is the node before the one we want to delete, so we are skipping over trav with this line
    free(trav);  // freeing the memory of the orphaned node

}


void print_table()
{

}

void free_table()
{

}


