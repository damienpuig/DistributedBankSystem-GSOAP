/* 
 * File:   accountmapper.cpp
 * Author: damien
 * 
 * Created on November 29, 2012, 10:22 AM
 */

#include "accountmapper.h"
#include "soapAccountProxy.h"

accountmapper::accountmapper() {
}

accountmapper::accountmapper(const accountmapper& orig) {
}

accountmapper::~accountmapper() {
}

void accountmapper::init(int idacc, char* addr, float bal){
    this->accid = idacc;
    this->address =  addr;
    this->initialbalance = bal;
    this->laststatus = "something went wrong";
    fprintf(stderr, "test address: %d\n", this->accid);
    fprintf(stderr, "test address: %s\n", this->address);
    fprintf(stderr, "test address: %f\n", this->initialbalance);
    dedicatedInstance.init(this->address, "", this->initialbalance, &laststatus);
    
    fprintf(stderr, "test message: %s\n", this->laststatus);
}

    bool accountmapper::add(float entrya){
        bool isaddvalida;
        dedicatedInstance.add(this->address, "", entrya, &isaddvalida);
        return isaddvalida;
    }
    
    bool accountmapper::remove(float entryr){
        bool isremovevalidr;
        dedicatedInstance.remove(this->address, "", entryr, &isremovevalidr);
        return isremovevalidr;
    }
    
   char* accountmapper::getbalance(){
        dedicatedInstance.getbalance(this->address, "", &laststatus);
        return this->laststatus;
    }
    
    char* accountmapper::getstatus(){
        dedicatedInstance.getstatus(this->address, "", &laststatus);
        return this->laststatus;
    }
