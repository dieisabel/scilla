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

#include "STM32ADC.h"

using namespace scilla;

bool STM32ADC::setSpecificConfiguration(const STM32ADCConfiguration& configuration) {
    if (mState == EADCState::eConverting) {
        return false;
    }
    mSpecificConfiguration = configuration;
    return true;
}

void STM32ADC::getSpecificConfiguration(STM32ADCConfiguration& dest) {
    dest = mSpecificConfiguration;
}

EADCStatus STM32ADC::applyConfiguration() { return EADCStatus::eNotImplemented; }

EADCStatus STM32ADC::init() {
    if (mSpecificConfiguration.isValid() == false) {
        return EADCStatus::eErrorInvalidParameter;
    }
    if (HAL_ADC_GetState(mSpecificConfiguration.adcHalHandle) != HAL_ADC_STATE_READY) {
        return EADCStatus::eErrorInvalidParameter;
    }
    if (HAL_TIM_Base_GetState(mSpecificConfiguration.timHalHandle) !=
        HAL_TIM_STATE_READY) {
        return EADCStatus::eErrorInvalidParameter;
    }

    (void)stop();
    mState = EADCState::eIdle;
    return EADCStatus::eSuccess;
}

EADCStatus STM32ADC::reset() {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    (void)stop();
    mState = EADCState::eNotInitialized;
    return EADCStatus::eSuccess;
}

EADCStatus STM32ADC::start() {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    if (mState == EADCState::eConverting) {
        return EADCStatus::eErrorStarted;
    }
    if (mConfiguration.isValid() == false) {
        return EADCStatus::eErrorInvalidParameter;
    }
    if (mBuffer.isValid() == false) {
        return EADCStatus::eErrorInvalidParameter;
    }

    HAL_StatusTypeDef status =
        HAL_ADC_Start_DMA(mSpecificConfiguration.adcHalHandle,
                          reinterpret_cast<uint32_t*>(mBuffer.ptr), mBuffer.size);
    if (status != HAL_OK) {
        return EADCStatus::eError;
    }

    status = HAL_TIM_Base_Start(mSpecificConfiguration.timHalHandle);
    if (status != HAL_OK) {
        (void)HAL_ADC_Stop_DMA(mSpecificConfiguration.adcHalHandle);
        return EADCStatus::eError;
    }

    mState = EADCState::eConverting;
    return EADCStatus::eSuccess;
}

EADCStatus STM32ADC::stop() {
    if (mState == EADCState::eNotInitialized) {
        return EADCStatus::eNotInitialized;
    }
    if (mState == EADCState::eIdle) {
        return EADCStatus::eNotStarted;
    }

    /* To stop timer HAL just modifies some registers, this function cannot return
     * something other than HAL_OK */
    (void)HAL_TIM_Base_Stop(mSpecificConfiguration.timHalHandle);
    HAL_StatusTypeDef status = HAL_ADC_Stop_DMA(mSpecificConfiguration.adcHalHandle);
    if (status != HAL_OK) {
        return EADCStatus::eError;
    }
    return EADCStatus::eSuccess;
}
