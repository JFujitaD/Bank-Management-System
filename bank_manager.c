#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bank_manager.h"

LinkedList *pList = NULL;

void emptyBuffer(){
     while (getchar() != '\n');  
}

void startSystem(){
    printf("\n\nBANK MANAGEMENT SYSTEM \n\n");

    printf("----MAIN MENU---- \n");
    printf("1. Create new account \n");
    printf("2. Create transaction \n");
    printf("3. Check account \n");
    printf("4. Update account information \n");
    printf("5. Get account list\n");
    printf("6. Deactivate account \n");
    printf("7. Exit \n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        newAccount();
        break;
    case 5:
        emptyBuffer();
        viewAccountList();
        break;
    case 7:
        printf("\nThank you, come again!\n");
        exit(0);
    default:
        printf("\nInvalid choice. Please try again.\n\n");
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
    emptyBuffer();
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
        printf("\t0 accounts registered \n");
        printf("\nPress ENTER to continue.");
        getchar();
    }
    else{
        Account *pCurrent = pList->pHead;
        while(pCurrent->pNext != NULL){
            printf("\t    Name: %s", pCurrent->pFullName);
            printf("\t Address: %s", pCurrent->pAddress);
            printf("\tChecking: $%f\n", pCurrent->checking);
            printf("\t Savings: $%f\n\n", pCurrent->savings);
            pCurrent = pCurrent->pNext;
        }
        printf("\t    Name: %s", pCurrent->pFullName);
        printf("\t Address: %s", pCurrent->pAddress);
        printf("\tChecking: $%f\n", pCurrent->checking);
        printf("\t Savings: $%f\n", pCurrent->savings);

        printf("\nPress ENTER to continue.");
        getchar();
    }
}