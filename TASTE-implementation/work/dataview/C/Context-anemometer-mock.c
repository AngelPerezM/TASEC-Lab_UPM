/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>

#include "asn1crt_encoding.h"
#include "asn1crt_encoding_uper.h"
#include "asn1crt_encoding_acn.h"

#include "Context-anemometer-mock.h"

const asn1SccContext_anemometer_mock anemometer_mock_ctxt = {
    .pin = 22,
    .freq_hz = 1.50000000000000000000E+003
};


flag asn1SccContext_anemometer_mock_Equal(const asn1SccContext_anemometer_mock* pVal1, const asn1SccContext_anemometer_mock* pVal2)
{
	flag ret=TRUE;

    ret = (pVal1->pin == pVal2->pin);

    if (ret) {
        ret = (pVal1->freq_hz == pVal2->freq_hz);

    }

	return ret;

}

void asn1SccContext_anemometer_mock_Initialize(asn1SccContext_anemometer_mock* pVal)
{
	(void)pVal;



	/*set pin */
	asn1SccT_UInt32_Initialize((&(pVal->pin)));
	/*set freq_hz */
	asn1SccT_Float_Initialize((&(pVal->freq_hz)));
}

flag asn1SccContext_anemometer_mock_IsConstraintValid(const asn1SccContext_anemometer_mock* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = asn1SccT_UInt32_IsConstraintValid((&(pVal->pin)), pErrCode);
    if (ret) {
        ret = asn1SccT_Float_IsConstraintValid((&(pVal->freq_hz)), pErrCode);
    }

	return ret;
}

flag asn1SccContext_anemometer_mock_Encode(const asn1SccContext_anemometer_mock* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	ret = bCheckConstraints ? asn1SccContext_anemometer_mock_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode pin */
	    ret = asn1SccT_UInt32_Encode((&(pVal->pin)), pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode freq_hz */
	        ret = asn1SccT_Float_Encode((&(pVal->freq_hz)), pBitStrm, pErrCode, FALSE);
	    }
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_anemometer_mock_Decode(asn1SccContext_anemometer_mock* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode pin */
	ret = asn1SccT_UInt32_Decode((&(pVal->pin)), pBitStrm, pErrCode);
	if (ret) {
	    /*Decode freq_hz */
	    ret = asn1SccT_Float_Decode((&(pVal->freq_hz)), pBitStrm, pErrCode);
	}

	return ret  && asn1SccContext_anemometer_mock_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccContext_anemometer_mock_ACN_Encode(const asn1SccContext_anemometer_mock* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

	ret = bCheckConstraints ? asn1SccContext_anemometer_mock_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode pin */
	    ret = asn1SccT_UInt32_ACN_Encode((&(pVal->pin)), pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode freq_hz */
	        ret = asn1SccT_Float_ACN_Encode((&(pVal->freq_hz)), pBitStrm, pErrCode, FALSE);
	    }

    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_anemometer_mock_ACN_Decode(asn1SccContext_anemometer_mock* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode pin */
	ret = asn1SccT_UInt32_ACN_Decode((&(pVal->pin)), pBitStrm, pErrCode);
	if (ret) {
	    /*Decode freq_hz */
	    ret = asn1SccT_Float_ACN_Decode((&(pVal->freq_hz)), pBitStrm, pErrCode);
	}


    return ret && asn1SccContext_anemometer_mock_IsConstraintValid(pVal, pErrCode);
}

