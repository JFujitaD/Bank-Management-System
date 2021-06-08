#include <stdlib.h>
#include <stdio.h>
#include "bank_manager.h"

struct Account {
    float savings;
    float checking;
    char full_name[25];
};

struct Account *pAccounts;
struct Account *pCurrent;
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
        break;
    
    default:
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
        pCurrent = pAccounts;
        *pCurrent = a;

        printf("INITIALIZED NEW ARRAY \n\n");
    }
    // There is not enough memory for another account.
    else if(pCurrent + 1 == NULL){
        arraySize *= 2;
        pCurrent = pAccounts;                                   // Keep track of account head.

        pAccounts = malloc(sizeof(struct Account) * arraySize); // Set head to new array.
        struct Account *pTemp = pAccounts;                      

        while (pCurrent != NULL){   // Iterate through old array and put it into new one.
            *pTemp = *pCurrent;
            pTemp += 1;
            pCurrent += 1;
        }
        pCurrent = pTemp - 1;

        free(pTemp);
        printf("DOUBLED ARRAY TO %d\n\n", arraySize);
    }
    // There is enough room for another account.
    else{
        pCurrent++;
        *pCurrent = a;

        printf("ADDED TO ARRAY \n\n");
    }
        
}