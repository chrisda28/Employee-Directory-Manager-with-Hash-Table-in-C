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
    int index = hash(id);  //finding hash index
    node *trav = table[index];  //starting the traversal
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

}


void print_table()
{

}

void load_data() {
    FILE* file = fopen("sampledata.csv", "r");

    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* id = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* position = strtok(NULL, ",");
        char* department = strtok(NULL, ",");

        employee emp;
        emp.id = atoi(id);
        strncpy(emp.name, name, sizeof(emp.name));
        strncpy(emp.position, position, sizeof(emp.position));
        strncpy(emp.department, department, sizeof(emp.department));

        insert_employee(emp);
    }

    fclose(file);
}