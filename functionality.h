#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LENGTH 50  // sets maximum length
#define HASH_MAX 26


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


void initialize_table();
void insert_employee(employee emp);
employee *find_employee(int id);
void delete_employee(int id);
void print_table();

#endif