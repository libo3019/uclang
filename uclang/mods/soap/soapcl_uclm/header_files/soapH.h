/* soapH.h
   Generated by gSOAP 2.8.17r from calc.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
#ifndef WITH_NOIDREF

#ifdef __cplusplus
extern "C" {
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);

#ifdef __cplusplus
}
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif

#ifdef __cplusplus
extern "C" {
#endif
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);

#ifdef __cplusplus
}
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 const char ** SOAP_FMAC4 soap_faultcode(struct soap *soap);

SOAP_FMAC3 void * SOAP_FMAC4 soap_instantiate(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 int SOAP_FMAC4 soap_fdelete(struct soap_clist*);
SOAP_FMAC3 void* SOAP_FMAC4 soap_class_id_enter(struct soap*, const char*, void*, int, size_t, const char*, const char*);

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);

#ifndef soap_write_byte
#define soap_write_byte(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_byte(soap, data),0) || soap_put_byte(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);

#ifndef soap_read_byte
#define soap_read_byte(soap, data) ( soap_begin_recv(soap) || !soap_get_byte(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);

#ifndef soap_write_int
#define soap_write_int(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_int(soap, data),0) || soap_put_int(soap, data, "int", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);

#ifndef soap_read_int
#define soap_read_int(soap, data) ( soap_begin_recv(soap) || !soap_get_int(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_double
#define SOAP_TYPE_double (7)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_double(struct soap*, double *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_double(struct soap*, const char*, int, const double *, const char*);
SOAP_FMAC3 double * SOAP_FMAC4 soap_in_double(struct soap*, const char*, double *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_double(struct soap*, const double *, const char*, const char*);

#ifndef soap_write_double
#define soap_write_double(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_double(soap, data),0) || soap_put_double(soap, data, "double", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 double * SOAP_FMAC4 soap_get_double(struct soap*, double *, const char*, const char*);

#ifndef soap_read_double
#define soap_read_double(soap, data) ( soap_begin_recv(soap) || !soap_get_double(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (25)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Fault
#define soap_write_SOAP_ENV__Fault(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Fault(soap, data),0) || soap_put_SOAP_ENV__Fault(soap, data, "SOAP-ENV:Fault", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Fault
#define soap_read_SOAP_ENV__Fault(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Fault(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Fault * soap_new_SOAP_ENV__Fault(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Fault(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Fault * soap_new_req_SOAP_ENV__Fault(struct soap *soap) { struct SOAP_ENV__Fault *_p = soap_instantiate_SOAP_ENV__Fault(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Fault(soap, _p); } return _p; }

inline struct SOAP_ENV__Fault * soap_new_set_SOAP_ENV__Fault(struct soap *soap, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail) { struct SOAP_ENV__Fault *_p = soap_instantiate_SOAP_ENV__Fault(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Fault(soap, _p); _p->faultcode = faultcode; _p->faultstring = faultstring; _p->faultactor = faultactor; _p->detail = detail; _p->SOAP_ENV__Code = SOAP_ENV__Code; _p->SOAP_ENV__Reason = SOAP_ENV__Reason; _p->SOAP_ENV__Node = SOAP_ENV__Node; _p->SOAP_ENV__Role = SOAP_ENV__Role; _p->SOAP_ENV__Detail = SOAP_ENV__Detail; } return _p; }

inline void soap_delete_SOAP_ENV__Fault(struct soap *soap, struct SOAP_ENV__Fault *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Fault(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (24)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Reason
#define soap_write_SOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Reason(soap, data),0) || soap_put_SOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Reason
#define soap_read_SOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Reason * soap_new_SOAP_ENV__Reason(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Reason(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Reason * soap_new_req_SOAP_ENV__Reason(struct soap *soap) { struct SOAP_ENV__Reason *_p = soap_instantiate_SOAP_ENV__Reason(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Reason(soap, _p); } return _p; }

inline struct SOAP_ENV__Reason * soap_new_set_SOAP_ENV__Reason(struct soap *soap, char *SOAP_ENV__Text) { struct SOAP_ENV__Reason *_p = soap_instantiate_SOAP_ENV__Reason(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Reason(soap, _p); _p->SOAP_ENV__Text = SOAP_ENV__Text; } return _p; }

inline void soap_delete_SOAP_ENV__Reason(struct soap *soap, struct SOAP_ENV__Reason *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Reason(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (21)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Detail
#define soap_write_SOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Detail(soap, data),0) || soap_put_SOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Detail
#define soap_read_SOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Detail * soap_new_SOAP_ENV__Detail(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Detail(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Detail * soap_new_req_SOAP_ENV__Detail(struct soap *soap, int __type, void *fault) { struct SOAP_ENV__Detail *_p = soap_instantiate_SOAP_ENV__Detail(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Detail(soap, _p); _p->__type = __type; _p->fault = fault; } return _p; }

inline struct SOAP_ENV__Detail * soap_new_set_SOAP_ENV__Detail(struct soap *soap, char *__any, int __type, void *fault) { struct SOAP_ENV__Detail *_p = soap_instantiate_SOAP_ENV__Detail(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Detail(soap, _p); _p->__any = __any; _p->__type = __type; _p->fault = fault; } return _p; }

inline void soap_delete_SOAP_ENV__Detail(struct soap *soap, struct SOAP_ENV__Detail *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Detail(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Code
#define soap_write_SOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Code(soap, data),0) || soap_put_SOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Code
#define soap_read_SOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Code * soap_new_SOAP_ENV__Code(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Code(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Code * soap_new_req_SOAP_ENV__Code(struct soap *soap) { struct SOAP_ENV__Code *_p = soap_instantiate_SOAP_ENV__Code(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Code(soap, _p); } return _p; }

inline struct SOAP_ENV__Code * soap_new_set_SOAP_ENV__Code(struct soap *soap, char *SOAP_ENV__Value, struct SOAP_ENV__Code *SOAP_ENV__Subcode) { struct SOAP_ENV__Code *_p = soap_instantiate_SOAP_ENV__Code(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Code(soap, _p); _p->SOAP_ENV__Value = SOAP_ENV__Value; _p->SOAP_ENV__Subcode = SOAP_ENV__Subcode; } return _p; }

inline void soap_delete_SOAP_ENV__Code(struct soap *soap, struct SOAP_ENV__Code *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Code(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (18)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_write_SOAP_ENV__Header
#define soap_write_SOAP_ENV__Header(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Header(soap, data),0) || soap_put_SOAP_ENV__Header(soap, data, "SOAP-ENV:Header", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Header
#define soap_read_SOAP_ENV__Header(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Header(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);

inline struct SOAP_ENV__Header * soap_new_SOAP_ENV__Header(struct soap *soap, int n = -1) { return soap_instantiate_SOAP_ENV__Header(soap, n, NULL, NULL, NULL); }

inline struct SOAP_ENV__Header * soap_new_req_SOAP_ENV__Header(struct soap *soap) { struct SOAP_ENV__Header *_p = soap_instantiate_SOAP_ENV__Header(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Header(soap, _p); } return _p; }

inline struct SOAP_ENV__Header * soap_new_set_SOAP_ENV__Header(struct soap *soap) { struct SOAP_ENV__Header *_p = soap_instantiate_SOAP_ENV__Header(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_SOAP_ENV__Header(soap, _p); } return _p; }

inline void soap_delete_SOAP_ENV__Header(struct soap *soap, struct SOAP_ENV__Header *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Header(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef SOAP_TYPE_ns__sqrt
#define SOAP_TYPE_ns__sqrt (17)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__sqrt(struct soap*, struct ns__sqrt *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__sqrt(struct soap*, const struct ns__sqrt *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__sqrt(struct soap*, const char*, int, const struct ns__sqrt *, const char*);
SOAP_FMAC3 struct ns__sqrt * SOAP_FMAC4 soap_in_ns__sqrt(struct soap*, const char*, struct ns__sqrt *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__sqrt(struct soap*, const struct ns__sqrt *, const char*, const char*);

#ifndef soap_write_ns__sqrt
#define soap_write_ns__sqrt(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns__sqrt(soap, data),0) || soap_put_ns__sqrt(soap, data, "ns:sqrt", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns__sqrt * SOAP_FMAC4 soap_get_ns__sqrt(struct soap*, struct ns__sqrt *, const char*, const char*);

#ifndef soap_read_ns__sqrt
#define soap_read_ns__sqrt(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__sqrt(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct ns__sqrt * SOAP_FMAC2 soap_instantiate_ns__sqrt(struct soap*, int, const char*, const char*, size_t*);

inline struct ns__sqrt * soap_new_ns__sqrt(struct soap *soap, int n = -1) { return soap_instantiate_ns__sqrt(soap, n, NULL, NULL, NULL); }

inline struct ns__sqrt * soap_new_req_ns__sqrt(struct soap *soap, double a) { struct ns__sqrt *_p = soap_instantiate_ns__sqrt(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__sqrt(soap, _p); _p->a = a; } return _p; }

inline struct ns__sqrt * soap_new_set_ns__sqrt(struct soap *soap, double a) { struct ns__sqrt *_p = soap_instantiate_ns__sqrt(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__sqrt(soap, _p); _p->a = a; } return _p; }

inline void soap_delete_ns__sqrt(struct soap *soap, struct ns__sqrt *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__sqrt(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__sqrtResponse
#define SOAP_TYPE_ns__sqrtResponse (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__sqrtResponse(struct soap*, struct ns__sqrtResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__sqrtResponse(struct soap*, const struct ns__sqrtResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__sqrtResponse(struct soap*, const char*, int, const struct ns__sqrtResponse *, const char*);
SOAP_FMAC3 struct ns__sqrtResponse * SOAP_FMAC4 soap_in_ns__sqrtResponse(struct soap*, const char*, struct ns__sqrtResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__sqrtResponse(struct soap*, const struct ns__sqrtResponse *, const char*, const char*);

#ifndef soap_write_ns__sqrtResponse
#define soap_write_ns__sqrtResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns__sqrtResponse(soap, data),0) || soap_put_ns__sqrtResponse(soap, data, "ns:sqrtResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns__sqrtResponse * SOAP_FMAC4 soap_get_ns__sqrtResponse(struct soap*, struct ns__sqrtResponse *, const char*, const char*);

#ifndef soap_read_ns__sqrtResponse
#define soap_read_ns__sqrtResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__sqrtResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct ns__sqrtResponse * SOAP_FMAC2 soap_instantiate_ns__sqrtResponse(struct soap*, int, const char*, const char*, size_t*);

inline struct ns__sqrtResponse * soap_new_ns__sqrtResponse(struct soap *soap, int n = -1) { return soap_instantiate_ns__sqrtResponse(soap, n, NULL, NULL, NULL); }

inline struct ns__sqrtResponse * soap_new_req_ns__sqrtResponse(struct soap *soap) { struct ns__sqrtResponse *_p = soap_instantiate_ns__sqrtResponse(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__sqrtResponse(soap, _p); } return _p; }

inline struct ns__sqrtResponse * soap_new_set_ns__sqrtResponse(struct soap *soap, double *result) { struct ns__sqrtResponse *_p = soap_instantiate_ns__sqrtResponse(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__sqrtResponse(soap, _p); _p->result = result; } return _p; }

inline void soap_delete_ns__sqrtResponse(struct soap *soap, struct ns__sqrtResponse *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__sqrtResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__sub
#define SOAP_TYPE_ns__sub (14)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__sub(struct soap*, struct ns__sub *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__sub(struct soap*, const struct ns__sub *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__sub(struct soap*, const char*, int, const struct ns__sub *, const char*);
SOAP_FMAC3 struct ns__sub * SOAP_FMAC4 soap_in_ns__sub(struct soap*, const char*, struct ns__sub *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__sub(struct soap*, const struct ns__sub *, const char*, const char*);

#ifndef soap_write_ns__sub
#define soap_write_ns__sub(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns__sub(soap, data),0) || soap_put_ns__sub(soap, data, "ns:sub", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns__sub * SOAP_FMAC4 soap_get_ns__sub(struct soap*, struct ns__sub *, const char*, const char*);

#ifndef soap_read_ns__sub
#define soap_read_ns__sub(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__sub(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct ns__sub * SOAP_FMAC2 soap_instantiate_ns__sub(struct soap*, int, const char*, const char*, size_t*);

inline struct ns__sub * soap_new_ns__sub(struct soap *soap, int n = -1) { return soap_instantiate_ns__sub(soap, n, NULL, NULL, NULL); }

inline struct ns__sub * soap_new_req_ns__sub(struct soap *soap, double a, double b) { struct ns__sub *_p = soap_instantiate_ns__sub(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__sub(soap, _p); _p->a = a; _p->b = b; } return _p; }

inline struct ns__sub * soap_new_set_ns__sub(struct soap *soap, double a, double b) { struct ns__sub *_p = soap_instantiate_ns__sub(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__sub(soap, _p); _p->a = a; _p->b = b; } return _p; }

inline void soap_delete_ns__sub(struct soap *soap, struct ns__sub *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__sub(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__subResponse
#define SOAP_TYPE_ns__subResponse (13)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__subResponse(struct soap*, struct ns__subResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__subResponse(struct soap*, const struct ns__subResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__subResponse(struct soap*, const char*, int, const struct ns__subResponse *, const char*);
SOAP_FMAC3 struct ns__subResponse * SOAP_FMAC4 soap_in_ns__subResponse(struct soap*, const char*, struct ns__subResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__subResponse(struct soap*, const struct ns__subResponse *, const char*, const char*);

#ifndef soap_write_ns__subResponse
#define soap_write_ns__subResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns__subResponse(soap, data),0) || soap_put_ns__subResponse(soap, data, "ns:subResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns__subResponse * SOAP_FMAC4 soap_get_ns__subResponse(struct soap*, struct ns__subResponse *, const char*, const char*);

#ifndef soap_read_ns__subResponse
#define soap_read_ns__subResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__subResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct ns__subResponse * SOAP_FMAC2 soap_instantiate_ns__subResponse(struct soap*, int, const char*, const char*, size_t*);

inline struct ns__subResponse * soap_new_ns__subResponse(struct soap *soap, int n = -1) { return soap_instantiate_ns__subResponse(soap, n, NULL, NULL, NULL); }

inline struct ns__subResponse * soap_new_req_ns__subResponse(struct soap *soap) { struct ns__subResponse *_p = soap_instantiate_ns__subResponse(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__subResponse(soap, _p); } return _p; }

inline struct ns__subResponse * soap_new_set_ns__subResponse(struct soap *soap, double *result) { struct ns__subResponse *_p = soap_instantiate_ns__subResponse(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__subResponse(soap, _p); _p->result = result; } return _p; }

inline void soap_delete_ns__subResponse(struct soap *soap, struct ns__subResponse *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__subResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__add
#define SOAP_TYPE_ns__add (11)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__add(struct soap*, struct ns__add *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__add(struct soap*, const struct ns__add *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__add(struct soap*, const char*, int, const struct ns__add *, const char*);
SOAP_FMAC3 struct ns__add * SOAP_FMAC4 soap_in_ns__add(struct soap*, const char*, struct ns__add *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__add(struct soap*, const struct ns__add *, const char*, const char*);

#ifndef soap_write_ns__add
#define soap_write_ns__add(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns__add(soap, data),0) || soap_put_ns__add(soap, data, "ns:add", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns__add * SOAP_FMAC4 soap_get_ns__add(struct soap*, struct ns__add *, const char*, const char*);

#ifndef soap_read_ns__add
#define soap_read_ns__add(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__add(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct ns__add * SOAP_FMAC2 soap_instantiate_ns__add(struct soap*, int, const char*, const char*, size_t*);

inline struct ns__add * soap_new_ns__add(struct soap *soap, int n = -1) { return soap_instantiate_ns__add(soap, n, NULL, NULL, NULL); }

inline struct ns__add * soap_new_req_ns__add(struct soap *soap, double a, double b) { struct ns__add *_p = soap_instantiate_ns__add(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__add(soap, _p); _p->a = a; _p->b = b; } return _p; }

inline struct ns__add * soap_new_set_ns__add(struct soap *soap, double a, double b) { struct ns__add *_p = soap_instantiate_ns__add(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__add(soap, _p); _p->a = a; _p->b = b; } return _p; }

inline void soap_delete_ns__add(struct soap *soap, struct ns__add *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__add(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__addResponse
#define SOAP_TYPE_ns__addResponse (10)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__addResponse(struct soap*, struct ns__addResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__addResponse(struct soap*, const struct ns__addResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__addResponse(struct soap*, const char*, int, const struct ns__addResponse *, const char*);
SOAP_FMAC3 struct ns__addResponse * SOAP_FMAC4 soap_in_ns__addResponse(struct soap*, const char*, struct ns__addResponse *, const char*);

SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__addResponse(struct soap*, const struct ns__addResponse *, const char*, const char*);

#ifndef soap_write_ns__addResponse
#define soap_write_ns__addResponse(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_ns__addResponse(soap, data),0) || soap_put_ns__addResponse(soap, data, "ns:addResponse", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct ns__addResponse * SOAP_FMAC4 soap_get_ns__addResponse(struct soap*, struct ns__addResponse *, const char*, const char*);

#ifndef soap_read_ns__addResponse
#define soap_read_ns__addResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__addResponse(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif

SOAP_FMAC1 struct ns__addResponse * SOAP_FMAC2 soap_instantiate_ns__addResponse(struct soap*, int, const char*, const char*, size_t*);

inline struct ns__addResponse * soap_new_ns__addResponse(struct soap *soap, int n = -1) { return soap_instantiate_ns__addResponse(soap, n, NULL, NULL, NULL); }

inline struct ns__addResponse * soap_new_req_ns__addResponse(struct soap *soap) { struct ns__addResponse *_p = soap_instantiate_ns__addResponse(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__addResponse(soap, _p); } return _p; }

inline struct ns__addResponse * soap_new_set_ns__addResponse(struct soap *soap, double *result) { struct ns__addResponse *_p = soap_instantiate_ns__addResponse(soap, -1, NULL, NULL, NULL); if (_p) { soap_default_ns__addResponse(soap, _p); _p->result = result; } return _p; }

inline void soap_delete_ns__addResponse(struct soap *soap, struct ns__addResponse *p) { soap_delete(soap, p); }

SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__addResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (27)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Reason
#define soap_write_PointerToSOAP_ENV__Reason(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Reason(soap, data),0) || soap_put_PointerToSOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Reason
#define soap_read_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (26)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Detail
#define soap_write_PointerToSOAP_ENV__Detail(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Detail(soap, data),0) || soap_put_PointerToSOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Detail
#define soap_read_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (20)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Code
#define soap_write_PointerToSOAP_ENV__Code(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Code(soap, data),0) || soap_put_PointerToSOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Code
#define soap_read_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

#ifndef SOAP_TYPE_PointerTodouble
#define SOAP_TYPE_PointerTodouble (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTodouble(struct soap*, double *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTodouble(struct soap*, const char *, int, double *const*, const char *);
SOAP_FMAC3 double ** SOAP_FMAC4 soap_in_PointerTodouble(struct soap*, const char*, double **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTodouble(struct soap*, double *const*, const char*, const char*);

#ifndef soap_write_PointerTodouble
#define soap_write_PointerTodouble(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_PointerTodouble(soap, data),0) || soap_put_PointerTodouble(soap, data, "double", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 double ** SOAP_FMAC4 soap_get_PointerTodouble(struct soap*, double **, const char*, const char*);

#ifndef soap_read_PointerTodouble
#define soap_read_PointerTodouble(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTodouble(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif

#define soap_default__QName(soap, a) soap_default_string(soap, a)

SOAP_FMAC3 void SOAP_FMAC4 soap_serialize__QName(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write__QName
#define soap_write__QName(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize__QName(soap, data),0) || soap_put__QName(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);

#ifndef soap_read__QName
#define soap_read__QName(soap, data) ( soap_begin_recv(soap) || !soap_get__QName(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_write_string
#define soap_write_string(soap, data) ( soap_free_temp(soap), soap_begin_send(soap) || (soap_serialize_string(soap, data),0) || soap_put_string(soap, data, "byte", NULL) || soap_end_send(soap), (soap)->error )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);

#ifndef soap_read_string
#define soap_read_string(soap, data) ( soap_begin_recv(soap) || !soap_get_string(soap, data, NULL, NULL) || soap_end_recv(soap), (soap)->error )
#endif


#endif

/* End of soapH.h */
