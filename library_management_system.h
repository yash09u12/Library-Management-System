/*
 * Library Management System Header
 * Author: Shaurya Verma
 */

#ifndef LIBRARY_MANAGEMENT_SYSTEM_H
#define LIBRARY_MANAGEMENT_SYSTEM_H

typedef struct {
    char title[100];
    char author[50];
    int id;
    int issued;
} Book;

void add_book();
void display_books();
void issue_book();
void return_book();
void menu();

#endif
