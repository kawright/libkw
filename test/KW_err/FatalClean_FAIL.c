// Copyright (C) 2024  KA Wright

/**
 * Test the behavior of `KW_fatal` with a cleanup callback.
*/

#include <assert.h>
#include <stdlib.h>

#include "KW_err.h"

char *globalStr = NULL;

void cleanup(){
    if (globalStr != NULL) {
        free(globalStr);
    }
}

int main(int argc, char *argv[]) {
    globalStr = malloc(8);
    assert(globalStr != NULL);

    KW_ErrSt err = {KW_ERR_RUNTIME, "This is a test error message."};
    KW_fatal(&err, &cleanup);
}