.. Copyright (C) 2024  KA Wright

``build`` - Build Script for Libraries and Test Binaries
========================================================

Build the ``libkw`` static and shared libraries, as well as unit test binaries.

Synopsis
--------

``build [-h] [-c] [-t] [-l]``

Description
-----------

Build static and shared libraries for the ``libkw`` project, as well as unit 
test binaries. Can also be used for cleanup of build artifacts.

Mandartory arguments to long options are mandatory for short options too.

``-h, --help``
    Display the help text.

``-c, --clean``
    Clean up build artifacts.

``-t, --tests-only``
    Only build test binaries.

``-l, --libs-only``
    Only build libraries.

Exit Status
-----------

This binary should always exit with ``0`` status.
