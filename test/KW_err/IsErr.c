// Copyright (C) 2024  KA Wright

/**
 * Test the behavior of `KW_isErr`.
*/

#include <assert.h>

#include "KW_err.h"

int main(int argc, char *argv[]) {
    KW_ErrSt err = { KW_ERR_OK, "" };
    assert(!KW_isErr(&err));

    err.code = KW_ERR_RUNTIME;
    assert(KW_isErr(&err));
}