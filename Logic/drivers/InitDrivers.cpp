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

#include "InitDrivers.h"

#include "Drivers.h"
#include "trice.h"

using namespace scilla;

static void STM32ADC2_Init();

STM32ADC drivers::gSTM32ADC2Driver;

void scilla::Drivers_Init() { STM32ADC2_Init(); }

static void STM32ADC2_Init() {
    STM32ADCConfiguration specificConfiguration;
    specificConfiguration.adcHalHandle = &hadc2;
    specificConfiguration.timHalHandle = &htim3;

    ADCConfiguration baseConfiguration;

    (void)drivers::gSTM32ADC2Driver.setSpecificConfiguration(specificConfiguration);
    (void)drivers::gSTM32ADC2Driver.setConfiguration(baseConfiguration);
    if (drivers::gSTM32ADC2Driver.init() == EADCStatus::eSuccess) {
        trice(iD(3042), "error:[Drivers_Init]: STM32ADC2 driver is not initialized\n");
    } else {
        trice(iD(7845), "info:[Drivers_Init]: STM32ADC2 driver is initialized\n");
    }
}
