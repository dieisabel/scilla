# Scilla Core

## Content

- [1. Introduction](#1-introduction)
- [2. Usage](#2-usage)

## 1. Introduction

This directory contains Scilla project core modules.

## 2. Usage

Link core modules to your project using CMake:

```bash
target_link_libraries(<TARGET> <SCOPE> scilla_core)
```

where:
- `<TARGET>` - your CMake target
- `<SCOPE>` - CMake scope, it can be `PRIVATE`, `PUBLIC` or `INTERFACE` depending on your use case

Include prefix is `scilla/core/`.
