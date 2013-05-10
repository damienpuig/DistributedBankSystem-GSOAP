/* 
 * File:   clientinstance.h
 * Author: damien
 *
 */

#ifndef CLIENTINSTANCE_H
#define	CLIENTINSTANCE_H

#include "soapBankProxy.h"
#include "bankmapper.h"

class clientinstance {
public:
    BankProxy proxy;
    bankmapper banks[2];
    bankmapper bankcontext;
    int selectedaccountid;
    char* formatedresult;
    
    clientinstance();
    clientinstance(const clientinstance& orig);
    virtual ~clientinstance();
    void init();
    
    void getbalance();
    
    void performdeposit();
    
    void performwithdraw();
    
    void performtransfert();
    
    void setbankcontextonclient();
    
    void switchaccount();

    //Menu asking for actions.
    void menu();
    
    private:
       void printstate(char*);
};

#endif	/* CLIENTINSTANCE_H */

