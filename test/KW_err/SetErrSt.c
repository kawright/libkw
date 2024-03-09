// Copyright (C) 2024  KA Wright

/**
 * Test the behavior of `KW_setErrSt`.
*/

#include <assert.h>
#include <string.h>

#include "KW_err.h"

int main(int argc, char *argv[]) {
    KW_ErrSt err = {KW_ERR_OK, ""};

    KW_setErrSt(&err, KW_ERR_RUNTIME, "Hello");
    assert(err.code == KW_ERR_RUNTIME);
    assert(strcmp(err.msg, "Hello") == 0);
}