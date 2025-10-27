# Copilot Instructions for AVR ATmega128A Project

## Project Overview
This project is a firmware codebase for the AVR ATmega128A microcontroller, organized for modularity and clarity. It uses CMake for builds and is structured into logical driver, application, and common layers.

## Architecture & Structure
- **src/**: Main source code directory
  - **driver/**: Hardware abstraction modules (button, led, fnd, uart, lcd, etc.)
  - **ap/**: Application logic (ap.c, ap.h)
  - **common/**: Shared definitions (def.h)
- **main.c**: Entry point, initializes and runs application logic
- **build/**: CMake build output (hex, elf, map, etc.)
- **tools/**: Toolchain and build scripts

## Key Patterns & Conventions
- **Drivers** use `volatile` for hardware register pointers and encapsulate state in structs (e.g., `BUTTON`).
- **Application logic** is separated from hardware drivers for testability and clarity.
- **Header files** are included with relative paths; maintain this convention for new modules.
- **Debounce** for buttons is handled in software with `_delay_ms()`.
- **All hardware access** (GPIO, UART, etc.) is abstracted in `driver/` modules.

## Build & Flash Workflow
- **Build**: Use the VS Code task labeled `Build` (runs CMake and avrdude)
- **Clean**: Use the `Clean` task
- **Flash**: Automatically performed after build via avrdude (115200 baud, `/dev/ttyUSB0`)
- **Manual build** (if needed):
  ```bash
  cmake --build build --target all
  /usr/bin/avrdude -v -u -p atmega128a -c avrisp2 -P /dev/ttyUSB0 -b 115200 -U flash:w:build/atmega128a.hex:i
  ```

## Integration Points
- **CMake**: All build logic is in `CMakeLists.txt` and `tools/avr-toolchain.cmake`
- **No external libraries**: Pure C, no OS dependencies
- **UART**: Communication via `driver/uart.c` and `driver/uart0_int.c`

## Examples
- **Button driver pattern**:
  ```c
  BUTTON btn;
  buttonInit(&btn, &DDRA, &PINA, 0);
  if (buttonGetState(&btn) == ACT_PUSH) { /* ... */ }
  ```
- **Application entry**:
  ```c
  int main(void) {
    apInit();
    while (1) apMain();
  }
  ```

## Agent Guidance
- Maintain modular separation (driver vs. application)
- Use `volatile` for hardware register pointers
- Follow existing naming and file organization
- Update or add header guards if missing
- Document new modules with brief comments
- Reference `src/driver/` for hardware patterns, `src/ap/` for application logic

---
For questions or unclear conventions, ask the user for clarification or examples from existing code.