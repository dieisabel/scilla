# Scilla

## Content

- [1. Introduction](#1-introduction)
- [2. Project Structure](#2-project-structure)
- [3. Development](#3-development)
    - [3.1 Code Style](#31-code-style)
    - [3.2 CI](#32-ci)
    - [3.3 VS Code Development Environment](#33-vs-code-development-environment)
        - [3.3.1 File templates](#331-file-templates)
        - [3.3.2 Auto formatting](#332-auto-formatting)
        - [3.3.3 Tasks](#333-tasks)
        - [3.3.4 Debugging](#334-debugging)
- [4. Similiar projects](#4-similiar-projects)
- [5. License](#5-license)
- [6. Q/A](#6-qa)

## 1. Introduction

This repository contains Scilla project.

## 2. Project Structure

Project is divided into separate directories. Each directory have a `README.md` file that describes directory content. Full list is presented below:
1. [Docs/](Docs/README.md) - project documentation, contains project and technical documentation

## 3. Development

### 3.1 Code Style

Project uses [Google C++ Code Style](https://google.github.io/styleguide/cppguide.html) with certain deviations:
1. indentation is done using 4 spaces
1. variable names are in camel case
1. line length is increases from 80 to 90 symbols
1. C++ source files have a `.cpp` extension instead of `.cc`
1. access modifiers are not indented

Use `clang-format` utility to format files. Check [their website](https://clang.llvm.org/docs/ClangFormat.html) for more information.

### 3.2 CI

Project have a Continious Integration (CI) process to ensure code meets project standards. CI is implemented using `pre-commit` utility. A full list of hooks you can see in `.pre-commit-config.yaml` file.

### 3.3 VS Code Development Environment

You can use VS Code for development. `.vscode/` directory contains all files related to VS Code configuration: templates, settings, extensions, etc. Check `.vscode/extensions.json` for a list of recommended extensions.

#### 3.3.1 File templates

`thinker.new-file-template` extension allows us to create files from templates. Project has a `cpp_class` template for creating C++ classes and `task` template for creating FreeRTOS tasks. You can use them using `<Mouse right click> -> New File from Template -> <Select template> -> <Select files> -> <Enter class name> -> <Done>`.

#### 3.3.2 Auto formatting

`xaver.clang-format` extension allows us to format files using `clang-format` in VS Code. Install this extension, add `"editor.formatOnSave": true` setting to your `.vscode/settings.json`. With this files will be automatically formatting on save.

#### 3.3.3 Tasks

VS Code features excellent feature called Tasks. They allows to run certain tools and commands using VS Code command prompt instead of going into terminal. Project features tasks for building, cleaning, flashing, etc. Full list of tasks is located in `.vscode/tasks.json`. Invoke them using `<Ctrl + Shift + P> -> Tasks: Run Task` and select task. For more information see official [webpage](https://code.visualstudio.com/docs/debugtest/tasks).

#### 3.3.4 Debugging

`marus25.cortex-debug` extension gives step-by-step firmware debugging on target hardware. It uses tools like `openocd` or similiar. For debugging project has a VS Code debug configuration called `Cortex Debug` that utilizes this extension. Also using extension we can gain access to GDB server using `Debug Console` tab.

## 4. Similiar projects

[EMBO](https://github.com/parezj/EMBO)

[ScopeFun](https://www.scopefun.com/)

## 5. License

Project is licensed under [MIT license](LICENSE.md).

## 6. Q/A

### Why dont generate BSP packet in CubeMX?

**Answer:** for some unknown reason CubeMX 6.14.0 which I use generates BSP packet for NUCLEO-64 pin development board, but I have NUCLEO-32 pin board. Because of this LED feature don't work. To solve this I manually port BSP.
