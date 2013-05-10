/* 
 * File:   headoffice.cpp
 * Author: damien
 *
 * Created on November 29, 2012, 10:07 AM
 */

#include <cstdlib>
#include "soapBankService.h"
#include "soapH.h"
#include "Bank.nsmap"
#include "soapBankProxy.h"
#include "accountmapper.h"
#include "config.h"
#include "account.h"
#include <pthread.h>

using namespace std;
accountmapper context;
/*
 * 
 */
int main(int argc, char** argv) {
    
    BankService bankService;
    int port = atoi(argv[1]) ;
        
   int m, s; // master and slave sockets
   m = bankService.bind(NULL, port, 100);
   
      fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
      for (int i = 1; ; i++)
      {
         s = bankService.accept();
         
         if (s < 0)
         {
            break;
         }
         
         fprintf(stderr, "%d: accepted connection from IP=%d.%d.%d.%d socket=%d\n", i,
            (bankService.ip >> 24)&0xFF, (bankService.ip >> 16)&0xFF, (bankService.ip >> 8)&0xFF, bankService.ip&0xFF, s);
         if (bankService.serve() != SOAP_OK) // process RPC request
             bankService.soap_print_fault(stderr);
         
         fprintf(stderr, "request served\n");
         
         bankService.destroy();// clean up class instances
         bankService.soap_close_socket();
      }
   }

int BankService::Deposit(float entry, char** rresult){
     context.add(entry);
     *rresult = context.getstatus();
    return SOAP_OK;
}

int BankService::Withdraw(float entry, char** rresult){
     context.remove(entry);
     *rresult = context.getstatus();
    return SOAP_OK;
}

int BankService::SwitchAccount(int bankid, char** rresult){
    
    if(bankid == 0)
    {
         context.init(0, accountntocall0, 200.00);
         fprintf(stderr, "test address: %s\n",accountntocall0);
    }
    else if (bankid == 1)
    {
         context.init(0, accountntocall1, 300.00);
         fprintf(stderr, "test address: %s\n",accountntocall1);
    }
    else if (bankid == 2)
    {
        context.init(0, accountntocall2, 300.00);
        fprintf(stderr, "test address: %s\n",accountntocall2);
    }
    
   *rresult = context.getstatus();
    return SOAP_OK;
}

int BankService::GetState(char** rresult){
    *rresult = context.getbalance();
    return SOAP_OK;
}

int BankService::Transfert(float entry, int accountid, char** rresult){
    char* retour;
   bool validity = context.remove(entry);
   retour = context.getstatus();
   
   if(validity)
   {
      validity = context.add(entry);
      
      if(validity)
          retour = context.getstatus();   
   }
   
   *rresult = retour;
   
    return SOAP_OK;
}

int BankService::initAccounts(int bankid, char** rresult){
           fprintf(stderr, "BANK SERVER: Returning account\n");
            fprintf(stderr, "bank : %d \n", bankid);
           
  if(bankid == 0)
    {
         context.init(0, accountntocall0, 200.00);
         fprintf(stderr, "test address: %s\n",accountntocall0);
    }
    else if (bankid == 1)
    {
         context.init(0, accountntocall1, 300.00);
         fprintf(stderr, "test address: %s\n",accountntocall1);
    }
    else if (bankid == 2)
    {
        context.init(0, accountntocall2, 300.00);
        fprintf(stderr, "test address: %s\n",accountntocall2);
    }

             fprintf(stderr, "context :%s\n", context.address);
             fprintf(stderr, "account :%d\n", context.accid);
             fprintf(stderr, "account :%s\n", context.laststatus);

     *rresult = context.laststatus;
             
    return SOAP_OK;
}
