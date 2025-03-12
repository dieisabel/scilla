#ifndef CORE_INCLUDE_SCILLA_CORE_OS_TASK_I_TASK_H_
#define CORE_INCLUDE_SCILLA_CORE_OS_TASK_I_TASK_H_

#include "scilla/core/os/task/ETaskState.h"
#include "scilla/core/os/task/ETaskStatus.h"
#include "scilla/core/os/task/TaskParameters.h"

namespace scilla::core {

struct ITask {
    virtual ETaskStatus init(const TaskParameters& parameters) = 0;
    virtual ~ITask() {};
    virtual ETaskStatus reset() = 0;
    virtual ETaskStatus start() = 0;
    virtual ETaskStatus stop() = 0;
    virtual ETaskStatus join() = 0;
    virtual ETaskState getState() = 0;
    virtual ETaskStatus getId(uint8_t& dest) = 0;
};

}

#endif
