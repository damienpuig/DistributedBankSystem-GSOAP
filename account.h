/* 
 * File:   account.h
 * Author: damien
 *
 * 
 */

#ifndef ACCOUNT_H
#define	ACCOUNT_H

class account {
public:
    float balance;
    char* errorinfo;
    
    account();
    account(const account& orig);
    
    void init(float);
    virtual ~account();
    
    float add(float);
    float remove(float);
    
    char*  notifybalanceorerror();
    char*  notifybalance();
    
    bool safer(float, int);
    
private:
    
    bool checker(float);
    char* formatedresult;
};

#endif	/* ACCOUNT_H */

