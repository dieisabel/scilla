#ifndef CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_E_TIMER_STATUS_H_
#define CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_E_TIMER_STATUS_H_

namespace scilla::core {

enum class ETimerStatus {
    eNotInitialized = 0,
    eSuccess,
    eError,
    eSubscriberAlreadyInList,
    eSubscriberNotFound,
    eIntervalNotSupported,
    eNotImplemented,
};

}

#endif
