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

#ifndef SCILLA_CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_I_TIMER_H_
#define SCILLA_CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_I_TIMER_H_

#include <cstdint>

#include "scilla/core/hal/timer/ETimerState.h"
#include "scilla/core/hal/timer/ETimerStatus.h"
#include "scilla/core/hal/timer/ITimerSubscriber.h"

namespace scilla::core {

struct ITimer {
    virtual ETimerStatus init() = 0;
    virtual ~ITimer() {}
    virtual ETimerStatus reset() = 0;
    virtual ETimerStatus start() = 0;
    virtual ETimerStatus stop() = 0;
    virtual ETimerStatus setInterval(uint32_t interval) = 0;
    virtual ETimerStatus getInterval(uint32_t& dest) = 0;
    virtual ETimerStatus getTicks(uint32_t& dest) = 0;
    virtual ETimerState getState() = 0;
    virtual ETimerStatus addSubscriber(ITimerSubscriber* subscriber) = 0;
    virtual ETimerStatus removeSubscriber(ITimerSubscriber* subscriber) = 0;
    virtual ETimerStatus notify() = 0;
    virtual void processFromISR() = 0;
};

}  // namespace scilla::core

#endif
