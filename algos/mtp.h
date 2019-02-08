#ifndef MTP_H
#define MTP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "argon2ref/argon2.h"

argon2_context init_argon2d_param(const char* input,char* output);

void mtp_hash(const char* input, char* output, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
