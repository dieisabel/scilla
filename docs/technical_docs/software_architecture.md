# Software Architecture

## Revisions

| Revision | Note | Date | Author |
| - | - | - | - |
| v0.1 | Initial version | 03/08/2025 | dieisabel |

## Content

- [1. Introduction](#1-introduction)
- [2. HAL](#2-hal)
    - [2.1 Timers](#21-timers)
- [3. Oscilloscope](#3-oscilloscope)
    - [3.1 ADC](#31-adc)

## 1. Introduction

This document contains software architecture. Text is written in English, Markdown format with PlantUML diagrams.

## 2. HAL

Hardware is abstracted from software through HAL (Hardware Abstraction Layer), which gives engineers ability to port software to many hardware platforms.

### 2.1 Timers

Main purpose of timers is to provide time counters or/and provide functionality for periodicity.

API for timers is presented on [Diagram 1](#diagram-1-timer-api).

##### Diagram 1: timer API

```plantuml
@startuml

enum ETimerStatus {
    TIMER_STATUS_NOT_INITIALIZED,
    TIMER_STATUS_SUCCESS,
    TIMER_STATUS_ERROR,
    TIMER_STATUS_SUBSCRIBER_ALREADY_IN_LIST,
    TIMER_STATUS_SUBSCRIBER_NOT_FOUND,
    TIMER_STATUS_INVERVAL_NOT_SUPPORTED,
    TIMER_STATUS_NOT_IMPLEMENTED,
}

interface ITimerSubscriber {
    + processTimeoutEvent(): void
}

interface ITimer {
    + init(): ETimerStatus
    + start(): ETimerStatus
    + stop(): ETimerStatus
    + setInterval(interval: uint32): ETimerStatus
    + getInterval(dest: uint32*): ETimerStatus
    + getTicks(dest: uint32*): ETimerStatus
    + addSubscriber(subscriber: ITimerSubcriber*): ETimerStatus
    + removeSubscriber(subscriber: ITimerSubcriber*): ETimerStatus
    + processFromISR(): void
}

ITimer -- ITimerSubscriber
ITimer -- ETimerStatus

@enduml
```

## 3. Oscilloscope

### 3.1 ADC

ADC API is presented on [Diagram 2](#diagram-2-adc-api).

##### Diagram 2: ADC API

```plantuml
@startuml

enum EADCStatus {
    ADC_STATUS_NOT_INITIALIZED,
    ADC_STATUS_SUCCESS,
    ADC_STATUS_ERROR,
    ADC_STATUS_CHANNEL_NOT_SUPPORTED,
    ADC_STATUS_NOT_IMPLEMENTED,
}

interface IADC {
    + init(): EADCStatus
    + singleConvert(channel: uint8): EADCStatus
    + startContiniousConverting(channel: uint8): EADCStatus
    + stopContiniousConverting(channel: uint8): EADCStatus
    + processFromISR(): void
}

IADC -- EADCStatus

@enduml
```
