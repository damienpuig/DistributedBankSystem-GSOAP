/* 
 * File:   account.cpp
 * Author: damien
 * 
 * 
 */
#include <cstdlib>
#include <stdio.h>
#include "account.h"
#include "command.h"

account::account(){
}

void account::init(float inicialBalance){
    this->balance = inicialBalance;
}

account::account(const account& orig) {
}

account::~account() {
}


float account::add(float value){
    float resultadd;
    
    resultadd = this->balance + value;
    
   return resultadd;
}


float account::remove(float value){
    float resultremove;
    
    resultremove = this->balance - value;
    
   return resultremove;
}

char* account::notifybalanceorerror(){
    this->formatedresult = new char[255];
    
    if(this->errorinfo != NULL)
    {
       sprintf(formatedresult, this->errorinfo);
    }
    else
    {
      sprintf(formatedresult, "Account Balance = %f\n", balance);
    }
    
    return this->formatedresult;
}

char* account::notifybalance()
{
    this->formatedresult = new char[255];

    sprintf(formatedresult, "Account Balance = %f\n", balance);
    
    return this->formatedresult;
}

bool account::safer(float value, int action){
    
    this->errorinfo = NULL;
    float finalresult;
    
    if(action == addamount)
    {
        finalresult = add(value);
    }
    
    if(action == removeamount)
    {
        finalresult = remove(value);
    }
    
   bool validity = checker(finalresult); 
    

    if(validity == false)
    {
        this->errorinfo = "The current operation cannot be performed. The current account cannot be under 0";
    }
    
    return validity;
}

bool account::checker(float result){

    if(result < 0)
    {
        return false;
    }
    
    this->balance = result;
    return true;
}
