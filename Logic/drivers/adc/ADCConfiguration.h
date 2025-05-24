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

#ifndef SCILLA_LOGIC_ADC_A_D_C_CONFIGURATION_H_
#define SCILLA_LOGIC_ADC_A_D_C_CONFIGURATION_H_

#include <cstdint>

#include "ADCBuffer.h"

namespace scilla {

enum class EADCSamplingTime : uint8_t {
    e2_5Cycles = 0,
    e6_5Cycles,
    e12_5Cycles,
    e24_5Cycles,
    e47_5Cycles,
    e92_5Cycles,
    e247_5Cycles,
    e640_5Cycles,
};

enum class EADCResolution : uint8_t {
    e6Bit = 0,
    e8Bit,
    e10Bit,
    e12Bit,
};

enum class EADCChannel : uint8_t {
    eChannel1 = 0,
};

struct ADCConfiguration {
    EADCChannel channel;
    EADCSamplingTime samplingTime;
    EADCResolution resolution;
    uint32_t frequency;

    ADCConfiguration();
    bool isValid() const;
};

}  // namespace scilla

#endif
