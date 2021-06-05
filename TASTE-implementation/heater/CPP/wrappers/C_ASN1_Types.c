#ifdef __unix__
#include <stdio.h>
#include <assert.h>
#endif

#include <string.h>

#include "C_ASN1_Types.h"

#ifdef __NEED_T_Int16_UPER
int Encode_UPER_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int16_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int16_ACN
int Encode_ACN_T_Int16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int16_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int16_NATIVE
int Encode_NATIVE_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int16) );
    return sizeof(asn1SccT_Int16);
}
#endif

#ifdef __NEED_T_Int16_UPER
int Decode_UPER_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int16_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int16_ACN
int Decode_ACN_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int16_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int16_NATIVE
int Decode_NATIVE_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int16 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt16_UPER
int Encode_UPER_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt16_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt16_ACN
int Encode_ACN_T_UInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt16_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Encode_NATIVE_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt16) );
    return sizeof(asn1SccT_UInt16);
}
#endif

#ifdef __NEED_T_UInt16_UPER
int Decode_UPER_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt16_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt16_ACN
int Decode_ACN_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt16_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Decode_NATIVE_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt16 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Float_UPER
int Encode_UPER_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Float_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Float (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Float_ACN
int Encode_ACN_T_Float(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Float *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Float_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Float (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Float_NATIVE
int Encode_NATIVE_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Float) );
    return sizeof(asn1SccT_Float);
}
#endif

#ifdef __NEED_T_Float_UPER
int Decode_UPER_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Float_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Float (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Float_ACN
int Decode_ACN_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Float_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Float (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Float_NATIVE
int Decode_NATIVE_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Float *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Double_UPER
int Encode_UPER_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Double_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Double (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Double_ACN
int Encode_ACN_T_Double(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Double *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Double_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Double (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Double_NATIVE
int Encode_NATIVE_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Double) );
    return sizeof(asn1SccT_Double);
}
#endif

#ifdef __NEED_T_Double_UPER
int Decode_UPER_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Double_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Double (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Double_ACN
int Decode_ACN_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Double_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Double (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Double_NATIVE
int Decode_NATIVE_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Double *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_SPI_ID_UPER
int Encode_UPER_SPI_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccSPI_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSPI_ID_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SPI-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SPI_ID_ACN
int Encode_ACN_SPI_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccSPI_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSPI_ID_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SPI-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SPI_ID_NATIVE
int Encode_NATIVE_SPI_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccSPI_ID *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccSPI_ID) );
    return sizeof(asn1SccSPI_ID);
}
#endif

#ifdef __NEED_SPI_ID_UPER
int Decode_UPER_SPI_ID(asn1SccSPI_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSPI_ID_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SPI-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SPI_ID_ACN
int Decode_ACN_SPI_ID(asn1SccSPI_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSPI_ID_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SPI-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SPI_ID_NATIVE
int Decode_NATIVE_SPI_ID(asn1SccSPI_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccSPI_ID *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_I2C_ID_UPER
int Encode_UPER_I2C_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccI2C_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccI2C_ID_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode I2C-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_I2C_ID_ACN
int Encode_ACN_I2C_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccI2C_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccI2C_ID_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode I2C-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_I2C_ID_NATIVE
int Encode_NATIVE_I2C_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccI2C_ID *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccI2C_ID) );
    return sizeof(asn1SccI2C_ID);
}
#endif

#ifdef __NEED_I2C_ID_UPER
int Decode_UPER_I2C_ID(asn1SccI2C_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccI2C_ID_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode I2C-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_I2C_ID_ACN
int Decode_ACN_I2C_ID(asn1SccI2C_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccI2C_ID_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode I2C-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_I2C_ID_NATIVE
int Decode_NATIVE_I2C_ID(asn1SccI2C_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccI2C_ID *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_GPS_PVT_UPER
int Encode_UPER_GPS_PVT(void *pBuffer, size_t iMaxBufferSize, const asn1SccGPS_PVT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccGPS_PVT_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode GPS-PVT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_GPS_PVT_ACN
int Encode_ACN_GPS_PVT(void *pBuffer, size_t iMaxBufferSize, asn1SccGPS_PVT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccGPS_PVT_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode GPS-PVT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_GPS_PVT_NATIVE
int Encode_NATIVE_GPS_PVT(void *pBuffer, size_t iMaxBufferSize, const asn1SccGPS_PVT *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccGPS_PVT) );
    return sizeof(asn1SccGPS_PVT);
}
#endif

#ifdef __NEED_GPS_PVT_UPER
int Decode_UPER_GPS_PVT(asn1SccGPS_PVT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccGPS_PVT_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode GPS-PVT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_GPS_PVT_ACN
int Decode_ACN_GPS_PVT(asn1SccGPS_PVT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccGPS_PVT_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode GPS-PVT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_GPS_PVT_NATIVE
int Decode_NATIVE_GPS_PVT(asn1SccGPS_PVT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccGPS_PVT *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_MGT_Raw_Data_UPER
int Encode_UPER_MGT_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMGT_Raw_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MGT-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MGT_Raw_Data_ACN
int Encode_ACN_MGT_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccMGT_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMGT_Raw_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MGT-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MGT_Raw_Data_NATIVE
int Encode_NATIVE_MGT_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccMGT_Raw_Data) );
    return sizeof(asn1SccMGT_Raw_Data);
}
#endif

#ifdef __NEED_MGT_Raw_Data_UPER
int Decode_UPER_MGT_Raw_Data(asn1SccMGT_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMGT_Raw_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MGT-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MGT_Raw_Data_ACN
int Decode_ACN_MGT_Raw_Data(asn1SccMGT_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMGT_Raw_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MGT-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MGT_Raw_Data_NATIVE
int Decode_NATIVE_MGT_Raw_Data(asn1SccMGT_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccMGT_Raw_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_MGT_MilliGauss_Data_UPER
int Encode_UPER_MGT_MilliGauss_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_MilliGauss_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMGT_MilliGauss_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MGT-MilliGauss-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MGT_MilliGauss_Data_ACN
int Encode_ACN_MGT_MilliGauss_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccMGT_MilliGauss_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMGT_MilliGauss_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MGT-MilliGauss-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MGT_MilliGauss_Data_NATIVE
int Encode_NATIVE_MGT_MilliGauss_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_MilliGauss_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccMGT_MilliGauss_Data) );
    return sizeof(asn1SccMGT_MilliGauss_Data);
}
#endif

#ifdef __NEED_MGT_MilliGauss_Data_UPER
int Decode_UPER_MGT_MilliGauss_Data(asn1SccMGT_MilliGauss_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMGT_MilliGauss_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MGT-MilliGauss-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MGT_MilliGauss_Data_ACN
int Decode_ACN_MGT_MilliGauss_Data(asn1SccMGT_MilliGauss_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMGT_MilliGauss_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MGT-MilliGauss-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MGT_MilliGauss_Data_NATIVE
int Decode_NATIVE_MGT_MilliGauss_Data(asn1SccMGT_MilliGauss_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccMGT_MilliGauss_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_ACC_Raw_Data_UPER
int Encode_UPER_ACC_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccACC_Raw_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ACC-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ACC_Raw_Data_ACN
int Encode_ACN_ACC_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccACC_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccACC_Raw_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ACC-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ACC_Raw_Data_NATIVE
int Encode_NATIVE_ACC_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccACC_Raw_Data) );
    return sizeof(asn1SccACC_Raw_Data);
}
#endif

#ifdef __NEED_ACC_Raw_Data_UPER
int Decode_UPER_ACC_Raw_Data(asn1SccACC_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccACC_Raw_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ACC-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ACC_Raw_Data_ACN
int Decode_ACN_ACC_Raw_Data(asn1SccACC_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccACC_Raw_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ACC-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ACC_Raw_Data_NATIVE
int Decode_NATIVE_ACC_Raw_Data(asn1SccACC_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccACC_Raw_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_ACC_MilliG_Data_UPER
int Encode_UPER_ACC_MilliG_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_MilliG_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccACC_MilliG_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ACC-MilliG-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ACC_MilliG_Data_ACN
int Encode_ACN_ACC_MilliG_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccACC_MilliG_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccACC_MilliG_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ACC-MilliG-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ACC_MilliG_Data_NATIVE
int Encode_NATIVE_ACC_MilliG_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_MilliG_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccACC_MilliG_Data) );
    return sizeof(asn1SccACC_MilliG_Data);
}
#endif

#ifdef __NEED_ACC_MilliG_Data_UPER
int Decode_UPER_ACC_MilliG_Data(asn1SccACC_MilliG_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccACC_MilliG_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ACC-MilliG-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ACC_MilliG_Data_ACN
int Decode_ACN_ACC_MilliG_Data(asn1SccACC_MilliG_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccACC_MilliG_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ACC-MilliG-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ACC_MilliG_Data_NATIVE
int Decode_NATIVE_ACC_MilliG_Data(asn1SccACC_MilliG_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccACC_MilliG_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_GYRO_Raw_Data_UPER
int Encode_UPER_GYRO_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccGYRO_Raw_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode GYRO-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_GYRO_Raw_Data_ACN
int Encode_ACN_GYRO_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccGYRO_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccGYRO_Raw_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode GYRO-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_GYRO_Raw_Data_NATIVE
int Encode_NATIVE_GYRO_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccGYRO_Raw_Data) );
    return sizeof(asn1SccGYRO_Raw_Data);
}
#endif

#ifdef __NEED_GYRO_Raw_Data_UPER
int Decode_UPER_GYRO_Raw_Data(asn1SccGYRO_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccGYRO_Raw_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode GYRO-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_GYRO_Raw_Data_ACN
int Decode_ACN_GYRO_Raw_Data(asn1SccGYRO_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccGYRO_Raw_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode GYRO-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_GYRO_Raw_Data_NATIVE
int Decode_NATIVE_GYRO_Raw_Data(asn1SccGYRO_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccGYRO_Raw_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_UPER
int Encode_UPER_GYRO_MilliDPS_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_MilliDPS_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccGYRO_MilliDPS_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode GYRO-MilliDPS-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_ACN
int Encode_ACN_GYRO_MilliDPS_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccGYRO_MilliDPS_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccGYRO_MilliDPS_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode GYRO-MilliDPS-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_NATIVE
int Encode_NATIVE_GYRO_MilliDPS_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_MilliDPS_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccGYRO_MilliDPS_Data) );
    return sizeof(asn1SccGYRO_MilliDPS_Data);
}
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_UPER
int Decode_UPER_GYRO_MilliDPS_Data(asn1SccGYRO_MilliDPS_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccGYRO_MilliDPS_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode GYRO-MilliDPS-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_ACN
int Decode_ACN_GYRO_MilliDPS_Data(asn1SccGYRO_MilliDPS_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccGYRO_MilliDPS_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode GYRO-MilliDPS-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_NATIVE
int Decode_NATIVE_GYRO_MilliDPS_Data(asn1SccGYRO_MilliDPS_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccGYRO_MilliDPS_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_IMU_All_Data_UPER
int Encode_UPER_IMU_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccIMU_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccIMU_All_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode IMU-All-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_IMU_All_Data_ACN
int Encode_ACN_IMU_All_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccIMU_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccIMU_All_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode IMU-All-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_IMU_All_Data_NATIVE
int Encode_NATIVE_IMU_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccIMU_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccIMU_All_Data) );
    return sizeof(asn1SccIMU_All_Data);
}
#endif

#ifdef __NEED_IMU_All_Data_UPER
int Decode_UPER_IMU_All_Data(asn1SccIMU_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccIMU_All_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode IMU-All-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_IMU_All_Data_ACN
int Decode_ACN_IMU_All_Data(asn1SccIMU_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccIMU_All_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode IMU-All-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_IMU_All_Data_NATIVE
int Decode_NATIVE_IMU_All_Data(asn1SccIMU_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccIMU_All_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC74s_Celsius_Data_UPER
int Encode_UPER_TC74s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC74s_Celsius_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC74s_Celsius_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC74s-Celsius-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC74s_Celsius_Data_ACN
int Encode_ACN_TC74s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccTC74s_Celsius_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC74s_Celsius_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC74s-Celsius-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC74s_Celsius_Data_NATIVE
int Encode_NATIVE_TC74s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC74s_Celsius_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC74s_Celsius_Data) );
    return sizeof(asn1SccTC74s_Celsius_Data);
}
#endif

#ifdef __NEED_TC74s_Celsius_Data_UPER
int Decode_UPER_TC74s_Celsius_Data(asn1SccTC74s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC74s_Celsius_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC74s-Celsius-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC74s_Celsius_Data_ACN
int Decode_ACN_TC74s_Celsius_Data(asn1SccTC74s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC74s_Celsius_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC74s-Celsius-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC74s_Celsius_Data_NATIVE
int Decode_NATIVE_TC74s_Celsius_Data(asn1SccTC74s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC74s_Celsius_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PT1000s_Raw_Data_UPER
int Encode_UPER_PT1000s_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPT1000s_Raw_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PT1000s-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PT1000s_Raw_Data_ACN
int Encode_ACN_PT1000s_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPT1000s_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPT1000s_Raw_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PT1000s-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PT1000s_Raw_Data_NATIVE
int Encode_NATIVE_PT1000s_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPT1000s_Raw_Data) );
    return sizeof(asn1SccPT1000s_Raw_Data);
}
#endif

#ifdef __NEED_PT1000s_Raw_Data_UPER
int Decode_UPER_PT1000s_Raw_Data(asn1SccPT1000s_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPT1000s_Raw_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PT1000s-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PT1000s_Raw_Data_ACN
int Decode_ACN_PT1000s_Raw_Data(asn1SccPT1000s_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPT1000s_Raw_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PT1000s-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PT1000s_Raw_Data_NATIVE
int Decode_NATIVE_PT1000s_Raw_Data(asn1SccPT1000s_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPT1000s_Raw_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PT1000s_Celsius_Data_UPER
int Encode_UPER_PT1000s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Celsius_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPT1000s_Celsius_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PT1000s-Celsius-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PT1000s_Celsius_Data_ACN
int Encode_ACN_PT1000s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPT1000s_Celsius_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPT1000s_Celsius_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PT1000s-Celsius-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PT1000s_Celsius_Data_NATIVE
int Encode_NATIVE_PT1000s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Celsius_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPT1000s_Celsius_Data) );
    return sizeof(asn1SccPT1000s_Celsius_Data);
}
#endif

#ifdef __NEED_PT1000s_Celsius_Data_UPER
int Decode_UPER_PT1000s_Celsius_Data(asn1SccPT1000s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPT1000s_Celsius_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PT1000s-Celsius-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PT1000s_Celsius_Data_ACN
int Decode_ACN_PT1000s_Celsius_Data(asn1SccPT1000s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPT1000s_Celsius_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PT1000s-Celsius-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PT1000s_Celsius_Data_NATIVE
int Decode_NATIVE_PT1000s_Celsius_Data(asn1SccPT1000s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPT1000s_Celsius_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PT1000s_All_Data_UPER
int Encode_UPER_PT1000s_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPT1000s_All_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PT1000s-All-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PT1000s_All_Data_ACN
int Encode_ACN_PT1000s_All_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPT1000s_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPT1000s_All_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PT1000s-All-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PT1000s_All_Data_NATIVE
int Encode_NATIVE_PT1000s_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPT1000s_All_Data) );
    return sizeof(asn1SccPT1000s_All_Data);
}
#endif

#ifdef __NEED_PT1000s_All_Data_UPER
int Decode_UPER_PT1000s_All_Data(asn1SccPT1000s_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPT1000s_All_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PT1000s-All-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PT1000s_All_Data_ACN
int Decode_ACN_PT1000s_All_Data(asn1SccPT1000s_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPT1000s_All_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PT1000s-All-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PT1000s_All_Data_NATIVE
int Decode_NATIVE_PT1000s_All_Data(asn1SccPT1000s_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPT1000s_All_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PS_Calibration_Data_UPER
int Encode_UPER_PS_Calibration_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Calibration_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_Calibration_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-Calibration-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_Calibration_Data_ACN
int Encode_ACN_PS_Calibration_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_Calibration_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_Calibration_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-Calibration-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_Calibration_Data_NATIVE
int Encode_NATIVE_PS_Calibration_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Calibration_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPS_Calibration_Data) );
    return sizeof(asn1SccPS_Calibration_Data);
}
#endif

#ifdef __NEED_PS_Calibration_Data_UPER
int Decode_UPER_PS_Calibration_Data(asn1SccPS_Calibration_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_Calibration_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-Calibration-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_Calibration_Data_ACN
int Decode_ACN_PS_Calibration_Data(asn1SccPS_Calibration_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_Calibration_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-Calibration-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_Calibration_Data_NATIVE
int Decode_NATIVE_PS_Calibration_Data(asn1SccPS_Calibration_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPS_Calibration_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PS_Raw_Data_UPER
int Encode_UPER_PS_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_Raw_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_Raw_Data_ACN
int Encode_ACN_PS_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_Raw_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-Raw-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_Raw_Data_NATIVE
int Encode_NATIVE_PS_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Raw_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPS_Raw_Data) );
    return sizeof(asn1SccPS_Raw_Data);
}
#endif

#ifdef __NEED_PS_Raw_Data_UPER
int Decode_UPER_PS_Raw_Data(asn1SccPS_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_Raw_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_Raw_Data_ACN
int Decode_ACN_PS_Raw_Data(asn1SccPS_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_Raw_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-Raw-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_Raw_Data_NATIVE
int Decode_NATIVE_PS_Raw_Data(asn1SccPS_Raw_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPS_Raw_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PS_Processed_Data_UPER
int Encode_UPER_PS_Processed_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Processed_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_Processed_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-Processed-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_Processed_Data_ACN
int Encode_ACN_PS_Processed_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_Processed_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_Processed_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-Processed-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_Processed_Data_NATIVE
int Encode_NATIVE_PS_Processed_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Processed_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPS_Processed_Data) );
    return sizeof(asn1SccPS_Processed_Data);
}
#endif

#ifdef __NEED_PS_Processed_Data_UPER
int Decode_UPER_PS_Processed_Data(asn1SccPS_Processed_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_Processed_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-Processed-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_Processed_Data_ACN
int Decode_ACN_PS_Processed_Data(asn1SccPS_Processed_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_Processed_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-Processed-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_Processed_Data_NATIVE
int Decode_NATIVE_PS_Processed_Data(asn1SccPS_Processed_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPS_Processed_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PS_All_Data_UPER
int Encode_UPER_PS_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_All_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-All-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_All_Data_ACN
int Encode_ACN_PS_All_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPS_All_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PS-All-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PS_All_Data_NATIVE
int Encode_NATIVE_PS_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_All_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPS_All_Data) );
    return sizeof(asn1SccPS_All_Data);
}
#endif

#ifdef __NEED_PS_All_Data_UPER
int Decode_UPER_PS_All_Data(asn1SccPS_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_All_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-All-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_All_Data_ACN
int Decode_ACN_PS_All_Data(asn1SccPS_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPS_All_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PS-All-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PS_All_Data_NATIVE
int Decode_NATIVE_PS_All_Data(asn1SccPS_All_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPS_All_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_OBSW_DP_Data_UPER
int Encode_UPER_OBSW_DP_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccOBSW_DP_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode OBSW-DP-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_OBSW_DP_Data_ACN
int Encode_ACN_OBSW_DP_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccOBSW_DP_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccOBSW_DP_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode OBSW-DP-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_OBSW_DP_Data_NATIVE
int Encode_NATIVE_OBSW_DP_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccOBSW_DP_Data) );
    return sizeof(asn1SccOBSW_DP_Data);
}
#endif

#ifdef __NEED_OBSW_DP_Data_UPER
int Decode_UPER_OBSW_DP_Data(asn1SccOBSW_DP_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccOBSW_DP_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode OBSW-DP-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_OBSW_DP_Data_ACN
int Decode_ACN_OBSW_DP_Data(asn1SccOBSW_DP_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccOBSW_DP_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode OBSW-DP-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_OBSW_DP_Data_NATIVE
int Decode_NATIVE_OBSW_DP_Data(asn1SccOBSW_DP_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccOBSW_DP_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int32) );
    return sizeof(asn1SccT_Int32);
}
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt32) );
    return sizeof(asn1SccT_UInt32);
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int8) );
    return sizeof(asn1SccT_Int8);
}
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt8) );
    return sizeof(asn1SccT_UInt8);
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Boolean) );
    return sizeof(asn1SccT_Boolean);
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Boolean *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Null_Record) );
    return sizeof(asn1SccT_Null_Record);
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Null_Record *) pBuffer;
    {
        return 0;
    }
}
#endif

