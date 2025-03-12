#ifndef CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_E_TIMER_STATE_H_
#define CORE_INCLUDE_SCILLA_CORE_HAL_TIMER_E_TIMER_STATE_H_

namespace scilla::core {

enum class ETimerState {
    eNotInitialized = 0,
    eIdle,
    eRunning,
};

}

#endif
