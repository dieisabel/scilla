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

#ifndef SCILLA_CORE_INCLUDE_SCILLA_CORE_OS_TASK_I_TASK_H_
#define SCILLA_CORE_INCLUDE_SCILLA_CORE_OS_TASK_I_TASK_H_

#include "scilla/core/os/task/ETaskState.h"
#include "scilla/core/os/task/ETaskStatus.h"
#include "scilla/core/os/task/TaskParameters.h"

namespace scilla::core {

struct ITask {
    virtual ETaskStatus init(const TaskParameters& parameters) = 0;
    virtual ~ITask() {};
    virtual ETaskStatus reset() = 0;
    virtual ETaskStatus start() = 0;
    virtual ETaskStatus stop() = 0;
    virtual ETaskStatus join() = 0;
    virtual ETaskState getState() = 0;
    virtual ETaskStatus getId(uint8_t& dest) = 0;
};

}  // namespace scilla::core

#endif
