// Copyright (C) 2024  KA Wright

/**
 * Test that the `KW_MAX_ERR_MSG_LEN` macro expands to the expected value.
*/

#include <assert.h>

#include "KW_err.h"

int main(int argc, char *argv[]) {
    assert(KW_MAX_ERR_MSG_LEN == 127);

    return 0;
}