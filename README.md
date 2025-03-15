# Scilla

## Content

- [1. Introduction](#1-introduction)
- [2. Project Structure](#2-project-structure)
- [3. Development](#3-development)
    - [3.1 Code Style](#31-code-style)
    - [3.2 VS Code Development Environment](#32-vs-code-development-environment)
        - [3.2.1 File templates](#321-file-templates)
        - [3.2.2 Auto formatting](#322-auto-formatting)
- [4. License](#4-license)

## 1. Introduction

This repository contains Scilla project.

## 2. Project Structure

Project is divided into separate directories. Each directory have a `README.md` file that describes directory content. Full list is presented below:
1. [docs/](docs/README.md) - project documentation, contains project and technical documentation
1. [experiments/](experiments/README.md) - experiments and system modeling
1. [core/](core/README.md) - core modules

## 3. Development

### 3.1 Code Style

Project uses [Google C++ Code Style](https://google.github.io/styleguide/cppguide.html) with certain deviations:
1. indentation is done using 4 spaces
1. variable names are in camel case
1. line length is increases from 80 to 90 symbols
1. C++ source files have a `.cpp` extension instead of `.cc`
1. access modifiers are not indented

Use `clang-format` utility to format files. Check [their website](https://clang.llvm.org/docs/ClangFormat.html) for more information.

### 3.2 VS Code Development Environment

You can use VS Code for development. `.vscode/` directory contains all files related to VS Code configuration: templates, settings, extensions, etc. Check `.vscode/extensions.json` for a list of recommended extensions.

#### 3.2.1 File templates

`thinker.new-file-template` extension allows us to create files from templates. Project has a `cpp_class` template for creating C++ classes. You can use it using `<Mouse right click> -> New File from Template -> <Select files> -> <Enter class name> -> <Done>`.

#### 3.2.2 Auto formatting

`xaver.clang-format` extension allows us to format files using `clang-format` in VS Code. Install this extension, add `"editor.formatOnSave": true` setting to your `.vscode/settings.json`. With this files will be automatically formatting on save.

## 4. License

Project is licensed under [MIT license](LICENSE.md).
