// Copyright (C) 2024  KA Wright

/**
 * This header file contains callback function pointers which are commonly
 * used throughout the KW library API.
*/

#ifndef __KW_CB_H__
#define __KW_CB_H__

/**
 * Callback function which is responsible for cleaning up global heap-allocated
 * resources. 
*/
typedef void (*KW_CleanCb)();

#endif