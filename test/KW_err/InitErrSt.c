// Copyright (C) 2024  KA Wright

/**
 * Test the behavior of the `KW_initErrSt` function--both on a newly created
 * instance, and an existing instance to reset the updated state back to
 * default values.
*/

#include <assert.h>
#include <string.h>

#include "KW_err.h"

int main(int arc, char *argv[]) {
    KW_ErrSt err;

    // Test on new instance
    KW_initErrSt(&err);
    assert(err.code == KW_ERR_OK);
    assert(strcmp(err.msg, "") == 0);

    // Test on existing, non-default instance
    err.code = KW_ERR_RUNTIME;
    strcpy(err.msg, "Hello, world");
    assert(err.code == KW_ERR_RUNTIME);
    assert(strcmp(err.msg, "Hello, world") == 0);
    KW_initErrSt(&err);
    assert(err.code == KW_ERR_OK);
    assert(strcmp(err.msg, "") == 0);

    return err.code;
}