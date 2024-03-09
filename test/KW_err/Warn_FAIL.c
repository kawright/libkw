// Copyright (C) 2024  KA Wright

/**
 * Test the behavior of `KW_Warn`. Note that this test uses the `FAIL` tag so
 * that the warning message is shown from the test runner.
*/

#include "KW_err.h"

int main(int argc, char *argv[]) {
    KW_ErrSt err = {KW_ERR_RUNTIME, "This is a test error"};
    KW_warn(&err);

    return 1;
}