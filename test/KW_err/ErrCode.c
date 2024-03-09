// Copyright (C) 2024  KA Wright

/**
 * Test that the values of the `KW_ErrCode` enum are correct.
*/

#include <assert.h>

#include "KW_err.h"

int main(int argc, char *argv[]) {
    assert(KW_ERR_OK == 0);
    assert(KW_ERR_RUNTIME == 1);
    assert(KW_ERR_ARGV == 2);
    assert(KW_ERR_MEM == 3);

    return 0;
}