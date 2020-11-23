#include <stdio.h>
#include <stdbool.h>
#include<math.h> 

double allAccounts[2][50] = {0};

bool validAccount(int number){
    if(number >= 900 && number <= 950) return true;
    return false;
}

bool isOpen(int account){
    if(allAccounts[0][account-900] == 1) return true;
    return false;
}

void createAccount(int account, double init){
    if(validAccount(account)){
        if(!isOpen(account)){
            allAccounts[0][account-900] = 1;
            allAccounts[1][account-900] = floor(init * 100) / 100;
            printf("A new account number %d has been created\n",account);
        }else{
            printf("This account number already exists\n");
        }
    }else{
        printf("Invalid account number\n");
    }
}

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

void deposit(int account, double money){
    if(validAccount(account)){
        if(isOpen(account)){
            allAccounts[1][account-900] += money;
            printf("Your balance after deposit in account number %d is %.2lf\n",account, allAccounts[1][account-900]);
        }else{
            printf("This account is closed or does not exist\n");
        }
    }else{
        printf("Invalid account number\n");
    }
}

void withdraw(int account, double money){
    if(validAccount(account)){
        if(isOpen(account)){
            if(money <= allAccounts[1][account-900]){
                allAccounts[1][account-900] -= money;
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
            printf("Account number %d is closed", account);
        }else{
            printf("The bank account is already closed or does not exist");
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
    printf("All accounts have been closed\n");
}
