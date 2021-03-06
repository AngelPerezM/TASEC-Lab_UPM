#ifndef GENERATED_ASN1SCC_Context_heater1_H
#define GENERATED_ASN1SCC_Context_heater1_H
/*
Code automatically generated by asn1scc tool
*/
#include "asn1crt.h"
#include "asn1crt_encoding.h"

#include "dataview-uniq.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- asn1SccContext_heater1 --------------------------------------------*/
typedef struct {
    asn1SccT_Int32 gpio_pin;

} asn1SccContext_heater1;

flag asn1SccContext_heater1_Equal(const asn1SccContext_heater1* pVal1, const asn1SccContext_heater1* pVal2);

void asn1SccContext_heater1_Initialize(asn1SccContext_heater1* pVal);

#define ERR_CONTEXT_HEATER1		8079  /**/
#define ERR_CONTEXT_HEATER1_GPIO_PIN_2		8072  /**/
flag asn1SccContext_heater1_IsConstraintValid(const asn1SccContext_heater1* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_CONTEXT_HEATER1		8080  /**/
#define ERR_UPER_ENCODE_CONTEXT_HEATER1_GPIO_PIN_2		8073  /**/
#define asn1SccContext_heater1_REQUIRED_BYTES_FOR_ENCODING       4 
#define asn1SccContext_heater1_REQUIRED_BITS_FOR_ENCODING        32

flag asn1SccContext_heater1_Encode(const asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_CONTEXT_HEATER1		8081  /**/
#define ERR_UPER_DECODE_CONTEXT_HEATER1_GPIO_PIN_2		8074  /**/
flag asn1SccContext_heater1_Decode(asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_CONTEXT_HEATER1		8082  /**/
#define ERR_ACN_ENCODE_CONTEXT_HEATER1_GPIO_PIN_2		8075  /**/
#define asn1SccContext_heater1_REQUIRED_BYTES_FOR_ACN_ENCODING       4 
#define asn1SccContext_heater1_REQUIRED_BITS_FOR_ACN_ENCODING        32

flag asn1SccContext_heater1_ACN_Encode(const asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_CONTEXT_HEATER1		8083  /**/
#define ERR_ACN_DECODE_CONTEXT_HEATER1_GPIO_PIN_2		8076  /**/
flag asn1SccContext_heater1_ACN_Decode(asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode);

extern const asn1SccContext_heater1 heater1_ctxt; 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
