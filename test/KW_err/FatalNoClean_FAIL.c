// Copyright (C) 2024  KA Wright

/**
 * Test the behavior of the `KW_fatal` function when called without a cleanup
 * callback.
*/

#include <assert.h>
#include <stdlib.h>

#include "KW_err.h"

int main(int argc, char *argv[]) {
    KW_ErrSt err = {KW_ERR_RUNTIME, "This is a test error message."};
    KW_fatal(&err, NULL);
}