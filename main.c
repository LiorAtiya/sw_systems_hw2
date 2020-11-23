#include <stdio.h>
#include "myBank.h"
#include <math.h>

void main(){
    static int count = 0;
    printf("Welcome to the bank\n");
    int account;
    double sum;
    char operation;
    int exit = 0;

    while(exit != 1){
        printf("\nO - Open new account \n");
        printf("B - The balance in account\n");
        printf("D - Deposit from account\n");
        printf("W - Withdraw from account\n");
        printf("C - Close account\n");
        printf("I - Add interest to all open accounts\n");
        printf("P - Print all bank accounts\n");
        printf("E - Exit and close all the acounts\n");
        printf("Transaction type?: ");
        scanf("\n%c", &operation);

        switch (operation)
        {
        case 'O':
            if(count < 50){
                printf("Enter a new account number: ");
                //NEED TO CHECK VALID INPUT
                scanf("%d", &account);
                printf("Initial deposit?: ");
                scanf("%lf", &sum);
                createAccount(account, sum);
                count++;
            }else{
                printf("The bank account quota is full");
            }
            break;
        case 'B':
            printf("Enter a account number: ");
            //NEED TO CHECK VALID INPUT
            scanf("%d", &account);
            balance(account);
            break;
        case 'D':
            printf("Enter a account number: ");
            //NEED TO CHECK VALID INPUT
            scanf("%d", &account);
            printf("Amount?: ");
            scanf("%lf", &sum);
            deposit(account, sum);
            break;
        case 'W':
            printf("Enter a account number: ");
            //NEED TO CHECK VALID INPUT
            scanf("%d", &account);
            printf("Amount?: ");
            scanf("%lf", &sum);
            withdraw(account, sum);
            break;
        case 'C':
            printf("Enter a account number: ");
            //NEED TO CHECK VALID INPUT
            scanf("%d", &account);
            closeAccount(account);
            count--;
            break;
        case 'I':
            printf("Interest rate?: ");
            scanf("%lf", &sum);
            addInterest(sum);
            break;
        case 'P':
            printAccounts();
            break;
        case 'E':
            closeAllAcounts();
            exit = 1;
            break;
        default:
            printf("Invaild input!");
            break;
        }
    }
}

