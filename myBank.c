#include <stdio.h>
#include <stdbool.h>
#include <math.h> 

/**
 * 2D array of all accounts containing: open/closed account and account balance.
 */
static double allAccounts[2][50] = {{0},{0}};

/**
 * Auxiliary function to check if the bank account is open or closed.
 */
bool isOpen(int account){
    // if(account <= 900 && account >= 951) return false;
    if(allAccounts[0][account-901] == 1) return true;
    return false;
}

/**
 * Creating a new bank account, if such an account number exists in the system -> if the bank 
 * is closed then a new one is opened in its place, otherwise it prints an error
 */
void createAccount(int account, double init){
    if(!isOpen(account)){
        allAccounts[0][account-901] = 1;
        allAccounts[1][account-901] = floor(init * 100) / 100;
    }else{
        printf("This account number already exists\n");
    }
}

/**
 * Prints the balance in the account if the account exists in the system.
 */
void balance(int account){
    if(isOpen(account)){
        double balance = allAccounts[1][account-901];
        printf("The balance of account number %d is: %.2lf\n",account, balance);
    }else{
        printf("This account is closed\n");
    }
}

/**
 * Account deposit if such an account exists in the system.
 */
void deposit(int account, double money){
    if(isOpen(account)){
        allAccounts[1][account-901] += floor(money * 100) / 100;
        printf("The new balance is: %.2lf\n",allAccounts[1][account-901]);
    }else{
        printf("This account is closed\n");
    }
}

/**
 * Withdrawal from the bank provided there is enough money in the account.
 */
void withdraw(int account, double money){
    if(isOpen(account)){
        if(money <= allAccounts[1][account-901]){
            allAccounts[1][account-901] -= floor(money * 100) / 100;
            printf("The new balance is: %.2lf\n", allAccounts[1][account-901]);
        }else{
            printf("Cannot withdraw more than the balance\n");
        }
    }else{
        printf("This account is closed\n");
    }
}

/**
 * Closing the bank account.
 */
void closeAccount(int account){
    if(isOpen(account)){
        allAccounts[0][account-901] = 0;
        printf("Closed account number %d\n", account);
    }else{
        printf("This account is already closed\n");
    }
}

/**
 * Addition of interest (calculated according to percentages).
 */
void addInterest(double interest_rate){
    for(int i=0 ; i < 50 ; i++){
        if(allAccounts[0][i] == 1){
           allAccounts[1][i] += allAccounts[1][i]*((double)interest_rate/100);
        }
    }
}

/**
 * Print the status of all open bank accounts.
 */
void printAccounts(){
    int i;
    for(i=0 ; i <= 50 ; i++){
        if(allAccounts[0][i] == 1){
           printf("The balance of account number %d is: %.2lf\n",i+901, allAccounts[1][i]);
        }
    }
}

/**
 * Closing all open bank accounts.
 */
void closeAllAcounts(){
    int i;
    for(i=0 ; i < 50 ; i++){
        if(allAccounts[0][i] == 1){
           allAccounts[0][i] = 0;
        }
    }
}
