#include "sos/sos.h"

#include "gcov_api.h"

static const gcov_api_t * m_gcov_api = NULL;

static int fetch_api(){
	if( m_gcov_api == NULL ){
		m_gcov_api = kernel_request_api(GCOV_API_REQUEST);
	}
	return m_gcov_api == NULL ? -1 : 0;
}

void __gcov_init(void * info){
	if( fetch_api() <	0 ){
		printf("kernel does not provide gcov API\n");
		exit(1);
	}
	m_gcov_api->init(info);
}

void __gcov_merge_add(u32 type, u32 value){
	m_gcov_api->merge_add(type, value);
}
