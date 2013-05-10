/* 
 * File:   accountmapper.h
 * Author: damien
 *
 * Created on November 29, 2012, 10:22 AM
 */

#ifndef ACCOUNTMAPPER_H
#define	ACCOUNTMAPPER_H

#include "soapAccountProxy.h"



class accountmapper {
public:
    accountmapper();
    accountmapper(const accountmapper& orig);
    virtual ~accountmapper();
    int accid;
    char* laststatus;
    char* address;
    float initialbalance;
    AccountProxy dedicatedInstance;
    void init(int, char*, float);
    bool add(float);
    bool remove(float);
    char* getbalance();
    char* getstatus();
};

#endif	/* ACCOUNTMAPPER_H */

