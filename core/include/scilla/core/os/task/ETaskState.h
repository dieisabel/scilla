#ifndef CORE_INCLUDE_SCILLA_CORE_OS_TASK_E_TASK_STATE_H_
#define CORE_INCLUDE_SCILLA_CORE_OS_TASK_E_TASK_STATE_H_

namespace scilla::core {

enum class ETaskState {
    eNotInitialized = 0,
    eIdle,
    eRunning
};

}

#endif
