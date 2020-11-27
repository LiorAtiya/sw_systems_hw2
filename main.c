#include <stdio.h>
#include "myBank.h"
#include <math.h>

int main(){
    int accountNumber;
    int countAccount = 901;
    double sum;
    char operation;
    int exit = 0;

    while(exit != 1){
        printf("Please choose a transaction type: \n");
        printf("O-Open Account\n");
        printf("B-Balance Inquiry\n");
        printf("D-Deposit\n");
        printf("W-Withdrawal\n");
        printf("C-Close Account\n");
        printf("I-Interest\n");
        printf("P-Print\n");
        printf("E-Exit\n");
        
        scanf(" %c", &operation);
        
        switch (operation) {
        case 'O':
            if(countAccount <= 950){
                printf("Please enter amount for deposit: \n");
                if(scanf(" %lf", &sum) != 1){
                    printf("Failed to read the amount\n");
                    break;
                }
                printf("New account number is: %d\n", countAccount);
                createAccount(countAccount, sum);
                countAccount++;
            }
            break;
        case 'B':
            printf("Please enter account number: \n");
            if(scanf(" %d", &accountNumber) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            balance(accountNumber);
            break;
        case 'D':
            printf("Please enter account number: \n");
            if(scanf(" %d", &accountNumber) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            printf("Amount? ");
            if(scanf(" %lf", &sum) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            deposit(accountNumber, sum);
            break;
        case 'W':
            printf("Please enter account number: \n");
            if(scanf(" %d", &accountNumber) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            printf("Please enter the amount to withdraw: \n");
            if(scanf(" %lf", &sum) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            withdraw(accountNumber, sum);
            break;
        case 'C':
            printf("Please enter account number: ");
            if(scanf(" %d", &accountNumber) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            closeAccount(accountNumber);
            countAccount--;
            break;
        case 'I':
            printf("Please enter interest rate: \n");
            if(scanf(" %lf", &sum) != 1){
                printf("Failed to read the interest rate\n");
                break;
            }
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
            printf("Invalid transaction type\n");
            break;
        }
        printf("\n");
    } 
    return 0;
}

