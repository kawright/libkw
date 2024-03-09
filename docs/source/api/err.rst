.. Copyright (C) 2024  KA Wright

``KW_err.h`` - Error Signaling and Handling
===========================================

The ``KW_err`` header specifies an API for signaling and handling error 
conditions in both ``libkw`` code, and in client code.

Overview
--------

The ``KW_err`` API provides both a canonical way to check and handle error 
conditions while using the ``libkw`` library, and a convenient, flexible way to 
manage errors in client code.

In the ``libkw`` library, functions which might cause an error conditions
will always take a pointer to a ``KW_ErrSt`` instance as the final argument:

.. code-block:: c

    KW_Arr KW_newArr(long sz, KW_ErrSt *err);

After calling such a function, the value of the ``KW_ErrSt`` instance's ``code``
field should be checked to see if an error occurred:

.. code-block:: c

    // Catch all errors...
    if (KW_isErr(&err)) {
        // Perform error handling...
    }

    // Catch specific errors...
    if (err.code == KW_ERR_MEM) {
        // Perform error handling...
    }

For convenience, the ``KW_fatal`` can be used if the error-condition being
checked-for is fatal, and should be handled with a process exit. It prints the 
error message to ``stderr``, optionally calls a cleanup callback function, and 
exits the process with the error code's exit status (i.e. its ``int`` value):

.. code-block:: c

    // Create an error state object on the stack an initialize it:
    KW_ErrSt err;
    KW_initErrSt(&err);

    // Create an empty array. If any error happens, exit immediately:
    KW_Arr myArr = KW_newArr(16, &err);
    KW_fatal(&err, NULL);
    /*
    The above line is equivalent to:
    if (err.code != KW_ERR_OK) {
        fprintf(stderr, "%s\n", err.msg);
        return err.code;
    }
    */

It is recommended that client code use a similar strategy, but this is not
required. Developers can leverage the flexible ``KW_err`` API to implement
whatever error handling strategy they desire. For example, one could return 
error codes directly:

.. code-block:: c 

    KW_ErrCode divide(int a, int b, int *ans) {
        if (b == 0) {
            return KW_ERR_RUNTIME;          // Can't divide by zero
        }
        *ans = a / b;
        return KW_ERR_OK;
    }

Dependencies
------------

This API depends on the following header files:

* :doc:`cb`

Macros
------

.. c:macro:: KW_MAX_ERR_MSG_LEN
    
    The maximum length of an error message. Expands to the ``int`` literal 
    ``127``.

Enums
-----

.. c:enum:: KW_ErrCode

    Stores all supported error codes. The values of the enumerators are the 
    process exit codes used for fatal error condition handling.

    .. c:enumerator:: KW_ERR_OK

        No error has occurred. Value is ``0``.

    .. c:enumerator:: KW_ERR_RUNTIME

        General or uncategorized runtime error. Value is ``1``.

    .. c:enumerator:: KW_ERR_ARGV

        Malformed argument vector given. Value is ``2``.

    .. c:enumerator:: KW_ERR_MEM

        Out of memory. Value is ``3``.

Structs
-------

.. c:struct:: KW_ErrSt

    Stores a single error state, which consists of an error code and message.

    .. c:var:: KW_ErrCode code

        The error code.

    .. c:var:: char msg[KW_MAX_ERR_MSG_LEN]

        The error message.

Functions
---------

.. c:function:: void KW_fatal(KW_ErrSt *err, KW_CleanCb cb)

    If a given ``KW_ErrSt`` signals an error condition, print the ``msg`` field 
    to ``stderr`` and exit the process with the appropriate exit code. If ``cb``
    is not ``NULL``, it will be called to clean heap resources before exit.

.. c:function:: void KW_initErrSt(KW_ErrSt *err)

    Initialize a ``KW_ErrSt`` to ``KW_ERR_OK`` and an empty error message. 
    May also be used on previously initialized instances to reset them back to 
    default state.

.. c:function:: int KW_isErr(KW_ErrSt *err)

    Test whether a ``KW_ErrSt`` signals an error condition--that is, whether the
    ``code`` field is not ``KW_ERR_OK``.

.. c:function:: void KW_setErrSt(KW_ErrSt *err, KW_ErrCode code, char *msg)

    Set the state of a ``KW_ErrSt`` instance. Note that only the first 
    ``KW_MAX_ERR_MSG_LEN`` characters of ``msg`` are copied to the instance's 
    ``msg`` field.

.. c:function:: void KW_warn(KW_ErrSt *err)

    If a given ``KW_ErrSt`` signals an error condition, print the ``msg`` field 
    to ``stderr`` and return.