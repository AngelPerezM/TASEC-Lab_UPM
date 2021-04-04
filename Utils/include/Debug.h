#ifndef DEBUG_H
#define DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * CircularBuffer.h
 *
 * Author: Ángel Pérez
 *
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdio.h>

/* MACROS section
 *******************************************************************************/
#define PRINT_ERROR(msg, args...) \
  fprintf(stderr, "[ERROR] %s: %s at line %d:\n\t" msg, __func__,  __FILE__, __LINE__, ##args)
  
#ifdef DEBUG
#define PRINT_DEBUG(msg, args...) \
  printf("[DEBUG] %s: " msg, __func__,  ##args)
#else
#define PRINT_DEBUG(s, args...)
#endif

#ifdef __cplusplus
}
#endif

#endif // DEBUG_H
