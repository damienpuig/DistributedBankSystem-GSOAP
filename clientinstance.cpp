/* 
 * File:   clientinstance.cpp
 * Author: damien
 * 
 * Client class implementation.
 * 
 */
#include <cstdlib>
#include <stdio.h>
#include "clientinstance.h"
#include "soapBankProxy.h"
#include "bankmapper.h"
#include "config.h"

clientinstance::clientinstance() {
}

clientinstance::clientinstance(const clientinstance& orig) {
}

clientinstance::~clientinstance() {
}

void clientinstance::init(){
    banks[0].init(bankserver1, "HSBC", 0);
    
    setbankcontextonclient();
    
    printf("Starting on banks %d", bankcontext.bid);
    
}

void clientinstance::getbalance(){
    
     printf("Get balance :\n");
     
    proxy.GetState(bankcontext.address, "", &formatedresult);
    
    printf("%s\n", formatedresult);
    
    printf("balance reached\n");
}

void clientinstance::performdeposit(){
     printstate("Deposit");
    printf("Amount of the deposit :");
    
    //deposit amount to perform
    float amount;
    scanf("%f", &amount);
    
    printf("awaiting reply for amount %f\n", amount);
    
    proxy.Deposit(bankcontext.address, "", amount, &formatedresult);
    
    printf("%s\n", formatedresult);
    
    printf("transaction finished :deposit:\n");  
}

void clientinstance::performwithdraw(){
     printstate("withdraw");
    printf("Amount of the withdraw :");
     //withdraw amount to perform
    float amountr;
    scanf("%f", &amountr);
    
    proxy.Withdraw(bankcontext.address, "", amountr, &formatedresult);

    printf("%s\n", formatedresult);
    
    printf("transaction finished :remove:\n");  
}

//menu shortcut
void clientinstance::menu(){
    printf("Choice an action :\n");
    printf("===== Deposit - 1\n");
    printf("===== Withdraw - 2\n");
    printf("===== Transfert - 3\n");
    printf("===== Balance - 4\n");
}

 void clientinstance::performtransfert(){
     printf("Account receiving amount :\n");
    int accr;
    scanf("%d", &accr);
    
    printf("Amount of the transaction:\n");
    float amou;
    scanf("%f", &amou);
    
    proxy.Transfert(bankcontext.address, "", accr, amou, &formatedresult);
      printf("%s\n", formatedresult);
 }
 
 void clientinstance::setbankcontextonclient(){
      printf("banks available:\n");
      
         printf("===== Bank %s, choose %d\n", banks[0].name, banks[0].bid);
               
    printf("Choose bank: \n");
    int banknewcontextid;
    scanf("%d", &banknewcontextid);
    
    this->bankcontext = banks[banknewcontextid];
    
    
    printf("context: %s, address %s\n", bankcontext.name, bankcontext.address);
    
    proxy.initAccounts(bankcontext.address, "", bankcontext.bid,  &formatedresult);
    printf("%s\n", formatedresult);
    }
 
//Shortcut state of the current account context.
void clientinstance::printstate(char* actionstr){
    printf("%s to current account %d, bank %s, enter amount:\n",actionstr, selectedaccountid , bankcontext.name);
}

void clientinstance::switchaccount(){
    //get the new account context id.
   printf("Account number:\n");
   scanf("%d", &selectedaccountid);
    
   
   proxy.SwitchAccount(bankcontext.address, "", selectedaccountid, &formatedresult);
   
    printf("%s\n", this->formatedresult);
}