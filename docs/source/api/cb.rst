.. Copyright (C) 2024  KA Wright

``KW_cb.h`` - Callback Function Pointers
========================================

The ``KW_cb`` headers contains function pointers to callback functions commonly
used throughout  the ``libkw`` public API.

Function Pointers
-----------------

.. c:type:: void (*KW_CleanCb)()

    Responsible for cleaning global heap-allocated resources.