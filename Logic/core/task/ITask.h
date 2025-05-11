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

#ifndef SCILLA_LOGIC_TASK_I_TASK_H_
#define SCILLA_LOGIC_TASK_I_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "task/ETaskState.h"
#include "task/ETaskStatus.h"
#include "task/TaskParameters.h"

namespace scilla {

using TTaskCallback = void (*)(void*);

struct ITask {
    virtual ETaskStatus init(const TaskParameters& parameters) = 0;
    virtual ETaskStatus destroy() = 0;
    virtual ~ITask() {};

    /**
     * @brief Run loop. "Private", should be called only from FreeRTOS C wrapper
     */
    virtual void _run(void* args) = 0;

    ETaskStatus reset();
    ETaskStatus start();
    ETaskStatus stop();
    ETaskStatus join();
    ETaskState getState();
    ETaskStatus getId(uint8_t& dest);

protected:
    TaskParameters mParameters;
    ETaskState mState = ETaskState::eNotInitialized;
    TaskHandle_t mRtosTaskHandle = NULL;

    ETaskStatus baseInit(TTaskCallback callback, const char* name);
};

}  // namespace scilla

#endif
