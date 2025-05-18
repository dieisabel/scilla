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

ETaskStatus ITask::baseInit(TTaskCallback callback) {
    if (mParameters.name == nullptr) {
        trice(iD(6927), "err: invalid name\n");
        return ETaskStatus::eInvalidParameters;
    }
    if (mParameters.stackBuffer == nullptr) {
        TRICE_S(id(3860), "err:[%s]: stack buffer is nullptr\n", mParameters.name);
        return ETaskStatus::eInvalidParameters;
    }
    /* Stack size must be validated by derived class */

    mRtosTaskHandle = xTaskCreateStatic(callback, mParameters.name, mParameters.stackSize,
                                        NULL, mParameters.priority,
                                        mParameters.stackBuffer, &mRtosTaskTCBBuffer);
    if (mRtosTaskHandle == NULL) {
        TRICE_S(id(2759), "err:[%s]: task initialization error\n", mParameters.name);
        return ETaskStatus::eError;
    }
    vTaskSuspend(mRtosTaskHandle);
    mState = ETaskState::eSuspended;
    TRICE_S(id(6008), "info:[%s]: task is initialized\n", mParameters.name);
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
    TRICE_S(id(3753), "info:[%s]: task is deleted\n", mParameters.name);
    return ETaskStatus::eSuccess;
}

ETaskStatus ITask::reset() {
    if (mState == ETaskState::eNotInitialized) {
        return ETaskStatus::eNotInitialized;
    }
    destroy();
    mState = ETaskState::eNotInitialized;
    TRICE_S(id(4863), "info:[%s]: task state is changed to eNotInitialized\n",
            mParameters.name);
    return ETaskStatus::eSuccess;
}

ETaskStatus ITask::start() {
    switch (mState) {
        case ETaskState::eSuspended:
            vTaskResume(mRtosTaskHandle);
            mState = ETaskState::eRunning;
            TRICE_S(id(5021), "info:[%s]: task state is changed to eRunning\n",
                    mParameters.name);
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
            TRICE_S(id(1198), "info:[%s]: task state is changed to eSuspended\n",
                    mParameters.name);
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
