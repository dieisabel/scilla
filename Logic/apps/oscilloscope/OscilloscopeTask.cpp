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

    /* WARNING! Unsafe cast! */
    OscilloscopeTaskParameters* specificParameters =
        reinterpret_cast<OscilloscopeTaskParameters*>(parameters.other);
    if (specificParameters->isValid() == false) {
        trice(iD(7752), "err:[OscilloscopeTask]: invalid specific parameters\n");
        return ETaskStatus::eInvalidParameters;
    }
    if (specificParameters->adcDriver->getState() != EADCState::eIdle) {
        trice(iD(6549), "err:[OscilloscopeTask]: ADC driver is not initialized\n");
        return ETaskStatus::eInvalidParameters;
    }

    mSpecificParameters = *specificParameters;
    mParameters = parameters;
    mAdcDriver = mSpecificParameters.adcDriver;

    mAdcBuffer.size = kAdcBufferSize;
    mAdcBuffer.ptr = mAdcBufferMemory;

    mAdcConfiguration.channel = EADCChannel::eChannel1;
    mAdcConfiguration.frequency = 1;
    mAdcConfiguration.resolution = EADCResolution::e12Bit;
    mAdcConfiguration.samplingTime = EADCSamplingTime::e12_5Cycles;

    /* We already checked ADC driver state */
    (void)mAdcDriver->setBuffer(mAdcBuffer);
    (void)mAdcDriver->setConfiguration(mAdcConfiguration);

    return baseInit(Scilla_OscilloscopeTask_CRun);
}

ETaskStatus OscilloscopeTask::destroy() { return baseDestroy(); }

OscilloscopeTask::~OscilloscopeTask() { destroy(); }

void OscilloscopeTask::_run(void* args) {
    (void)args; /* Specific parameters are already located in mSpecificParameters */

    if (mSpecificParameters.adcDriver->start() != EADCStatus::eSuccess) {
        trice(iD(2971), "err:[OscilloscopeTask]: ADC is not started\n");
        suspend();
    }

    while (true) {
    }
}

ITask* OscilloscopeTask::getInstance() {
    static OscilloscopeTask instance;
    return &instance;
}
