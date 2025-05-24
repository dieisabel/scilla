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

#include "InitializationTask.h"

#include <cstdint>
#include <cstring>

#include "Drivers.h"
#include "HeartbeatTask.h"
#include "LoggerTask.h"
#include "OscilloscopeTask.h"
#include "OscilloscopeTaskParameters.h"

using namespace scilla;

static StaticTask_t InitializationTask_TaskTCBBuffer;
static TaskHandle_t InitializationTask_TaskHandle = nullptr;
static constexpr uint32_t InitializationTask_StackSize = 128;
static StackType_t InitializationTask_Stack[InitializationTask_StackSize] = {0};

static constexpr uint32_t HeartbeatTask_StackSize = 128;
static StackType_t HeartbeatTask_Stack[HeartbeatTask_StackSize] = {0};
static void HeartbeatTask_Init();

static constexpr uint32_t LoggerTask_StackSize = 128;
static StackType_t LoggerTask_Stack[LoggerTask_StackSize] = {0};
static void LoggerTask_Init();

static constexpr uint32_t OscilloscopeTask_StackSize = 128;
static StackType_t OscilloscopeTask_Stack[OscilloscopeTask_StackSize] = {0};
static void OscilloscopeTask_Init();

extern "C" {

void Scilla_InitializationTask_Init(void* arg) {
    (void)arg;
    std::memset(InitializationTask_Stack, 0,
                InitializationTask_StackSize * sizeof(StackType_t));
    InitializationTask_TaskHandle =
        xTaskCreateStatic(Scilla_InitializationTask_CRun, "InitializationTask",
                          InitializationTask_StackSize, NULL, 55,
                          InitializationTask_Stack, &InitializationTask_TaskTCBBuffer);
}

void Scilla_InitializationTask_CRun(void* arg) {
    (void)arg;

    LoggerTask_Init();
    HeartbeatTask_Init();
    OscilloscopeTask_Init();

    vTaskSuspend(InitializationTask_TaskHandle);
    while (1); /* Safeguard in case someone tries to unsuspend task */
}
}

static void HeartbeatTask_Init() {
    std::memset(HeartbeatTask_Stack, 0, HeartbeatTask_StackSize * sizeof(StackType_t));

    TaskParameters parameters;
    parameters.priority = 21;
    parameters.stackSize = HeartbeatTask_StackSize;
    parameters.stackBuffer = HeartbeatTask_Stack;
    parameters.name = "HeartbeatTask";
    parameters.other = nullptr;

    ITask* task = HeartbeatTask::getInstance();
    if (task->init(parameters) == ETaskStatus::eSuccess) {
        task->start();
    }
}

static void LoggerTask_Init() {
    std::memset(LoggerTask_Stack, 0, LoggerTask_StackSize * sizeof(StackType_t));

    TaskParameters parameters;
    parameters.priority = 21;
    parameters.stackSize = LoggerTask_StackSize;
    parameters.stackBuffer = LoggerTask_Stack;
    parameters.name = "LoggerTask";
    parameters.other = nullptr;

    ITask* task = LoggerTask::getInstance();
    if (task->init(parameters) == ETaskStatus::eSuccess) {
        task->start();
    }
}

static void OscilloscopeTask_Init() {
    std::memset(OscilloscopeTask_Stack, 0,
                OscilloscopeTask_StackSize * sizeof(StackType_t));

    OscilloscopeTaskParameters specificParameters;
    specificParameters.adcDriver = &drivers::gSTM32ADC2Driver;

    TaskParameters parameters;
    parameters.priority = 21;
    parameters.stackSize = OscilloscopeTask_StackSize;
    parameters.stackBuffer = OscilloscopeTask_Stack;
    parameters.name = "OscilloscopeTask";
    parameters.other = &specificParameters;

    ITask* task = OscilloscopeTask::getInstance();
    if (task->init(parameters) == ETaskStatus::eSuccess) {
        task->start();
    }
}
