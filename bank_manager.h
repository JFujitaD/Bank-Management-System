#ifndef BANK_MANAGER_H
#define BANK_MANAGER_H

#define NAME_LIMIT 25
#define ADDRESS_LIMIT 50

typedef struct Account Account;
struct Account {
    float savings;
    float checking;
    char *pFullName;
    char *pAddress;

    Account *pNext;
};

typedef struct LinkedList{
    Account *pHead;
} LinkedList;

void startSystem();

void newAccount();

void append(Account *a);

Account* searchByName(char *name);

void printAccount(Account *a);

void viewAccount();

void viewAccountList();

void newTransaction();

#endif