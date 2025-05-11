/* MIT License
 *
 * Copyright (c) 2025 dieisabel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SCILLA_LOGIC_ADC_I_A_D_C_H_
#define SCILLA_LOGIC_ADC_I_A_D_C_H_

#include <cstdint>

#include "ADCConfiguration.h"
#include "EADCState.h"
#include "EADCStatus.h"

namespace scilla {

/* TODO: Implement error handling */
/* TODO: Implement event handling */
struct IADC {
    virtual EADCStatus init() = 0;
    virtual ~IADC() {}
    virtual EADCStatus reset() = 0;
    virtual EADCStatus start() = 0;
    virtual EADCStatus stop() = 0;

protected:
    EADCState mState = EADCState::eNotInitialized;
    ADCConfiguration mConfiguration;

    EADCState getState();

    EADCStatus setConfiguration(const ADCConfiguration& configuration);
    EADCStatus getConfiguration(ADCConfiguration& dest);

    EADCStatus setChannel(EADCChannel channel);
    EADCStatus getChannel(EADCChannel& dest);

    EADCStatus setSamplingTime(EADCSamplingTime samplingTime);
    EADCStatus getSamplingTime(EADCSamplingTime& dest);

    EADCStatus setResolution(EADCResolution resolution);
    EADCStatus getResolution(EADCResolution& dest);

    EADCStatus setFrequency(uint32_t frequency);
    EADCStatus getFrequency(uint32_t& dest);
};

}  // namespace scilla

#endif
