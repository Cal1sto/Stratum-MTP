#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "sysendian.h"

#include "mtp.h"
#include "argon2ref/core.h"
#include "argon2ref/argon2.h"
#include "argon2ref/thread.h"
#include "argon2ref/blake2.h"
#include "argon2ref/blake2-impl.h"
#include "argon2ref/blamka-round-opt.h"

argon2_context init_argon2d_param(const char* input, char* output) {

    argon2_context context;
    argon2_context *pContext = &context;

    const allocate_fptr myown_allocator = NULL;
    const deallocate_fptr myown_deallocator = NULL;

    memset(pContext,0,sizeof(argon2_context));
    memset(&output[0], 0, sizeof(output));

    context.out = output;
    context.outlen = 32;
    context.version = ARGON2_VERSION_NUMBER;
    context.pwd = (uint8_t*)input;
    context.pwdlen = 80;
    context.salt = (uint8_t*)input;
    context.saltlen = 80;
    context.secret = NULL;
    context.secretlen = 0;
    context.ad = NULL;
    context.adlen = 0;
    context.t_cost = 1;
    context.m_cost = 4194304;
    context.lanes = 4;
    context.threads = 4;
    context.allocate_cbk = myown_allocator;
    context.free_cbk = myown_deallocator;
    context.flags = ARGON2_DEFAULT_FLAGS;

    return context;
}


inline void argon_call(const void *input,void *output)
{
	argon2_context context = init_argon2d_param(input, output);
    	argon2_instance_t instance;
    	argon2_ctx_from_mtp(&context, &instance);
}

void mtp_hash(const char* input, char* output, uint32_t len)
{
	argon_call(input, output);
}

