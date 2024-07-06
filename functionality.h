#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LENGTH 50  // sets maximum length
#define HASH_MAX 26  //sets length of hash table


typedef struct{
    int id;
    char name[LENGTH];
    char position[LENGTH];
    char department[LENGTH];
} employee;


typedef struct node {
    employee emp;
    struct node *next;
} node;


node *table[HASH_MAX];

char *strtok(char *str, const char *delim);
void load_csv();
int hash(int id);
void initialize_table();
void insert_employee(employee emp);
employee *find_employee(int id);
void delete_employee(int id);
void free_table();

#endif