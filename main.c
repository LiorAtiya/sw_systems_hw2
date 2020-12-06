#include <stdio.h>
#include "myBank.h"
#include <math.h>

int main(){
    int accountNumber;
    int countAccount = 901;
    double sum;
    int precent;
    char operation;
    int exit = 0;

    while(exit != 1){
        printf("\nPlease choose a transaction type: \n");
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
                printf("Please enter amount for deposit: ");
                if(scanf(" %lf", &sum) == 1){
                    if(sum >= 0){
                        int i = 0;
                        while(i+901 <= 950 && isOpen(i+901)){
                            i++;
                        }
                        printf("New account number is: %d\n", i+901);
                        createAccount(i+901, sum);
                        countAccount++;
                    }else{
                        printf("Invalid Amount\n");
                    }
                }else{
                    printf("Failed to read the amount\n");
                }
            }else{
                printf("The bank is full\n");
            }
            break;
        case 'B':
            printf("Please enter account number: ");
            if(scanf(" %d", &accountNumber) != 1 || accountNumber < 901 || accountNumber > 950){
                printf("Failed to read the account number\n");
                break;
            }
            balance(accountNumber);
            break;
        case 'D':
            printf("Please enter account number: ");
            if(scanf(" %d", &accountNumber) != 1){
                printf("Failed to read the account number\n");
                break;
            }
            if(accountNumber < 901 || accountNumber > 950){
                printf("Invalid account number\n");
                    break;
            }
            if(!isOpen(accountNumber)){
                printf("This account is closed\n");
                break;
            }
            printf("Please enter the amount to deposit: ");
            if(scanf(" %lf", &sum) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            if(sum < 0){
                printf("Cannot deposit a negative amount\n");
                break;
            }
            deposit(accountNumber, sum);
            break;
        case 'W':
            printf("Please enter account number: ");
            if(scanf(" %d", &accountNumber) != 1){
                printf("Failed to read the account number\n");
                break;
            }
            if(!isOpen(accountNumber)){
                printf("This account is closed\n");
                break;
            }
            printf("Please enter the amount to withdraw: ");
            if(scanf(" %lf", &sum) != 1){
                printf("Failed to read the amount\n");
                break;
            }
            withdraw(accountNumber, sum);
            break;
        case 'C':
            printf("Please enter account number: ");
            if(scanf(" %d", &accountNumber) != 1 || accountNumber < 901 || accountNumber > 950){
                printf("Failed to read the account number\n");
                break;
            }
            closeAccount(accountNumber);
            countAccount--;
            break;
        case 'I':
            printf("Please enter interest rate: ");
            if(scanf(" %d", &precent) != 1){
                printf("Failed to read the interest rate\n");
            }else if(precent < 0){
                printf("Invalid interest rate\n");
            }else{
                addInterest(precent);
            }
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
        // printf("\n");
    } 
    return 0;
}

