# Custom Calculator ESP32

A custom calculator project built around an ESP32 microcontroller and a 4-inch ST7796S TFT display. The PCB and schematic have been developed in KiCad, and the next phase is generating Gerber files for manufacturing, followed by enclosure design and firmware development.

## 🎯 Project Goal

Create a compact, custom 4-function calculator with:

- Addition
- Subtraction
- Multiplication
- Division

The design combines a tactile keypad matrix, a high-visibility graphics display, and a lightweight ESP32-based control system.

## 🧩 Hardware Overview

### Core controller
- ESP32 development module / ESP32-WROOM-style board footprint
- Connected to the keypad matrix and display interface
- Planned for calculation logic, UI rendering, and input handling

### Display
- 4-inch TFT display
- ST7796S controller
- Intended for calculator UI, numeric input, operator selection, and result display

### Input device
- Tactile switch matrix arranged in a key layout
- Supports numeric keys and operator keys
- Wiring is organized in a row/column matrix for efficient GPIO usage

### Power and support
- 3.3V logic rail
- Test points for power, reset, SPI, and signal debug
- ESP32 GPIOs mapped for display and keypad interfacing

## ✅ Current Status

### Completed
- PCB design completed in KiCad
- Schematic capture completed in KiCad
- Gerber files generated and ready for manufacturing
- Device planning for ESP32 + display + keypad matrix
- GPIO and pin allocation for the external interfaces
- Basic project structure in the workspace

Schematic:
<img width="1214" height="544" alt="Screenshot 2026-09-21 230605" src="https://github.com/user-attachments/assets/2c9fdb86-0f33-4455-9b36-1b5eef0ae5ce" />

PCB Layout and Wiring:

<img width="904" height="508" alt="Screenshot 2026-09-22 232805" src="https://github.com/user-attachments/assets/f15f4423-4501-4914-8c01-c6fc017d079e" />

PCB Rendering:

<img width="1238" height="885" alt="Screenshot 2026-09-24 234848" src="https://github.com/user-attachments/assets/80871f88-93ae-47a8-9287-3e6f8149e669" />

### Remaining work
- Enclosure design and mechanical fit for the display, buttons, and assembly
- Firmware programming for keypad scanning, display output, and calculator logic
- Final validation and hardware bring-up

## 📁 Repository Structure

```text
Custom_Calculator_ESP32/
├── CAD/
│   └── (mechanical / enclosure or enclosure-related files)
├── ECAD/
│   └── Calculator/
│       ├── Calculator.kicad_pro
│       ├── Calculator.kicad_sch
│       ├── Calculator.kicad_pcb
│       └── Calculator.kicad_prl
├── Programming/
│   └── (firmware source code and future development files)
├── README.md
└── .git/
```

## 📝 Design Notes

This project is intended to be a functional calculator rather than a general-purpose embedded display demo. The hardware is being designed around a straightforward architecture:

1. User presses keypad buttons.
2. ESP32 reads the matrix input.
3. Firmware interprets numeric and operator inputs.
4. Calculation result is rendered on the ST7796S display.

## 🚀 Planned Next Steps

- Design the enclosure to match the completed PCB and display layout
- Add silkscreen labeling and mechanical constraints
- Complete firmware programming for keypad scanning, display rendering, and calculator logic
- Validate the display graphics and UI flow on the physical hardware
- Finalize assembly and testing of the completed calculator

## 💻 Firmware Direction

The firmware can be implemented with:

- GPIO scanning for the keypad matrix
- SPI communication to the ST7796S TFT display
- Basic arithmetic state machine for calculator operation
- Keyboard debounce handling
- Result and expression rendering on screen
