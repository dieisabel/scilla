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

#include "adc/IADC.h"

using namespace scilla;

EADCState IADC::getState() { return mState; }

EADCStatus IADC::setConfiguration(const ADCConfiguration& configuration) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    if (mState == EADCState::eConverting) {
        return EADCStatus::eErrorStarted;
    }

    mConfiguration = configuration;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::getConfiguration(ADCConfiguration& dest) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }

    dest = mConfiguration;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::setChannel(EADCChannel channel) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    if (mState == EADCState::eConverting) {
        return EADCStatus::eErrorStarted;
    }

    mConfiguration.channel = channel;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::getChannel(EADCChannel& dest) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }

    dest = mConfiguration.channel;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::setSamplingTime(EADCSamplingTime samplingTime) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    if (mState == EADCState::eConverting) {
        return EADCStatus::eErrorStarted;
    }

    mConfiguration.samplingTime = samplingTime;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::getSamplingTime(EADCSamplingTime& dest) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }

    dest = mConfiguration.samplingTime;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::setResolution(EADCResolution resolution) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    if (mState == EADCState::eConverting) {
        return EADCStatus::eErrorStarted;
    }

    mConfiguration.resolution = resolution;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::getResolution(EADCResolution& dest) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }

    dest = mConfiguration.resolution;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::setFrequency(uint32_t frequency) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    if (mState == EADCState::eConverting) {
        return EADCStatus::eErrorStarted;
    }

    mConfiguration.frequency = frequency;
    return EADCStatus::eSuccess;
}

EADCStatus IADC::getFrequency(uint32_t& dest) {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }

    dest = mConfiguration.frequency;
    return EADCStatus::eSuccess;
}
