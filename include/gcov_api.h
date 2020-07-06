#ifndef GCOV_API_H
#define GCOV_API_H

#include <mcu/types.h>
#include <sos/api/sos_api.h>


typedef struct {
	sos_api_t sos_api;
	void (*init)(void * info);
	void (*merge_add)(u32,u32);
} gcov_api_t;


#define GCOV_API_REQUEST MCU_API_REQUEST_CODE('g','c','o','v')
extern const gcov_api_t gcov_api;

#define GCOV_API_VERSION 0x00000001

#endif // GCOV_API_H
