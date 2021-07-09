/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>

#include "asn1crt_encoding.h"
#include "asn1crt_encoding_uper.h"
#include "asn1crt_encoding_acn.h"

#include "Context-pt1000sensors.h"

const asn1SccContext_pt1000sensors pt1000sensors_ctxt = {
    .vcc_ch = 7,
    .channels = {    .arr = 
        {
            0,
            1,
            2,
            3,
            4,
            5,
            6        
        }
    }
};


flag asn1SccContext_pt1000sensors_Equal(const asn1SccContext_pt1000sensors* pVal1, const asn1SccContext_pt1000sensors* pVal2)
{
	flag ret=TRUE;

    ret = (pVal1->vcc_ch == pVal2->vcc_ch);

    if (ret) {
        ret = asn1SccPT1000s_Channels_Equal((&(pVal1->channels)), (&(pVal2->channels)));

    }

	return ret;

}

void asn1SccContext_pt1000sensors_Initialize(asn1SccContext_pt1000sensors* pVal)
{
	(void)pVal;



	/*set vcc_ch */
	asn1SccT_Int32_Initialize((&(pVal->vcc_ch)));
	/*set channels */
	asn1SccPT1000s_Channels_Initialize((&(pVal->channels)));
}

flag asn1SccContext_pt1000sensors_IsConstraintValid(const asn1SccContext_pt1000sensors* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = asn1SccT_Int32_IsConstraintValid((&(pVal->vcc_ch)), pErrCode);
    if (ret) {
        ret = asn1SccPT1000s_Channels_IsConstraintValid((&(pVal->channels)), pErrCode);
    }

	return ret;
}

flag asn1SccContext_pt1000sensors_Encode(const asn1SccContext_pt1000sensors* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	ret = bCheckConstraints ? asn1SccContext_pt1000sensors_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode vcc_ch */
	    ret = asn1SccT_Int32_Encode((&(pVal->vcc_ch)), pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode channels */
	        ret = asn1SccPT1000s_Channels_Encode((&(pVal->channels)), pBitStrm, pErrCode, FALSE);
	    }
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_pt1000sensors_Decode(asn1SccContext_pt1000sensors* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode vcc_ch */
	ret = asn1SccT_Int32_Decode((&(pVal->vcc_ch)), pBitStrm, pErrCode);
	if (ret) {
	    /*Decode channels */
	    ret = asn1SccPT1000s_Channels_Decode((&(pVal->channels)), pBitStrm, pErrCode);
	}

	return ret  && asn1SccContext_pt1000sensors_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccContext_pt1000sensors_ACN_Encode(const asn1SccContext_pt1000sensors* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

	ret = bCheckConstraints ? asn1SccContext_pt1000sensors_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode vcc_ch */
	    ret = asn1SccT_Int32_ACN_Encode((&(pVal->vcc_ch)), pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode channels */
	        ret = asn1SccPT1000s_Channels_ACN_Encode((&(pVal->channels)), pBitStrm, pErrCode, FALSE);
	    }

    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_pt1000sensors_ACN_Decode(asn1SccContext_pt1000sensors* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode vcc_ch */
	ret = asn1SccT_Int32_ACN_Decode((&(pVal->vcc_ch)), pBitStrm, pErrCode);
	if (ret) {
	    /*Decode channels */
	    ret = asn1SccPT1000s_Channels_ACN_Decode((&(pVal->channels)), pBitStrm, pErrCode);
	}


    return ret && asn1SccContext_pt1000sensors_IsConstraintValid(pVal, pErrCode);
}

