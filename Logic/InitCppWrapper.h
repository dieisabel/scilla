/* MIT License
 *
 * Copyright (c) 2025 dieisabel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file InitCppWrapper.h
 * @brief Header file for C++ wrapper. By calling Scilla_Initialize firmware goes from C
 * domain to C++
 */

#ifndef SCILLA_LOGIC_INIT_CPP_WRAPPER_H_
#define SCILLA_LOGIC_INIT_CPP_WRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize Scilla. Main purpose of this function is to go from C to C++ domain
 * @param args: arguments
 */
void Scilla_Initialize(void* args);

#ifdef __cplusplus
}
#endif

#endif
