# Solution Concept

## Revisions

| Revision | Note | Date | Author |
| - | - | - | - |
| v0.1 | Initial version | 02/15/2025 | dieisabel |
| v0.2 | Change analog bandwidth and input impedance requirements for oscilloscope | 03/01/2025 | dieisabel |
| v0.3 | Remove resources chapter | 03/02/2025 | dieisabel |
| v0.4 | Change page name to "Solution Concept" and add system model | 05/03/2025 | dieisabel |

## Content

- [1. Introduction](#1-introduction)
- [2. Terminology](#2-terminology)
- [3. System Model](#3-system-model)
- [4. Oscilloscope](#4-oscilloscope)
   - [4.1 Data gathering](#41-data-gathering)
      - [4.1.1 ADC](#411-adc)
      - [4.1.2 Acquisition](#412-acquisition)
      - [4.1.3 System Block](#413-system-block)
   - [4.2 Processing](#42-processing)

## 1. Introduction

This document contains solution concept. Text is written in English, Markdown format.

## 2. Terminology

ADC (Analog-Digital-Converter) - device that samples continious signals

## 3. System Model

System model is presented on [Diagram 1](#diagram-1-system-model).

##### Diagram 1: system model

```plantuml
@startuml

interface input_signal as "Input Signal"
interface output_signal as "Output Signal"
interface control_data as "Control Data"

component oscilloscope as "Oscilloscope"
component signal_generator as "Signal Generator"
component control_panel as "Control Panel"

input_signal -right-> oscilloscope
oscilloscope -right-> control_panel
control_panel -left-> oscilloscope

control_data -down-> control_panel

control_panel -right-> signal_generator
signal_generator -left-> control_panel
signal_generator -right-> output_signal

@enduml
```

## 4. Oscilloscope

In the real world oscilloscope main tasks are:
1. show a plot of a signal
1. analyze certain properties of a signal
1. apply certain operations to signal and show result

Oscilloscope system block is presented in [Diagram 2](#diagram-2-oscilloscope-system-block).

##### Diagram 2: oscilloscope system block

```plantuml
@startuml

component oscilloscope as "Oscilloscope"
interface input as "Input"
interface output as "Output"
interface parameters as "Parameters"

input -> oscilloscope : continious
oscilloscope -> output : discrete vector
parameters -down-> oscilloscope

@enduml
```

As you can see it is a block that accepts:
- `Input` - **continious** wave, more in Data Gathering chapter
- `Parameters` - some parameters that control behaviour
- `Output` - **discrete vector** output

As per technical task there will be a control panel that will show signal, so
we scope oscilloscope tasks only to data gathering and data processing.

Every task will be explained below in separate chapters and in the end of
this chapter there will be presented a oscilloscope system block.

### 4.1 Data gathering

#### 4.1.1 ADC

The signal is modeled as a function $ V(t) $, where $ V $ - voltage, $ t $ - time.
They are modeled as **continious** signal. To process it we need to
convert data to **digital** domain. To do it we need a blocks which are  called **sampler** and
**quantizier**. They are implemented using **ADC**. Requirements to ADC are listed below:
1. **Input channels:** at least 2 analog input channels
1. **Sampling rate:** to show a signal with frequency of 1MHz we need to sample
   at least 8 samples, so sampling rate must be at least 1MHz * 8 = 8MHz
1. **Input impedance:** input channels must have an 1MOhms input impedance

Specification is presented on [Table 1](#table-1-adc-block-specification).

##### Table 1: ADC block specification

| Problem space requirement (Oscilloscope) | Solution space requirement (ADC) |
| - | - |
| Input channels: at least 2 analog channels | Input channels: at least 2 input channels |
| Analog bandwidth: up to 150KHz | Sampling rate: up to 1MHz |
| Input impedance: very large, suppose 10MOhms | Input impedance: very large, suppose 10MOhms |

Block diagram is presented on [Diagram 3](#diagram-3-adc-system-block).

##### Diagram 3: ADC system block

```plantuml
@startuml

component adc as "ADC"
interface input as "Input"
interface output as "Output"

input -right-> adc : continious
adc -right-> output : digital

@enduml
```

#### 4.1.2 Acquisition

ADC samples signal continiously. To synchronize data acquisition with trigger we need
separate acquisition block that will start storing data after trigger signal.
Acqusition block stores a vector of data with some size $ N $ and gives it to
other block. System diagram is presented in [Diagram 4](#diagram-4-acquisition-system-block).

##### Diagram 4: acquisition system block

```plantuml
@startuml

component acquisition as "Acquisition"
interface input as "Input"
interface output as "Output"
interface trigger as "Trigger"

input -right-> acquisition : discrete
acquisition -right-> output : discrete vector
trigger -down-> acquisition

@enduml
```

Specification is presented on [Table 2](#table-2-acquisition-specification).

##### Table 2: acquisition specification

| Problem space requirement (Oscilloscope) | Solution space requirement (Acquisition) |
| - | - |
| Modes: edge trigger, normal, one-time | Trigger modes: edge trigger, normal, one-time |

#### 4.1.3 System Block

Data gathering system block is presented on [Diagram 5](#diagram-5-data-gathering-system-block).

#### Diagram 5: data gathering system block

```plantuml
@startuml

interface parameters as "Parameters"
component data_gathering as "Data Gathering" {
   interface input as "Input"
   interface output as "Output"
   interface trigger_parameter as "Trigger Parameter"

   component adc as "ADC"
   component acquisition as "Acquisition"

   input -right-> adc : continious signal
   adc -right-> acquisition : stream of discrete value
   acquisition -right-> output
   trigger_parameter -down-> acquisition
}

parameters -down-> data_gathering

@enduml
```

### 4.2 Processing

After data gathering block can process data. Per technical task oscilloscope must have a support
for math functions: addition, substraction, integration, FFT. System block for processing is
presented on [Diagram 6](#diagram-6-oscilloscope-processing-subblock).

#### Diagram 6: oscilloscope processing subblock

```plantuml
@startuml

component Processing {
   component add_operation as "Add Operation"
   component integrate_operation as "Integrate Operation"
   component fft_operation as "FFT Operation"
}

interface Input
interface Output
interface Operation

Input -> Processing : discrete
Processing -> Output : discrete
Operation -down-> Processing

@enduml
```
