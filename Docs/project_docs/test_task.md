# Test task for Scilla project

## Revisions

| Revision | Note | Date | Author |
| - | - | - | - |
| v0.1 | Initial version | 12/25/2024 | dieisabel |
| v0.2 | Change analog bandwidth and input impedance requirements for oscilloscope | 03/01/2025 | dieisabel |

## Content

- [1. Introduction](#1-introduction)
- [2. Problem](#2-problem)
- [3. Goal](#3-goal)
- [4. Requirements](#4-requirements)
    - [4.1 Functional](#41-functional)
        - [4.1.1 Oscilloscope](#411-oscilloscope)
        - [4.1.2 Signal Generator](#412-signal-generator)
        - [4.1.3 Control Panel](#413-control-panel)
    - [4.2 Non-functional](#42-non-functional)
        - [4.2.1 Pricing](#421-pricing)
        - [4.2.2 Case](#422-case)
        - [4.2.3 Power](#423-power)
        - [4.2.4 Data privacy](#424-data-privacy)
        - [4.2.5 Updates](#425-updates)

## 1. Introduction

This document contains test task for Scilla project. Text is written in English, Markdown format.

## 2. Problem

There are many signal analysis devices available on the current market. They range from small, compact devices
the size of a smartphone to larger devices that are usually placed on a table. The price also varies
greatly, from 80$ to a couple thousand dollars. For people who are just learning or just interested
in the world of signals, simple, small, low-power devices are often needed for their projects and experiments.
Unfortunately, there are few such devices on the market.

## 3. Goal

The goal of this project is to develop an device that combines the functionalities
of an oscilloscope and signal generator. The device will serve as a versatile and
low-cost tool mostly for hobbyists for the work with electronics signals.

## 4. Requirements

### 4.1 Functional

Functional requirements describe what the device must do.

#### 4.1.1 Oscilloscope

Device must implement oscilloscope functionality:
1. **Input channels:** at least 2 analog channels
1. **Analog bandwidth:** up to 150KHz
1. **Input impedance:** very large, suppose 10MOhms
1. **Modes:** edge trigger, normal, one-time
1. **Math functions:** addition, substraction, integration, FFT

#### 4.1.2 Signal Generator

Device must implement signal generator functionality:
1. **Output channels:** at least 1 analog channel
1. **Waveforms:** sine, triangle, pulse, noise, user type
1. **Output bandwidth:** up to 200KHz
1. **Amplitude:** up to 2V
1. **Modulation:** AM, FM, PM, PWM, and frequency sweep.
1. **Output impedance:** TODO

#### 4.1.3 Control Panel

Device must contain a control panel for displaying data and controlling device:
1. **Signal generator:** through control panel user must have access to:
    1. enable/disable output
    1. change waveform, draw own
    1. change amplitude
    1. change modulation
    1. change frequency
1. **Oscilloscope:** through control panel user must have access to:
    1. see signal plot
    1. change time axis
    1. change amplitude axis
    1. enable/disable input
    1. see math functions result
    1. change math functions
    1. change mode
    1. change trigger configuration
1. **Data access:** through control panel user must be able to:
    1. export signal snapshot as raw binary data, CSV or as image in jpg format
    1. export math functions result as raw binary data, CSV or as image in jpg format

### 4.2 Non-functional

Non-functional requirements describe the quality attributes and
constraits of a system.

#### 4.2.1 Pricing

1. Device must be low-cost, less than 20$

#### 4.2.2 Case

1. Device must contain two sockets for oscilloscope
1. Device must contain one socket for signal generator output
1. Device must contain one socket for power
1. Device must contain one socket for connecting to control panel
1. Device must be small. TODO: how small?

#### 4.2.3 Power

1. Device must consume no more than 0.3A

#### 4.2.4 Data privacy

1. Device must not share any data with third-party

#### 4.2.5 Updates

1. Firmware updates must be installable via USB without user intervention
