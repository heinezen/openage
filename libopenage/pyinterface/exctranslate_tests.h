// Copyright 2015-2024 the openage authors. See copying.md for legal info.

#pragma once

// pxd: from libopenage.pyinterface.functional cimport PyIfFunc0, PyIfFunc2, Func0
#include "functional.h"

namespace openage {
namespace pyinterface {
namespace tests {


/**
 * Called by cppinterface.demo_cpp_to_py.
 * Throws some exceptions, for translation to Python.
 *
 * pxd: void err_cpp_to_py_helper() except +
 */
OAAPI void err_cpp_to_py_helper();


/**
 * Part of pyinterface::demo_py_to_cpp.
 * Shall throw some exceptions, which we then translate to C++.
 *
 * pxd: PyIfFunc0[int] err_py_to_cpp_helper
 */
extern OAAPI PyIfFunc<int> err_py_to_cpp_helper;


/**
 * See the doc in exctranslate_tests.pyx.
 *
 * pxd: void bounce_call(Func0[int], int) except +
 */
OAAPI void bounce_call(const Func<int> &func, int times);


/**
 * Called by bounce_call() to bounce back to Python.
 *
 * pxd: PyIfFunc2[int, Func0[int], int] bounce_call_py
 */
extern OAAPI PyIfFunc<int, Func<int>, int> bounce_call_py;


} // namespace tests
} // namespace pyinterface
} // namespace openage
