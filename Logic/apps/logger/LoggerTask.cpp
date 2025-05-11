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

#include "LoggerTask.h"

#include "FreeRTOS.h"
#include "task.h"
#include "trice.h"

using namespace scilla;

extern "C" {
static void Scilla_LoggerTask_CRun(void* args) {
    (void)args;
    LoggerTask* task = static_cast<LoggerTask*>(LoggerTask::getInstance());

    /* On initialization task might start running immediatly because of how FreeRTOS
     * handles them. Wait here until first start is called */
    while (task->getState() == ETaskState::eNotInitialized);
    while (task->getState() == ETaskState::eSuspended);

    task->_run(NULL);
    task->destroy();
}
}

ETaskStatus LoggerTask::init(const TaskParameters& parameters) {
    if (parameters.stackSize < kMinStackSize) {
        return ETaskStatus::eInvalidParameters;
    }
    mParameters = parameters;
    return baseInit(Scilla_LoggerTask_CRun, "LoggerTask");
}

ETaskStatus LoggerTask::destroy() {
    if (mState == ETaskState::eNotInitialized) {
        return ETaskStatus::eNotInitialized;
    }

    if (mState == ETaskState::eRunning) {
        stop();
    }
    vTaskDelete(mRtosTaskHandle);
    return ETaskStatus::eSuccess;
}

LoggerTask::~LoggerTask() { destroy(); }

void LoggerTask::_run(void* args) {
    (void)args;

    while (true) {
        TriceTransfer();
        vTaskDelay(100);
    }
}

ITask* LoggerTask::getInstance() {
    static LoggerTask instance;
    return &instance;
}
