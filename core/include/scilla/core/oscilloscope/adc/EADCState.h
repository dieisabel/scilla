#ifndef CORE_INCLUDE_SCILLA_CORE_OSCILLOSCOPE_ADC_E_A_D_C_STATE_H_
#define CORE_INCLUDE_SCILLA_CORE_OSCILLOSCOPE_ADC_E_A_D_C_STATE_H_

namespace scilla::core {

enum class EADCState {
    eNotInitialized = 0,
    eIdle,
    eConverting,
};

}

#endif
