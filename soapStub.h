/* soapStub.h
   Generated by gSOAP 2.8.11 from service.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 20811
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ns__addResponse
#define SOAP_TYPE_ns__addResponse (11)
/* ns:addResponse */
struct ns__addResponse
{
public:
	bool *rresulta;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:boolean */
};
#endif

#ifndef SOAP_TYPE_ns__add
#define SOAP_TYPE_ns__add (12)
/* ns:add */
struct ns__add
{
public:
	float entry;	/* required element of type xsd:float */
};
#endif

#ifndef SOAP_TYPE_ns__removeResponse
#define SOAP_TYPE_ns__removeResponse (14)
/* ns:removeResponse */
struct ns__removeResponse
{
public:
	bool *rresultr;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:boolean */
};
#endif

#ifndef SOAP_TYPE_ns__remove
#define SOAP_TYPE_ns__remove (15)
/* ns:remove */
struct ns__remove
{
public:
	float entry;	/* required element of type xsd:float */
};
#endif

#ifndef SOAP_TYPE_ns__initResponse
#define SOAP_TYPE_ns__initResponse (18)
/* ns:initResponse */
struct ns__initResponse
{
public:
	char **rresulti;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__init
#define SOAP_TYPE_ns__init (19)
/* ns:init */
struct ns__init
{
public:
	float balance;	/* required element of type xsd:float */
};
#endif

#ifndef SOAP_TYPE_ns__getbalanceResponse
#define SOAP_TYPE_ns__getbalanceResponse (21)
/* ns:getbalanceResponse */
struct ns__getbalanceResponse
{
public:
	char **rresultb;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__getbalance
#define SOAP_TYPE_ns__getbalance (22)
/* ns:getbalance */
struct ns__getbalance
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ns__getstatusResponse
#define SOAP_TYPE_ns__getstatusResponse (24)
/* ns:getstatusResponse */
struct ns__getstatusResponse
{
public:
	char **rresultg;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns__getstatus
#define SOAP_TYPE_ns__getstatus (25)
/* ns:getstatus */
struct ns__getstatus
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ns1__DepositResponse
#define SOAP_TYPE_ns1__DepositResponse (27)
/* ns1:DepositResponse */
struct ns1__DepositResponse
{
public:
	char **rresult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__Deposit
#define SOAP_TYPE_ns1__Deposit (28)
/* ns1:Deposit */
struct ns1__Deposit
{
public:
	float entry;	/* required element of type xsd:float */
};
#endif

#ifndef SOAP_TYPE_ns1__WithdrawResponse
#define SOAP_TYPE_ns1__WithdrawResponse (30)
/* ns1:WithdrawResponse */
struct ns1__WithdrawResponse
{
public:
	char **rresult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__Withdraw
#define SOAP_TYPE_ns1__Withdraw (31)
/* ns1:Withdraw */
struct ns1__Withdraw
{
public:
	float entry;	/* required element of type xsd:float */
};
#endif

#ifndef SOAP_TYPE_ns1__initAccountsResponse
#define SOAP_TYPE_ns1__initAccountsResponse (33)
/* ns1:initAccountsResponse */
struct ns1__initAccountsResponse
{
public:
	char **rresult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__initAccounts
#define SOAP_TYPE_ns1__initAccounts (34)
/* ns1:initAccounts */
struct ns1__initAccounts
{
public:
	int bankid;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__TransfertResponse
#define SOAP_TYPE_ns1__TransfertResponse (36)
/* ns1:TransfertResponse */
struct ns1__TransfertResponse
{
public:
	char **rresult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__Transfert
#define SOAP_TYPE_ns1__Transfert (37)
/* ns1:Transfert */
struct ns1__Transfert
{
public:
	float entry;	/* required element of type xsd:float */
	int accountid;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__SwitchAccountResponse
#define SOAP_TYPE_ns1__SwitchAccountResponse (39)
/* ns1:SwitchAccountResponse */
struct ns1__SwitchAccountResponse
{
public:
	char **rresult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__SwitchAccount
#define SOAP_TYPE_ns1__SwitchAccount (40)
/* ns1:SwitchAccount */
struct ns1__SwitchAccount
{
public:
	int bankid;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__GetStateResponse
#define SOAP_TYPE_ns1__GetStateResponse (42)
/* ns1:GetStateResponse */
struct ns1__GetStateResponse
{
public:
	char **rresult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__GetState
#define SOAP_TYPE_ns1__GetState (43)
/* ns1:GetState */
struct ns1__GetState
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (44)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (45)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (47)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (50)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (51)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
