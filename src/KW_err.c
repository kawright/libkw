// Copyright (C) 2024  KA Wright

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "KW_err.h"

void KW_initErrSt(KW_ErrSt *err) {
    err->code = KW_ERR_OK;
    strcpy(err->msg, "");
}

void KW_setErrSt(KW_ErrSt *err, KW_ErrCode code, char *msg) {
    err->code = code;
    strncpy(err->msg, msg, KW_MAX_ERR_MSG_LEN);
}

int KW_isErr(KW_ErrSt *err) {
    return err->code != KW_ERR_OK;
}

void KW_fatal(KW_ErrSt *err, KW_CleanCb cb) {
    if (KW_isErr(err)) {
        fprintf(stderr, "%s\n", err->msg);
        if (cb != NULL) {
            cb();
        }
        exit(err->code);
    }
}

void KW_warn(KW_ErrSt *err) {
    fprintf(stderr, "%s\n", err->msg);
}
