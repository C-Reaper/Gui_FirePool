# Project README

## Overview
This project is a simple fire pool simulation built using C/C++. The application creates a window and simulates a fire effect based on mouse interactions.

## Features
- Real-time fire simulation.
- Mouse interaction to add "fire" at the cursor position.
- Cross-platform build for Linux, Windows, Wine, and WebAssembly using Emscripten.

## Project Structure

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- Libraries needed in specific projects:
  - X11 for Linux GUI (if not cross-compiling to Windows with Wine)
  - WINAPI for Windows GUI
  - Emscripten for WebAssembly

## Build & Run
### Linux Build and Execution
To build the project on Linux, execute the following commands:

```bash
cd <Project>
make -f Makefile.linux all
make -f Makefile.linux exe
```

This will compile the source code into an executable named `Main` located in the `build/` directory. You can run it directly with:

```bash
./build/Main
```

### Windows Build and Execution
To build the project on Windows, execute the following commands:

```bash
cd <Project>
make -f Makefile.windows all
make -f Makefile.windows exe
```

This will compile the source code into an executable named `Main.exe` located in the `build/` directory. You can run it directly with:

```bash
start build\Main.exe
```

### Wine Build and Execution
To build the project for Windows using Wine on Linux, execute the following commands:

```bash
cd <Project>
make -f Makefile.wine all
make -f Makefile.wine exe
```

This will compile the source code into an executable named `Main.exe` located in the `build/` directory. You can run it with Wine by executing:

```bash
WINEPREFIX=~/wine64 WINEARCH=win64 wine build/Main.exe
```

### WebAssembly Build and Execution
To build the project for WebAssembly using Emscripten, execute the following commands:

```bash
cd <Project>
make -f Makefile.web all
make -f Makefile.web exe
```

This will compile the source code into a web application that can be served via an HTTP server. You can run it by opening `build/index.html` in your web browser.

## Build Options

- **Build Output**: 
  ```bash
  make -f Makefile.(os) all  
  ```

- **Build and Execute Output**:
  ```bash
  make -f Makefile.(os) do     
  ```
  For example, `make -f Makefile.linux do` for Linux.

- **Clean Rebuild**:
  ```bash
  make -f Makefile.(os) clean  
  ```

- **Clean Libs and Build** (if there are `./bin` and `./libs` directories):
  ```bash
  make -f Makefile.(os) cleanlib  
  make -f Makefile.(os) lib    
  ```

- **Exe Output**:
  ```bash
  make -f Makefile.(os) exe      
  ```
  For example, `make -f Makefile.linux exe` for Linux.