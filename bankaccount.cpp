/* 
 * File:   bankaccount.cpp
 * Author: damien
 *
 * Created on November 27, 2012, 3:10 PM
 */

#include <cstdlib>
#include "soapAccountService.h"
#include "soapH.h"
#include "Account.nsmap"
#include "soapAccountProxy.h"
#include <pthread.h>
#include "account.h"
#include "command.h"
account context;


int main(int argc, char** argv) {
    
    AccountService accountService;
    int port = atoi(argv[1]) ;
        
   int m, s; // master and slave sockets
   m = accountService.bind(NULL, port, 100);
   
      fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
      for (int i = 1; ; i++)
      {
         s = accountService.accept();
         
         fprintf(stderr, "%d: accepted connection from IP=%d.%d.%d.%d socket=%d\n", i,
            (accountService.ip >> 24)&0xFF, (accountService.ip >> 16)&0xFF, (accountService.ip >> 8)&0xFF, accountService.ip&0xFF, s);
         if (accountService.serve() != SOAP_OK) // process RPC request
             accountService.soap_print_fault(stderr);
         
         fprintf(stderr, "request served\n");
         
         accountService.destroy();// clean up class instances
         accountService.soap_close_socket();
      }
   }

int AccountService::add(float entry, bool *rresulta){
    *rresulta =  context.safer(entry, addamount);
 fprintf(stderr, "add served\n");
    return SOAP_OK;
}

int AccountService::remove(float entry, bool *rresultr){
    *rresultr = context.safer(entry, removeamount);
    fprintf(stderr, "remove served\n");
    return SOAP_OK;
}


int AccountService::init(float balance, char **rresulti){
    context.init(balance);
    *rresulti = context.notifybalanceorerror(); 
    fprintf(stderr, "init served %f\n", context.balance);
    return SOAP_OK;
}

int AccountService::getbalance(char **rresultb){
    *rresultb = context.notifybalance(); 
    fprintf(stderr, "getbalance served %f\n", context.balance);
    return SOAP_OK;
}

int AccountService::getstatus(char **rresultg){
    *rresultg = context.notifybalanceorerror();   
    fprintf(stderr, "getstatus served\n");
    return SOAP_OK;
}
