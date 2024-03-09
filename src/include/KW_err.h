// Copyright (C) 2024  KA Wright

/**
 * This header file specifies an API for signaling and reading error states.
*/

#ifndef __KW_ERR_H__
#define __KW_ERR_H__

#include "KW_cb.h"

/**
 * The maximum length of an error message.
*/
#define KW_MAX_ERR_MSG_LEN 127

/**
 * This enum stores all supported error codes. The values of the members
 * represent the exit code used for fatal error conditions.
*/
typedef enum __KW_ERRCODE__ {
    KW_ERR_OK               = 0,    // 0: No error
    KW_ERR_RUNTIME,                 // 1: General runtime error
    KW_ERR_ARGV,                    // 2: Malformed argument vector
    KW_ERR_MEM                      // 3: Out of memory
} KW_ErrCode;

/**
 * This struct stores a single error state, which consists of an error code,
 * and an error message.
*/
typedef struct __KW_ERRST__ {
    KW_ErrCode code;
    char msg[KW_MAX_ERR_MSG_LEN];
} KW_ErrSt;

/**
 * Initialize a `KW_ErrSt` instance. This function can also be used on 
 * previously initialized instances to reset the error state back to default
 * values.
*/
void KW_initErrSt(KW_ErrSt *err);

/**
 * Set the state of a `KW_ErrSt` instance. Note that only the first
 * `KW_MAX_ERR_MSG_LEN` characters of `msg` will be written to the instance's 
 * message attribute.
*/
void KW_setErrSt(KW_ErrSt *err, KW_ErrCode code, char *msg);

/**
 * Test whether or not a `KW_ErrSt` signals an error condition. That is, whether
 * or not the code attribute is anything aside from `KW_ERR_OK`.
*/
int KW_isErr(KW_ErrSt *err);

/**
 * If a given `KW_ErrSt` signals an error condition, print the error message
 * to `stderr`, then exit the process with the exit-code associated with the
 * error code. If `cb` is not `NULL`, it will be called with the purpose of
 * cleaning up any heap-allocated resources before exiting. 
*/
void KW_fatal(KW_ErrSt *err, KW_CleanCb cb);

/**
 * If a given `KW_ErrSt` signals an error condition, print the error message
 * to `stderr`, and immediately return.
*/
void KW_warn(KW_ErrSt *err);

#endif