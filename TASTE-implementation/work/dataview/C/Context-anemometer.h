#ifndef GENERATED_ASN1SCC_Context_anemometer_H
#define GENERATED_ASN1SCC_Context_anemometer_H
/*
Code automatically generated by asn1scc tool
*/
#include "asn1crt.h"
#include "asn1crt_encoding.h"

#include "dataview-uniq.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- asn1SccContext_anemometer --------------------------------------------*/
typedef struct {
    asn1SccT_UInt32 gpio_pin;

} asn1SccContext_anemometer;

flag asn1SccContext_anemometer_Equal(const asn1SccContext_anemometer* pVal1, const asn1SccContext_anemometer* pVal2);

void asn1SccContext_anemometer_Initialize(asn1SccContext_anemometer* pVal);

#define ERR_CONTEXT_ANEMOMETER		8485  /**/
#define ERR_CONTEXT_ANEMOMETER_GPIO_PIN_2		8478  /**/
flag asn1SccContext_anemometer_IsConstraintValid(const asn1SccContext_anemometer* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_CONTEXT_ANEMOMETER		8486  /**/
#define ERR_UPER_ENCODE_CONTEXT_ANEMOMETER_GPIO_PIN_2		8479  /**/
#define asn1SccContext_anemometer_REQUIRED_BYTES_FOR_ENCODING       4 
#define asn1SccContext_anemometer_REQUIRED_BITS_FOR_ENCODING        32

flag asn1SccContext_anemometer_Encode(const asn1SccContext_anemometer* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_CONTEXT_ANEMOMETER		8487  /**/
#define ERR_UPER_DECODE_CONTEXT_ANEMOMETER_GPIO_PIN_2		8480  /**/
flag asn1SccContext_anemometer_Decode(asn1SccContext_anemometer* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_CONTEXT_ANEMOMETER		8488  /**/
#define ERR_ACN_ENCODE_CONTEXT_ANEMOMETER_GPIO_PIN_2		8481  /**/
#define asn1SccContext_anemometer_REQUIRED_BYTES_FOR_ACN_ENCODING       4 
#define asn1SccContext_anemometer_REQUIRED_BITS_FOR_ACN_ENCODING        32

flag asn1SccContext_anemometer_ACN_Encode(const asn1SccContext_anemometer* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_CONTEXT_ANEMOMETER		8489  /**/
#define ERR_ACN_DECODE_CONTEXT_ANEMOMETER_GPIO_PIN_2		8482  /**/
flag asn1SccContext_anemometer_ACN_Decode(asn1SccContext_anemometer* pVal, BitStream* pBitStrm, int* pErrCode);

extern const asn1SccContext_anemometer anemometer_ctxt; 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
