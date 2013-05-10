/* soapAccountService.cpp
   Generated by gSOAP 2.8.11 from service.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapAccountService.h"

AccountService::AccountService()
{	AccountService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

AccountService::AccountService(const struct soap &_soap) : soap(_soap)
{ }

AccountService::AccountService(soap_mode iomode)
{	AccountService_init(iomode, iomode);
}

AccountService::AccountService(soap_mode imode, soap_mode omode)
{	AccountService_init(imode, omode);
}

AccountService::~AccountService()
{ }

void AccountService::AccountService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns", "urn:Account", NULL, NULL},
	{"ns1", "urn:Bank", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
};

void AccountService::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void AccountService::reset()
{	destroy();
	soap_done(this);
	soap_init(this);
	AccountService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
AccountService *AccountService::copy()
{	AccountService *dup = SOAP_NEW_COPY(AccountService(*(struct soap*)this));
	return dup;
}
#endif

int AccountService::soap_close_socket()
{	return soap_closesock(this);
}

int AccountService::soap_force_close_socket()
{	return soap_force_closesock(this);
}

int AccountService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this, string, detailXML);
}

int AccountService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this, subcodeQName, string, detailXML);
}

int AccountService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this, string, detailXML);
}

int AccountService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this, subcodeQName, string, detailXML);
}

void AccountService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void AccountService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *AccountService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

void AccountService::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *AccountService::soap_header()
{	return this->header;
}

int AccountService::run(int port)
{	if (soap_valid_socket(this->master) || soap_valid_socket(bind(NULL, port, 100)))
	{	for (;;)
		{	if (!soap_valid_socket(accept()) || serve())
				return this->error;
			soap_destroy(this);
			soap_end(this);
		}
	}
	else
		return this->error;
	return SOAP_OK;
}

SOAP_SOCKET AccountService::bind(const char *host, int port, int backlog)
{	return soap_bind(this, host, port, backlog);
}

SOAP_SOCKET AccountService::accept()
{	return soap_accept(this);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int AccountService::ssl_accept()
{	return soap_ssl_accept(this);
}
#endif

int AccountService::serve()
{
#ifndef WITH_FASTCGI
	unsigned int k = this->max_keep_alive;
#endif
	do
	{

#ifndef WITH_FASTCGI
		if (this->max_keep_alive > 0 && !--k)
			this->keep_alive = 0;
#endif

		if (soap_begin_serve(this))
		{	if (this->error >= SOAP_STOP)
				continue;
			return this->error;
		}
		if (dispatch() || (this->fserveloop && this->fserveloop(this)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this);
#else
			return soap_send_fault(this);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(this);
		soap_end(this);
	} while (1);
#else
	} while (this->keep_alive);
#endif
	return SOAP_OK;
}

static int serve_ns__add(AccountService*);
static int serve_ns__remove(AccountService*);
static int serve_ns__init(AccountService*);
static int serve_ns__getbalance(AccountService*);
static int serve_ns__getstatus(AccountService*);

int AccountService::dispatch()
{	soap_peek_element(this);
	if (!soap_match_tag(this, this->tag, "ns:add"))
		return serve_ns__add(this);
	if (!soap_match_tag(this, this->tag, "ns:remove"))
		return serve_ns__remove(this);
	if (!soap_match_tag(this, this->tag, "ns:init"))
		return serve_ns__init(this);
	if (!soap_match_tag(this, this->tag, "ns:getbalance"))
		return serve_ns__getbalance(this);
	if (!soap_match_tag(this, this->tag, "ns:getstatus"))
		return serve_ns__getstatus(this);
	return this->error = SOAP_NO_METHOD;
}

static int serve_ns__add(AccountService *soap)
{	struct ns__add soap_tmp_ns__add;
	struct ns__addResponse soap_tmp_ns__addResponse;
	bool soap_tmp_bool;
	soap_default_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	soap_default_bool(soap, &soap_tmp_bool);
	soap_tmp_ns__addResponse.rresulta = &soap_tmp_bool;
	soap_default_ns__add(soap, &soap_tmp_ns__add);
	soap->encodingStyle = "";
	if (!soap_get_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->add(soap_tmp_ns__add.entry, soap_tmp_ns__addResponse.rresulta);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__remove(AccountService *soap)
{	struct ns__remove soap_tmp_ns__remove;
	struct ns__removeResponse soap_tmp_ns__removeResponse;
	bool soap_tmp_bool;
	soap_default_ns__removeResponse(soap, &soap_tmp_ns__removeResponse);
	soap_default_bool(soap, &soap_tmp_bool);
	soap_tmp_ns__removeResponse.rresultr = &soap_tmp_bool;
	soap_default_ns__remove(soap, &soap_tmp_ns__remove);
	soap->encodingStyle = "";
	if (!soap_get_ns__remove(soap, &soap_tmp_ns__remove, "ns:remove", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->remove(soap_tmp_ns__remove.entry, soap_tmp_ns__removeResponse.rresultr);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns__removeResponse(soap, &soap_tmp_ns__removeResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__removeResponse(soap, &soap_tmp_ns__removeResponse, "ns:removeResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__removeResponse(soap, &soap_tmp_ns__removeResponse, "ns:removeResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__init(AccountService *soap)
{	struct ns__init soap_tmp_ns__init;
	struct ns__initResponse soap_tmp_ns__initResponse;
	char * soap_tmp_string;
	soap_default_ns__initResponse(soap, &soap_tmp_ns__initResponse);
	soap_tmp_string = NULL;
	soap_tmp_ns__initResponse.rresulti = &soap_tmp_string;
	soap_default_ns__init(soap, &soap_tmp_ns__init);
	soap->encodingStyle = "";
	if (!soap_get_ns__init(soap, &soap_tmp_ns__init, "ns:init", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->init(soap_tmp_ns__init.balance, soap_tmp_ns__initResponse.rresulti);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns__initResponse(soap, &soap_tmp_ns__initResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__initResponse(soap, &soap_tmp_ns__initResponse, "ns:initResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__initResponse(soap, &soap_tmp_ns__initResponse, "ns:initResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__getbalance(AccountService *soap)
{	struct ns__getbalance soap_tmp_ns__getbalance;
	struct ns__getbalanceResponse soap_tmp_ns__getbalanceResponse;
	char * soap_tmp_string;
	soap_default_ns__getbalanceResponse(soap, &soap_tmp_ns__getbalanceResponse);
	soap_tmp_string = NULL;
	soap_tmp_ns__getbalanceResponse.rresultb = &soap_tmp_string;
	soap_default_ns__getbalance(soap, &soap_tmp_ns__getbalance);
	soap->encodingStyle = "";
	if (!soap_get_ns__getbalance(soap, &soap_tmp_ns__getbalance, "ns:getbalance", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->getbalance(soap_tmp_ns__getbalanceResponse.rresultb);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns__getbalanceResponse(soap, &soap_tmp_ns__getbalanceResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getbalanceResponse(soap, &soap_tmp_ns__getbalanceResponse, "ns:getbalanceResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getbalanceResponse(soap, &soap_tmp_ns__getbalanceResponse, "ns:getbalanceResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__getstatus(AccountService *soap)
{	struct ns__getstatus soap_tmp_ns__getstatus;
	struct ns__getstatusResponse soap_tmp_ns__getstatusResponse;
	char * soap_tmp_string;
	soap_default_ns__getstatusResponse(soap, &soap_tmp_ns__getstatusResponse);
	soap_tmp_string = NULL;
	soap_tmp_ns__getstatusResponse.rresultg = &soap_tmp_string;
	soap_default_ns__getstatus(soap, &soap_tmp_ns__getstatus);
	soap->encodingStyle = "";
	if (!soap_get_ns__getstatus(soap, &soap_tmp_ns__getstatus, "ns:getstatus", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->getstatus(soap_tmp_ns__getstatusResponse.rresultg);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns__getstatusResponse(soap, &soap_tmp_ns__getstatusResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getstatusResponse(soap, &soap_tmp_ns__getstatusResponse, "ns:getstatusResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getstatusResponse(soap, &soap_tmp_ns__getstatusResponse, "ns:getstatusResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */