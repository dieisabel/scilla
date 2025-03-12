#ifndef CORE_INCLUDE_SCILLA_CORE_OSCILLOSCOPE_ADC_E_A_D_C_STATUS_H_
#define CORE_INCLUDE_SCILLA_CORE_OSCILLOSCOPE_ADC_E_A_D_C_STATUS_H_

namespace scilla::core {

enum class EADCStatus {
    eNotInitialized = 0,
    eSuccess,
    eError,
    eChannelNotSupported,
    eNotImplemented,
};

}

#endif
