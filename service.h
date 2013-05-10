//gsoap ns service name: Account
//gsoap ns service style:  rpc
//gsoap ns service encoding: encoded
//gsoap ns schema namespace: urn:Account

//gsoap ns1 service name: Bank
//gsoap ns1 service style:  rpc
//gsoap ns1 service encoding: encoded
//gsoap ns1 schema namespace: urn:Bank




int ns__add(float entry,  bool* rresulta);
int ns__remove(float entry, bool* rresultr);
int ns__init(float balance, char** rresulti);
int ns__getbalance(char** rresultb);
int ns__getstatus(char** rresultg);




int ns1__Deposit(float entry,  char** rresult);
int ns1__Withdraw(float entry, char** rresult);
int ns1__initAccounts(int bankid, char** rresult);
int ns1__Transfert(float entry, int accountid, char** rresult);
int ns1__SwitchAccount(int bankid, char** rresult);
int ns1__GetState(char** rresult);