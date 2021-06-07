#include <stdlib.h>
#include <stdio.h>
#include "bank_manager.h"

struct Account {
    float savings;
    float checking;
    char full_name[25];
};

struct Account *accounts;
int activeAccounts = 0;

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

    // No accounts have been created
    if(accounts == NULL){
        accounts = malloc(sizeof(struct Account));
        *accounts = a;
        activeAccounts++;
    }
        
}