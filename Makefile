GSOAP=soapcpp2
SOAPH=stdsoap2.h
SOAPC=stdsoap2.c
SOAPCPP=stdsoap2.cpp
CC=gcc
CPP=g++
LIBS=
COFLAGS=-O2
CWFLAGS=-Wall
CIFLAGS=-I../..
CMFLAGS=
CFLAGS= $(CWFLAGS) $(COFLAGS) $(CIFLAGS) $(CMFLAGS)
all:		client bankserver accountserver
	
client:	service.h main.cpp $(SOAPH) $(SOAPCPP)
		$(GSOAP) -i service.h
		$(CPP) $(CFLAGS) -o client main.cpp bankmapper.cpp clientinstance.cpp  soapC.cpp soapBankProxy.cpp $(SOAPCPP) $(LIBS)

accountserver:	service.h bankaccount.cpp $(SOAPH) $(SOAPCPP)
		$(GSOAP) -i service.h
		$(CPP) $(CFLAGS) -o bankaccount bankaccount.cpp account.cpp soapC.cpp soapAccountService.cpp  $(SOAPCPP) -lm $(LIBS) -lpthread

bankserver:	service.h headoffice.cpp $(SOAPH) $(SOAPCPP)
		$(GSOAP) -i service.h
		$(CPP) $(CFLAGS) -o headoffice headoffice.cpp accountmapper.cpp soapC.cpp soapAccountProxy.cpp soapBankService.cpp  $(SOAPCPP) -lm $(LIBS) -lpthread
	
clean:
		rm -f client bankaccount headoffice
	