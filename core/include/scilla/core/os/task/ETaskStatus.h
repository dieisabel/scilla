#ifndef CORE_INCLUDE_SCILLA_CORE_OS_TASK_E_TASK_STATUS_H_
#define CORE_INCLUDE_SCILLA_CORE_OS_TASK_E_TASK_STATUS_H_

namespace scilla::core {

enum class ETaskStatus {
    eNotInitialized = 0,
    eSuccess,
    eError,
    eNotStarted,
    eAlreadyStarted,
    eInvalidParameters,
    eNotImplemented
};

}

#endif
