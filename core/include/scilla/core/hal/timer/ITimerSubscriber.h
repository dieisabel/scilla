#ifndef CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_I_TIMER_SUBSCRIBER_H_
#define CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_I_TIMER_SUBSCRIBER_H_

namespace scilla::core {

struct ITimerSubscriber {
    virtual void processTimeoutEvent() = 0;
};

}

#endif
