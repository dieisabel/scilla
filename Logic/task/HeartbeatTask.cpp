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
#include "stm32g4xx_ll_usart.h"
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
    BaseType_t status =
        xTaskCreate(Scilla_HeartbeatTask_CRun, "HeartbeatTask", mParameters.stackSize,
                    NULL, mParameters.priority,
                    &mRtosTaskHandle); /* TODO: Allocate static buffer for task */
    if (status != pdPASS) {
        return ETaskStatus::eError;
    }
    vTaskSuspend(mRtosTaskHandle);
    mState = ETaskState::eSuspended;
    return ETaskStatus::eSuccess;
}

ETaskStatus HeartbeatTask::destroy() {
    if (mState == ETaskState::eNotInitialized) {
        return ETaskStatus::eNotInitialized;
    }

    if (mState == ETaskState::eRunning) {
        stop();
    }
    vTaskDelete(mRtosTaskHandle);
    return ETaskStatus::eSuccess;
}

HeartbeatTask::~HeartbeatTask() { destroy(); }

ETaskStatus HeartbeatTask::reset() {
    if (mState == ETaskState::eNotInitialized) {
        return ETaskStatus::eNotInitialized;
    }
    destroy();
    mState = ETaskState::eNotInitialized;
    return ETaskStatus::eSuccess;
}

ETaskStatus HeartbeatTask::start() {
    switch (mState) {
        case ETaskState::eSuspended:
            vTaskResume(mRtosTaskHandle);
            mState = ETaskState::eRunning;
            return ETaskStatus::eSuccess;
        case ETaskState::eNotInitialized:
            return ETaskStatus::eNotInitialized;
        case ETaskState::eRunning:
            return ETaskStatus::eAlreadyStarted;
        default:
            return ETaskStatus::eError;
    }
    return ETaskStatus::eError;
}

ETaskStatus HeartbeatTask::stop() {
    switch (mState) {
        case ETaskState::eRunning:
            vTaskSuspend(mRtosTaskHandle);
            mState = ETaskState::eSuspended;
            return ETaskStatus::eSuccess;
        case ETaskState::eNotInitialized:
            return ETaskStatus::eNotInitialized;
        case ETaskState::eSuspended:
            return ETaskStatus::eNotStarted;
        default:
            return ETaskStatus::eError;
    }
    return ETaskStatus::eError;
}

void HeartbeatTask::_run(void* args) {
    (void)args;

    while (true) {
        trice(iD(4099), "Hello\n");
        BSP_LED_Off(LED_GREEN);
        vTaskDelay(pdMS_TO_TICKS(1000));

        trice(iD(3073), "Hello\n");
        BSP_LED_On(LED_GREEN);
        vTaskDelay(pdMS_TO_TICKS(1000));

        TriceTransfer();
        vTaskDelay(100);
    }
}

ETaskStatus HeartbeatTask::join() { return ETaskStatus::eNotImplemented; }

ETaskState HeartbeatTask::getState() { return mState; }

ETaskStatus HeartbeatTask::getId(uint8_t& dest) {
    (void)dest;
    return ETaskStatus::eNotImplemented;
}

ITask* HeartbeatTask::getInstance() {
    static HeartbeatTask instance;
    return &instance;
}
