# Copyright (C) 2024  KA Wright

"""Manifest of all object files and test executables"""

objs = [
    "KW_err"
]

tests = {
    "KW_err": [
        "ErrCode",
        "FatalClean_FAIL",
        "FatalNoClean_FAIL",
        "InitErrSt",
        "IsErr",
        "MaxErrMsgLen",
        "SetErrSt",
        "Warn_FAIL"
    ]
}