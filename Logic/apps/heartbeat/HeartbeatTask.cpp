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

#include "HeartbeatTask.h"

#include "FreeRTOS.h"
#include "stm32g4xx_nucleo.h"
#include "task.h"
#include "trice.h"

using namespace scilla;

extern "C" {
static void Scilla_HeartbeatTask_CRun(void* args) {
    (void)args;
    HeartbeatTask* task = static_cast<HeartbeatTask*>(HeartbeatTask::getInstance());

    /* On initialization task might start running immediatly because of how FreeRTOS
     * handles them. Wait here until first start is called */
    while (task->getState() == ETaskState::eNotInitialized);
    while (task->getState() == ETaskState::eSuspended);

    task->_run(NULL);
    task->destroy();
}
}

ETaskStatus HeartbeatTask::init(const TaskParameters& parameters) {
    if (parameters.stackSize < kMinStackSize) {
        return ETaskStatus::eInvalidParameters;
    }
    mParameters = parameters;
    return baseInit(Scilla_HeartbeatTask_CRun, "HeartbeatTask");
}

ETaskStatus HeartbeatTask::destroy() { return baseDestroy(); }

HeartbeatTask::~HeartbeatTask() { destroy(); }

void HeartbeatTask::_run(void* args) {
    (void)args;

    while (true) {
        trice(iD(5369), "Beat\n");
        BSP_LED_Off(LED_GREEN);
        vTaskDelay(pdMS_TO_TICKS(1000));

        trice(iD(2015), "Beat\n");
        BSP_LED_On(LED_GREEN);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

ITask* HeartbeatTask::getInstance() {
    static HeartbeatTask instance;
    return &instance;
}
