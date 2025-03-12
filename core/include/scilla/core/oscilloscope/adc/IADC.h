#ifndef CORE_INCLUDE_SCILLA_CORE_OSCILLOSCOPE_ADC_I_A_D_C_H_
#define CORE_INCLUDE_SCILLA_CORE_OSCILLOSCOPE_ADC_I_A_D_C_H_

#include <cstdint>

#include "scilla/core/oscilloscope/adc/EADCState.h"
#include "scilla/core/oscilloscope/adc/EADCStatus.h"

namespace scilla::core {

struct IADC {
    virtual EADCStatus init() = 0;
    virtual ~IADC() {}
    virtual EADCStatus reset() = 0;
    virtual EADCStatus singleConvert(uint8_t channel, uint32_t& dest) = 0;
    virtual EADCState getState() = 0;
};

}

#endif
