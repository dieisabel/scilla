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

#include "OscilloscopeTask.h"

#include "FreeRTOS.h"
#include "task.h"
#include "trice.h"

using namespace scilla;

extern "C" {
static void Scilla_OscilloscopeTask_CRun(void* args) {
    (void)args;
    OscilloscopeTask* task =
        static_cast<OscilloscopeTask*>(OscilloscopeTask::getInstance());

    /* On initialization task might start running immediatly because of how FreeRTOS
     * handles them. Wait here until first start is called */
    while (task->getState() == ETaskState::eNotInitialized);
    while (task->getState() == ETaskState::eSuspended);

    task->_run(NULL);
    task->destroy();
}
}

ETaskStatus OscilloscopeTask::init(const TaskParameters& parameters) {
    if (parameters.stackSize < kMinStackSize) {
        return ETaskStatus::eInvalidParameters;
    }
    mParameters = parameters;
    return baseInit(Scilla_OscilloscopeTask_CRun);
}

ETaskStatus OscilloscopeTask::destroy() { return baseDestroy(); }

OscilloscopeTask::~OscilloscopeTask() { destroy(); }

void OscilloscopeTask::_run(void* args) {
    (void)args;

    while (true) {
    }
}

ITask* OscilloscopeTask::getInstance() {
    static OscilloscopeTask instance;
    return &instance;
}
