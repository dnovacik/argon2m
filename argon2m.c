#include "argon2d/argon2.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

static const size_t INPUT_BYTES = 80;
static const size_t OUTPUT_BYTES = 32;
static const unsigned int DEFAULT_ARGON2_FLAG = 2;

void argon2m_hash(void* input, void* output)
{
    char hashout[32];
    memset(hashout,'\0',32);

    argon2_context context;
    context.out = (uint8_t *)output;
    context.outlen = (uint32_t)OUTPUT_BYTES;
    context.pwd = (unsigned char*)input;
    context.pwdlen = (uint32_t)INPUT_BYTES;
    context.salt = context.pwd;
    context.saltlen = context.pwdlen;
    context.secret = NULL;
    context.secretlen = 0;
    context.ad = NULL;
    context.adlen = 0;
    context.allocate_cbk = NULL;
    context.free_cbk = NULL;
    context.flags = DEFAULT_ARGON2_FLAG;
    context.m_cost = 2;
    context.lanes = 1;
    context.threads = 1;
    context.t_cost = 1;
    context.version = ARGON2_VERSION_13;
    argon2_ctx(&context, Argon2_id);

    memcpy(output,hashout,32);
}