#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bank_manager.h"

#define NAME_LIMIT 25
#define ADDRESS_LIMIT 50

void emptyBuffer();

struct Account {
    float savings;
    float checking;
    char *pFullName;
    char *pAddress;
};

struct Account *pAccounts;
int currentIndex = 0;
int arraySize = 2;


void startSystem(){
    printf("\n\nBANK MANAGEMENT SYSTEM \n\n");

    printf("----MAIN MENU---- \n");
    printf("1. Create new account \n");
    printf("2. Create transaction \n");
    printf("3. Check account \n");
    printf("4. Update account information \n");
    printf("5. Deactivate account \n");
    printf("6. Exit \n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        newAccount();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        printf("\nThank you, come again!\n");
        exit(0);
    default:
        printf("\nInvalid choice. Please try again.\n\n");
        break;
    }
}

void newAccount(){
    struct Account a;
    a.savings = 0;
    a.checking = 0;
    a.pFullName = malloc(sizeof(char) * NAME_LIMIT);
    a.pAddress = malloc(sizeof(char) * ADDRESS_LIMIT);

    // Handle user input
    printf("\nPlease enter your account information. \n");

    printf("\tFull Name: ");
    emptyBuffer();
    fgets(a.pFullName, NAME_LIMIT, stdin);

    printf("\tAddress: ");
    fgets(a.pAddress, ADDRESS_LIMIT, stdin);

    // There are no accounts.
    // Allocate space for 2 accounts.
    if(pAccounts == NULL){
        pAccounts = malloc(sizeof(a) * arraySize);
        pAccounts[currentIndex++] = a;
    }
    // There is space for another account
    else if(currentIndex < arraySize){
        pAccounts[currentIndex++] = a;
    }
    // There is no more space for another account.
    // Allocate double the size, copy over contents to new array.
    else{
        arraySize *= 2;
        currentIndex = 0;
        struct Account *pTemp = pAccounts;
        pAccounts = malloc(sizeof(a) * arraySize);

        while(currentIndex < arraySize / 2){
            pAccounts[currentIndex] = pTemp[currentIndex];
            currentIndex++;
        }
        pAccounts[currentIndex++] = a;
        free(pTemp);
    }

    printf("\nAccount was successfully created. \nPress ENTER to continue.");
    emptyBuffer();
    //printf("A: %d  S: %d", currentIndex, arraySize);
}

void emptyBuffer(){
     while (getchar() != '\n');  
}