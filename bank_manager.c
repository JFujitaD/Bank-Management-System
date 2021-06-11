#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bank_manager.h"

LinkedList *pList = NULL;

void startSystem(){
    printf("\n\nBANK MANAGEMENT SYSTEM \n\n");

    printf("----MAIN MENU---- \n");
    printf("1. Create new account \n");
    printf("2. Check account \n");
    printf("3. Get account list\n");
    printf("4. Exit \n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    
    switch (choice)
    {
    case 1:
        newAccount();
        break;
    case 2:
        viewAccount();
        break;
    case 3:
        viewAccountList();
        break;
    case 4:
        printf("\nThank you, come again!\n");
        exit(0);
    default:
        printf("\nInvalid choice. Please try again.\n");
        printf("Press ENTER to continue.");
        getchar();
        break;
    }
}

void newAccount(){
    // Set new account up
    Account *a = malloc(sizeof(Account));
    a->savings = 0;
    a->checking = 25.00;
    a->pFullName = malloc(sizeof(char) * NAME_LIMIT);
    a->pAddress = malloc(sizeof(char) * ADDRESS_LIMIT);
    a->pNext = NULL;

    // Handle user input
    printf("\nPlease enter your account information. \n");

    printf("\tFull Name: ");
    fgets(a->pFullName, NAME_LIMIT, stdin);

    printf("\tAddress: ");
    fgets(a->pAddress, ADDRESS_LIMIT, stdin);

    append(a);

    printf("\nAccount was successfully created. \nPress ENTER to continue.");
    getchar();
}

void append(Account *a){
    // Empty list
    if(pList == NULL){
        pList = malloc(sizeof(LinkedList));
        pList->pHead = a;
    }
    // List is populated
    else{
        Account *pCurrent = pList->pHead;
        while(pCurrent->pNext != NULL){
            pCurrent = pCurrent->pNext;
        }
        pCurrent->pNext = a;
    }
}

void viewAccountList(){
    printf("\nRegistered Accounts \n");

    if(pList == NULL){
        printf("\tThere are no accounts registered. \n");
        printf("\nPress ENTER to continue.");
        getchar();
    }
    else{
        Account *pCurrent = pList->pHead;
        while(pCurrent->pNext != NULL){
            printAccount(pCurrent);
            pCurrent = pCurrent->pNext;
        }
        printAccount(pCurrent);

        printf("\nPress ENTER to continue.");
        getchar();
    }
}

Account* searchByName(char* name){
    Account *nullAccount = NULL;

    // List is empty
    if(pList == NULL){
        return nullAccount;
    }
    // List has values
    else{
        Account *pCurrent = pList->pHead;

        if(!strcmp(name, pCurrent->pFullName))
            return pCurrent;
        while(pCurrent->pNext != NULL){
            pCurrent = pCurrent->pNext;
            if(!strcmp(name, pCurrent->pFullName))
                return pCurrent;
        }
        if(!strcmp(name, pCurrent->pFullName))
            return pCurrent;
    }
    return nullAccount;
}

void viewAccount(){
    char *pName = malloc(sizeof(char) * NAME_LIMIT);

    printf("\nSearch by name: ");
    fgets(pName, NAME_LIMIT, stdin);
    Account *a = searchByName(pName);

    if(a == NULL){
        printf("\nAccount not found. \n");
        printf("Press ENTER to continue.");
        getchar();
    }
        
    else{
        printf("\nAccount Information \n");
        printAccount(a);
        printf("Press ENTER to continue.");
        getchar();
    }  

    free(pName);
}

void printAccount(Account *a){
    printf("\t    Name: %s", a->pFullName);
    printf("\t Address: %s", a->pAddress);
    printf("\tChecking: $%f\n", a->checking);
    printf("\t Savings: $%f\n\n", a->savings);
}