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

#include "ITask.h"

#include "trice.h"

using namespace scilla;

ETaskStatus ITask::baseInit(TTaskCallback callback, const char* name) {
    if (name == nullptr) {
        return ETaskStatus::eInvalidParameters;
    }

    BaseType_t status =
        xTaskCreate(callback, name, mParameters.stackSize, NULL, mParameters.priority,
                    &mRtosTaskHandle); /* TODO: Allocate static buffer for task */
    if (status != pdPASS) {
        return ETaskStatus::eError;
    }
    vTaskSuspend(mRtosTaskHandle);
    mName = name;
    mState = ETaskState::eSuspended;
    return ETaskStatus::eSuccess;
}

ETaskStatus ITask::baseDestroy() {
    if (mState == ETaskState::eNotInitialized) {
        return ETaskStatus::eNotInitialized;
    }
    if (mState == ETaskState::eRunning) {
        stop();
    }
    vTaskDelete(mRtosTaskHandle);
    return ETaskStatus::eSuccess;
}

ETaskStatus ITask::reset() {
    if (mState == ETaskState::eNotInitialized) {
        return ETaskStatus::eNotInitialized;
    }
    destroy();
    mState = ETaskState::eNotInitialized;
    return ETaskStatus::eSuccess;
}

ETaskStatus ITask::start() {
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

ETaskStatus ITask::stop() {
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

ETaskStatus ITask::join() { return ETaskStatus::eNotImplemented; }

ETaskState ITask::getState() { return mState; }

ETaskStatus ITask::getId(uint8_t& dest) {
    (void)dest;
    return ETaskStatus::eNotImplemented;
}
