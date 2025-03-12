#ifndef CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_I_TIMER_H_
#define CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_I_TIMER_H_

#include <cstdint>

#include "scilla/core/hal/timer/ETimerStatus.h"
#include "scilla/core/hal/timer/ITimerSubscriber.h"
#include "scilla/core/hal/timer/ETimerState.h"

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

}

#endif
