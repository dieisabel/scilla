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

#ifndef SCILLA_LOGIC_APPS_LOGGER_LOGGER_TASK_H_
#define SCILLA_LOGIC_APPS_LOGGER_LOGGER_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "task/ITask.h"

namespace scilla {

struct LoggerTask : public ITask {
    virtual ETaskStatus init(const TaskParameters& parameters) override;
    virtual ETaskStatus destroy() override;
    virtual ~LoggerTask() override;
    virtual ETaskStatus reset() override;
    virtual ETaskStatus start() override;
    virtual ETaskStatus stop() override;
    virtual ETaskStatus join() override;
    virtual ETaskState getState() override;
    virtual ETaskStatus getId(uint8_t& dest) override;

    static ITask* getInstance();

    /**
     * @brief Run loop. "Private", should be called from FreeRTOS C wrapper
     */
    void _run(void* args);

private:
    TaskParameters mParameters;
    ETaskState mState = ETaskState::eNotInitialized;
    TaskHandle_t mRtosTaskHandle;
    static constexpr uint8_t kMinStackSize = 128;
};

}  // namespace scilla

#endif
