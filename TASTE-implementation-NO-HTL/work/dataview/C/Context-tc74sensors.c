/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>

#include "asn1crt_encoding.h"
#include "asn1crt_encoding_uper.h"
#include "asn1crt_encoding_acn.h"

#include "Context-tc74sensors.h"

const asn1SccContext_tc74sensors tc74sensors_ctxt = {
    .i2c_channels = {    .arr = 
        {
            11,
            12,
            13,
            14,
            15        
        }
    }
};


flag asn1SccContext_tc74sensors_Equal(const asn1SccContext_tc74sensors* pVal1, const asn1SccContext_tc74sensors* pVal2)
{
	flag ret=TRUE;

    ret = asn1SccTC74s_I2CBuses_Equal((&(pVal1->i2c_channels)), (&(pVal2->i2c_channels)));

	return ret;

}

void asn1SccContext_tc74sensors_Initialize(asn1SccContext_tc74sensors* pVal)
{
	(void)pVal;



	/*set i2c_channels */
	asn1SccTC74s_I2CBuses_Initialize((&(pVal->i2c_channels)));
}

flag asn1SccContext_tc74sensors_IsConstraintValid(const asn1SccContext_tc74sensors* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = asn1SccTC74s_I2CBuses_IsConstraintValid((&(pVal->i2c_channels)), pErrCode);

	return ret;
}

flag asn1SccContext_tc74sensors_Encode(const asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	ret = bCheckConstraints ? asn1SccContext_tc74sensors_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode i2c_channels */
	    ret = asn1SccTC74s_I2CBuses_Encode((&(pVal->i2c_channels)), pBitStrm, pErrCode, FALSE);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_tc74sensors_Decode(asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode i2c_channels */
	ret = asn1SccTC74s_I2CBuses_Decode((&(pVal->i2c_channels)), pBitStrm, pErrCode);

	return ret  && asn1SccContext_tc74sensors_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccContext_tc74sensors_ACN_Encode(const asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

	ret = bCheckConstraints ? asn1SccContext_tc74sensors_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode i2c_channels */
	    ret = asn1SccTC74s_I2CBuses_ACN_Encode((&(pVal->i2c_channels)), pBitStrm, pErrCode, FALSE);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccContext_tc74sensors_ACN_Decode(asn1SccContext_tc74sensors* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode i2c_channels */
	ret = asn1SccTC74s_I2CBuses_ACN_Decode((&(pVal->i2c_channels)), pBitStrm, pErrCode);

    return ret && asn1SccContext_tc74sensors_IsConstraintValid(pVal, pErrCode);
}

