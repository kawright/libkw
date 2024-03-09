.. Copyright (C) 2024  KA Wright

``runtests`` - Unit Test Runner
===============================

Run unit test binaries and report the results.

Synopsis
--------

``runtests``

Description
-----------

This script runs all of the unit test binaries in the ``build/test`` folder.
All tests will be run without any options. Tests which exit with status code
``0`` will be considered a PASS--all other status codes will be considered
a FAIL. For all tests with the substring ``FAIL`` in the filename, the condition
is opposite such that ``0`` is a FAIL et cetera.

Exit Status
-----------

This binary should exit with ``0`` status, but may exit with status ``1`` if
the test binaries could not be accessed (hint: run ``script/build`` and try 
again).