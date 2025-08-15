/*
 * Library Management System
 * Author: Shaurya Verma
 * Date: August 15, 2025
 * Description: Console-based system for basic library management.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library_management_system.h"

#define MAX_BOOKS 100

Book books[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Book limit reached!\n");
        return;
    }
    printf("Enter book title: ");
    scanf(" %[^\n]", books[book_count].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", books[book_count].author);
    printf("Enter book ID: ");
    scanf("%d", &books[book_count].id);
    books[book_count].issued = 0;
    book_count++;
    printf("Book added successfully!\n");
}

void display_books() {
    printf("\n--- Library Book List ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book %d: Title: %s, Author: %s, ID: %d, Status: %s\n",
            i + 1, books[i].title, books[i].author, books[i].id,
            books[i].issued ? "Issued" : "Available");
    }
    if (book_count == 0) {
        printf("No books found.\n");
    }
}

void issue_book() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            if (books[i].issued) {
                printf("Book already issued!\n");
            } else {
                books[i].issued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void return_book() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (books[i].id == id) {
            if (!books[i].issued) {
                printf("Book was not issued!\n");
            } else {
                books[i].issued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: issue_book(); break;
            case 4: return_book(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
