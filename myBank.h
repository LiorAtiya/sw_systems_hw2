#ifndef MYBANK_H
#define MYBANK_H

void createAccount(int account, double init);
void balance(int account);
void deposit(int account, double money);
void withdraw(int account, double money);
void closeAccount(int account);
void addInterest(double interest_rate);
void printAccounts();
void closeAllAcounts();

#endif
