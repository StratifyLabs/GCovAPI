
#include "gcov_api.h"

extern void __gcov_init();
extern void __gcov_merge_add();

const gcov_api_t gcov_api = {
	.sos_api = {
		.name = "gcov",
		.version = GCOV_API_VERSION,
		.git_hash = SOS_GIT_HASH
	},
	.init = __gcov_init,
	.merge_add = __gcov_merge_add
};
