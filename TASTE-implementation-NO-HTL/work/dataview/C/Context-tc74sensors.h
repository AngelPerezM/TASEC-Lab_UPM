#ifndef GENERATED_ASN1SCC_Context_tc74sensors_H
#define GENERATED_ASN1SCC_Context_tc74sensors_H
/*
Code automatically generated by asn1scc tool
*/
#include "asn1crt.h"
#include "asn1crt_encoding.h"

#include "dataview-uniq.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*-- asn1SccContext_tc74sensors --------------------------------------------*/
typedef struct {
    asn1SccTC74s_I2CBuses i2c_channels;

} asn1SccContext_tc74sensors;

flag asn1SccContext_tc74sensors_Equal(const asn1SccContext_tc74sensors* pVal1, const asn1SccContext_tc74sensors* pVal2);

void asn1SccContext_tc74sensors_Initialize(asn1SccContext_tc74sensors* pVal);

#define ERR_CONTEXT_TC74SENSORS		8275  /**/
#define ERR_CONTEXT_TC74SENSORS_I2C_CHANNELS_2		8268  /**/
flag asn1SccContext_tc74sensors_IsConstraintValid(const asn1SccContext_tc74sensors* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_CONTEXT_TC74SENSORS		8276  /**/
#define ERR_UPER_ENCODE_CONTEXT_TC74SENSORS_I2C_CHANNELS_2		8269  /**/
#define asn1SccContext_tc74sensors_REQUIRED_BYTES_FOR_ENCODING       20 
#define asn1SccContext_tc74sensors_REQUIRED_BITS_FOR_ENCODING        160

flag asn1SccContext_tc74sensors_Encode(const asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_CONTEXT_TC74SENSORS		8277  /**/
#define ERR_UPER_DECODE_CONTEXT_TC74SENSORS_I2C_CHANNELS_2		8270  /**/
flag asn1SccContext_tc74sensors_Decode(asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_CONTEXT_TC74SENSORS		8278  /**/
#define ERR_ACN_ENCODE_CONTEXT_TC74SENSORS_I2C_CHANNELS_2		8271  /**/
#define asn1SccContext_tc74sensors_REQUIRED_BYTES_FOR_ACN_ENCODING       20 
#define asn1SccContext_tc74sensors_REQUIRED_BITS_FOR_ACN_ENCODING        160

flag asn1SccContext_tc74sensors_ACN_Encode(const asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_CONTEXT_TC74SENSORS		8279  /**/
#define ERR_ACN_DECODE_CONTEXT_TC74SENSORS_I2C_CHANNELS_2		8272  /**/
flag asn1SccContext_tc74sensors_ACN_Decode(asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode);

extern const asn1SccContext_tc74sensors tc74sensors_ctxt; 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
