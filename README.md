# Custom Calculator ESP32

A custom calculator project built around an ESP32 microcontroller and a 4-inch ST7796S TFT display. The design is currently in the electronics phase: the KiCad schematic is complete, and the PCB layout is the next step before prototyping and firmware development.

## Project Goal

Create a compact, custom 4-function calculator with:

- Addition
- Subtraction
- Multiplication
- Division

The design combines a tactile keypad matrix, a high-visibility graphics display, and a lightweight ESP32-based control system.

## Hardware Overview

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

## Current Status

### Completed
- Schematic capture in KiCad
- Device planning for ESP32 + display + keypad matrix
- GPIO and pin allocation for the external interfaces
- Basic project structure in the workspace

### In progress
- PCB layout and routing in KiCad
- Mechanical placement of the display, buttons, and enclosure fit
- Signal integrity review for display and key matrix lines

## Repository Structure

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

## Design Notes

This project is intended to be a functional calculator rather than a general-purpose embedded display demo. The hardware is being designed around a straightforward architecture:

1. User presses keypad buttons.
2. ESP32 reads the matrix input.
3. Firmware interprets numeric and operator inputs.
4. Calculation result is rendered on the ST7796S display.

## Planned Next Steps

- Finish the PCB layout in KiCad
- Review the board for routing, grounding, and placement issues
- Add silkscreen labeling and mechanical constraints
- Export manufacturing files when the layout is complete
- Develop firmware for keypad scanning and calculator logic
- Validate the display graphics and UI flow on the physical hardware

## Firmware Direction

The firmware can be implemented with:

- GPIO scanning for the keypad matrix
- SPI communication to the ST7796S TFT display
- Basic arithmetic state machine for calculator operation
- Keyboard debounce handling
- Result and expression rendering on screen
