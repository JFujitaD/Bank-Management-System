#include <stdlib.h>
#include <stdio.h>
#include "bank_manager.h"

struct Account {
    float savings;
    float checking;
    char fullName[25];
};

struct Account *pAccounts;
int currentIndex = 0;
int arraySize = 2;


void startSystem(){
    printf("BANK MANAGEMENT SYSTEM\n\n");

    printf("----MAIN MENU----\n");
    printf("1. Create new account\n");
    printf("2. Create transaction\n");
    printf("3. Check account\n");
    printf("4. Update account information\n");
    printf("5. Deactivate account\n");
    printf("6. Exit\n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\e[1;1H\e[2J");
    
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
    a.savings = 11000.99;
    a.checking = 29.65;

    // There are no accounts.
    if(pAccounts == NULL){
        pAccounts = malloc(sizeof(struct Account) * arraySize);
        pAccounts[currentIndex++] = a;
    }
    // There is space for another account
    else if(currentIndex < arraySize){
        pAccounts[currentIndex++] = a;
    }
    // There is no more space for another account.
    else{
        arraySize *= 2;
        currentIndex = 0;
        struct Account *pTemp = pAccounts;
        pAccounts = malloc(sizeof(struct Account) * arraySize);

        while(currentIndex < arraySize / 2){
            pAccounts[currentIndex] = pTemp[currentIndex];
            currentIndex++;
        }
        currentIndex++;
        free(pTemp);
    }
        printf("A: %d S: %d \n", currentIndex, arraySize);
}