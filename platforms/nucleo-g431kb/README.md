# NUCLEO-G431KB platform

## Content

- [1. Introduction](#1-introduction)
- [2. Q/A](#2-qa)

## 1. Introduction

This document contains documentation for nucleo-g431kb platform.

## 2. Q/A

### Why dont generate BSP packet in CubeMX?

**Answer:** for some reason CubeMX 6.14.0 generates BSP packet for NUCLEO-64 pin development board, which is wrong because i have NUCLEO-32 pin board. Because of wrong board LED dont work. To solve this I manually port BSP.
