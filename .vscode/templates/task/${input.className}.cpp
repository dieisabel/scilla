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

#include "FreeRTOS.h"
#include "task.h"

#include "${input.className}.h"

using namespace scilla;

extern "C" {
static void Scilla_${input.className}_CRun(void* args) {
    (void)args;
    ${input.className}* task = static_cast<${input.className}*>(${input.className}::getInstance());

    /* On initialization task might start running immediatly because of how FreeRTOS
     * handles them. Wait here until first start is called */
    while (task->getState() == ETaskState::eNotInitialized);
    while (task->getState() == ETaskState::eSuspended);

    task->_run(NULL);
    task->destroy();
}
}

ETaskStatus ${input.className}::init(const TaskParameters& parameters) {
    if (parameters.stackSize < kMinStackSize) {
        return ETaskStatus::eInvalidParameters;
    }
    mParameters = parameters;
    return baseInit(Scilla_${input.className}_CRun, "${input.className}");
}

ETaskStatus ${input.className}::destroy() {
    return baseDestroy();
}

${input.className}::~${input.className}() { destroy(); }

void ${input.className}::_run(void* args) {
    (void)args;

    while (true) {}
}

ITask* ${input.className}::getInstance() {
    static ${input.className} instance;
    return &instance;
}
