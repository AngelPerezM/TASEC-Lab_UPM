#ifndef GENERATED_ASN1SCC_Context_heater2_H
#define GENERATED_ASN1SCC_Context_heater2_H
/*
Code automatically generated by asn1scc tool
*/
#include "asn1crt.h"
#include "asn1crt_encoding.h"

#include "dataview-uniq.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- asn1SccContext_heater2 --------------------------------------------*/
typedef struct {
    asn1SccT_Int32 gpio_pin;

} asn1SccContext_heater2;

flag asn1SccContext_heater2_Equal(const asn1SccContext_heater2* pVal1, const asn1SccContext_heater2* pVal2);

void asn1SccContext_heater2_Initialize(asn1SccContext_heater2* pVal);

#define ERR_CONTEXT_HEATER2		8030  /**/
#define ERR_CONTEXT_HEATER2_GPIO_PIN_2		8023  /**/
flag asn1SccContext_heater2_IsConstraintValid(const asn1SccContext_heater2* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_CONTEXT_HEATER2		8031  /**/
#define ERR_UPER_ENCODE_CONTEXT_HEATER2_GPIO_PIN_2		8024  /**/
#define asn1SccContext_heater2_REQUIRED_BYTES_FOR_ENCODING       4 
#define asn1SccContext_heater2_REQUIRED_BITS_FOR_ENCODING        32

flag asn1SccContext_heater2_Encode(const asn1SccContext_heater2* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_CONTEXT_HEATER2		8032  /**/
#define ERR_UPER_DECODE_CONTEXT_HEATER2_GPIO_PIN_2		8025  /**/
flag asn1SccContext_heater2_Decode(asn1SccContext_heater2* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_CONTEXT_HEATER2		8033  /**/
#define ERR_ACN_ENCODE_CONTEXT_HEATER2_GPIO_PIN_2		8026  /**/
#define asn1SccContext_heater2_REQUIRED_BYTES_FOR_ACN_ENCODING       4 
#define asn1SccContext_heater2_REQUIRED_BITS_FOR_ACN_ENCODING        32

flag asn1SccContext_heater2_ACN_Encode(const asn1SccContext_heater2* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_CONTEXT_HEATER2		8034  /**/
#define ERR_ACN_DECODE_CONTEXT_HEATER2_GPIO_PIN_2		8027  /**/
flag asn1SccContext_heater2_ACN_Decode(asn1SccContext_heater2* pVal, BitStream* pBitStrm, int* pErrCode);

extern const asn1SccContext_heater2 heater2_ctxt; 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
