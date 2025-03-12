#ifndef CORE_INCLUDE_SCILLA_CORE_OS_TASK_TASK_PARAMETERS_H_
#define CORE_INCLUDE_SCILLA_CORE_OS_TASK_TASK_PARAMETERS_H_

#include <cstdint>

namespace scilla::core {

struct TaskParameters {
    uint8_t priority;
    uint32_t memorySize;
    void (*function)();
    void* other;
};

}

#endif
