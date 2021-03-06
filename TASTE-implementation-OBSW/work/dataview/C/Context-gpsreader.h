#ifndef GENERATED_ASN1SCC_Context_gpsreader_H
#define GENERATED_ASN1SCC_Context_gpsreader_H
/*
Code automatically generated by asn1scc tool
*/
#include "asn1crt.h"
#include "asn1crt_encoding.h"

#include "dataview-uniq.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- asn1SccContext_gpsreader --------------------------------------------*/
typedef struct {
    asn1SccT_UInt32 max_retries;
    asn1SccT_UInt32 waiting_time_per_retry_us;

} asn1SccContext_gpsreader;

flag asn1SccContext_gpsreader_Equal(const asn1SccContext_gpsreader* pVal1, const asn1SccContext_gpsreader* pVal2);

void asn1SccContext_gpsreader_Initialize(asn1SccContext_gpsreader* pVal);

#define ERR_CONTEXT_GPSREADER		8534  /**/
#define ERR_CONTEXT_GPSREADER_MAX_RETRIES_2		8513  /**/
#define ERR_CONTEXT_GPSREADER_WAITING_TIME_PER_RETRY_US_2		8527  /**/
flag asn1SccContext_gpsreader_IsConstraintValid(const asn1SccContext_gpsreader* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_CONTEXT_GPSREADER		8535  /**/
#define ERR_UPER_ENCODE_CONTEXT_GPSREADER_MAX_RETRIES_2		8514  /**/
#define ERR_UPER_ENCODE_CONTEXT_GPSREADER_WAITING_TIME_PER_RETRY_US_2		8528  /**/
#define asn1SccContext_gpsreader_REQUIRED_BYTES_FOR_ENCODING       8 
#define asn1SccContext_gpsreader_REQUIRED_BITS_FOR_ENCODING        64

flag asn1SccContext_gpsreader_Encode(const asn1SccContext_gpsreader* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_CONTEXT_GPSREADER		8536  /**/
#define ERR_UPER_DECODE_CONTEXT_GPSREADER_MAX_RETRIES_2		8515  /**/
#define ERR_UPER_DECODE_CONTEXT_GPSREADER_WAITING_TIME_PER_RETRY_US_2		8529  /**/
flag asn1SccContext_gpsreader_Decode(asn1SccContext_gpsreader* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_CONTEXT_GPSREADER		8537  /**/
#define ERR_ACN_ENCODE_CONTEXT_GPSREADER_MAX_RETRIES_2		8516  /**/
#define ERR_ACN_ENCODE_CONTEXT_GPSREADER_WAITING_TIME_PER_RETRY_US_2		8530  /**/
#define asn1SccContext_gpsreader_REQUIRED_BYTES_FOR_ACN_ENCODING       8 
#define asn1SccContext_gpsreader_REQUIRED_BITS_FOR_ACN_ENCODING        64

flag asn1SccContext_gpsreader_ACN_Encode(const asn1SccContext_gpsreader* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_CONTEXT_GPSREADER		8538  /**/
#define ERR_ACN_DECODE_CONTEXT_GPSREADER_MAX_RETRIES_2		8517  /**/
#define ERR_ACN_DECODE_CONTEXT_GPSREADER_WAITING_TIME_PER_RETRY_US_2		8531  /**/
flag asn1SccContext_gpsreader_ACN_Decode(asn1SccContext_gpsreader* pVal, BitStream* pBitStrm, int* pErrCode);

extern const asn1SccContext_gpsreader gpsreader_ctxt; 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
