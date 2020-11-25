#include <stdio.h>
#include <stdbool.h>
#include <math.h> 

/**
 * 2D array of all accounts containing: open/closed account and account balance.
 */
static double allAccounts[2][50] = {0};

/**
 * Counter of the number of accounts.
 */
static int count = 0;

/**
 * Help function for checking the input range of the number of accounts.
 */
bool validAccount(int number){
    if(number >= 901 && number <= 950) return true;
    return false;
}

/**
 * Help function to check if the bank account is open or closed.
 */
bool isOpen(int account){
    if(allAccounts[0][account-900] == 1) return true;
    return false;
}

/**
 * Creating a new bank account, if such an account number exists in the system,
 * if the bank is closed then a new one is opened in its place, otherwise it prints an error
 */
void createAccount(int account, double init){
    if(validAccount(account)){
        if(count < 50){
            if(!isOpen(account)){
                allAccounts[0][account-900] = 1;
                allAccounts[1][account-900] = floor(init * 100) / 100;
                printf("A new account number %d has been created\n",account);
                printf("The initial amount deposited is %lf \n",init);
                count++;
            }else{
                printf("This account number already exists\n");
            }
        }else{
            printf("The bank is full");
        }
    }else{
        printf("Invalid account number\n");
    }
}

/**
 * Prints the balance in the account if the account exists in the system.
 */
void balance(int account){
    if(validAccount(account)){
        if(isOpen(account)){
            double balance = allAccounts[1][account-900];
            printf("The balance in account number %d is %.2lf\n",account,balance);
        }else{
            printf("This account is closed\n");
        }
    }else{
        printf("Invalid account number\n");
    }
}

/**
 * Account deposit if such an account exists in the system.
 */
void deposit(int account, double money){
    if(validAccount(account)){
        if(isOpen(account)){
            double current = allAccounts[1][account-900];
            allAccounts[1][account-900] += floor(money * 100) / 100;
            printf("Your balance before deposit in account number %d is %.2lf\n",account, current);
            printf("Your balance after deposit in account number %d is %.2lf\n",account, allAccounts[1][account-900]);
        }else{
            printf("This account is closed or does not exist\n");
        }
    }else{
        printf("Invalid account number\n");
    }
}

/**
 * 
 */
void withdraw(int account, double money){
    if(validAccount(account)){
        if(isOpen(account)){
            if(money <= allAccounts[1][account-900]){
                double current = allAccounts[1][account-900];
                allAccounts[1][account-900] -= floor(money * 100) / 100;
                printf("Your balance before withdraw in account number %d is %.2lf\n",account, current);
                printf("Your balance after withdraw in account number %d is %.2lf\n",account, allAccounts[1][account-900]);
            }else{
                printf("There is not enough money in the account to withdraw such a sum\n");
            }
        }else{
            printf("This account is closed or does not exist\n");
        }
    }else{
        printf("Invalid account number\n");
    }
}

void closeAccount(int account){
    if(validAccount(account)){
        if(isOpen(account)){
            allAccounts[0][account-900] = 0;
            printf("Account number %d is closed\n", account);
            count--;
        }else{
            printf("The bank account is already closed or does not exist\n");
        }
    }else{
        printf("Invalid account number\n");
    }
}

void addInterest(double interest_rate){
    for(int i=0 ; i < 50 ; i++){
        if(allAccounts[0][i] == 1){
           allAccounts[1][i] += allAccounts[1][i]*interest_rate;
        }
    }
    printf("An interest rate of %.2lf percent was added for all open accounts\n", interest_rate);
}

void printAccounts(){
    int i;
    for(i=0 ; i <= 50 ; i++){
        if(allAccounts[0][i] == 1){
           printf("Account number : %.0d , Balance: %.2lf\n",i+900, allAccounts[1][i]);
        }
    }
}

void closeAllAcounts(){
    int i;
    for(i=0 ; i < 50 ; i++){
        if(allAccounts[0][i] == 1){
           closeAccount(i+900);
        }
    }
    count = 0;
    printf("All accounts have been closed and exit the bank\n");
}
