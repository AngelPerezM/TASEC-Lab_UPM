/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>

#include "asn1crt_encoding.h"
#include "asn1crt_encoding_uper.h"
#include "asn1crt_encoding_acn.h"

#include "Context-heater1.h"

const asn1SccContext_heater1 heater1_ctxt = {
    .gpio_pin = 12
};


flag asn1SccContext_heater1_Equal(const asn1SccContext_heater1* pVal1, const asn1SccContext_heater1* pVal2)
{
	flag ret=TRUE;

    ret = (pVal1->gpio_pin == pVal2->gpio_pin);

	return ret;

}

void asn1SccContext_heater1_Initialize(asn1SccContext_heater1* pVal)
{
	(void)pVal;



	/*set gpio_pin */
	asn1SccT_Int32_Initialize((&(pVal->gpio_pin)));
}

flag asn1SccContext_heater1_IsConstraintValid(const asn1SccContext_heater1* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = asn1SccT_Int32_IsConstraintValid((&(pVal->gpio_pin)), pErrCode);

	return ret;
}

flag asn1SccContext_heater1_Encode(const asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	ret = bCheckConstraints ? asn1SccContext_heater1_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode gpio_pin */
	    ret = asn1SccT_Int32_Encode((&(pVal->gpio_pin)), pBitStrm, pErrCode, FALSE);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_heater1_Decode(asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode gpio_pin */
	ret = asn1SccT_Int32_Decode((&(pVal->gpio_pin)), pBitStrm, pErrCode);

	return ret  && asn1SccContext_heater1_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccContext_heater1_ACN_Encode(const asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

	ret = bCheckConstraints ? asn1SccContext_heater1_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode gpio_pin */
	    ret = asn1SccT_Int32_ACN_Encode((&(pVal->gpio_pin)), pBitStrm, pErrCode, FALSE);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_heater1_ACN_Decode(asn1SccContext_heater1* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode gpio_pin */
	ret = asn1SccT_Int32_ACN_Decode((&(pVal->gpio_pin)), pBitStrm, pErrCode);

    return ret && asn1SccContext_heater1_IsConstraintValid(pVal, pErrCode);
}

