# Intro-Class - Introduction to GBA Hardware

## Summary

1. Old console history
2. Inside the GBA
3. Introduction to Video Memory
4. Emulating GBA + Dev Tools

## 1. Old consoles history

### Atari 2600

About:
    Year: 1977
    Processor: MOS Technology 6507
    Bus: 8bit
    Clock: 1.19MHz
    RAM: 128B
    ROM: 16KB
    Resolution: 160x192 (NTSC), 160x228 (PAL)
    Colors: 128
    Sound: 2 channels (1 chip each)

Development Specifications:
    - Had for 2 player's sprites with Hardware Acceleration
    - Fully bitmapped
    - Maximum of 2 sprites on the same scanline

### NES

About:
    Year: 1983
    Processor: Custom MOS 6502
    Bus: 8bit
    CPU Clock: 1.79MHz (NTSC), 1.66MHz (PAL)
    GPU Clock: 5.37MHz (NTSC), 5.33MHz (PAL)
    RAM: 2KiB + Cartdridge expansion RAM
    ROM: 48KB
    Resolution: 256x240
    Max sprites on screen: 64
    Sound: see dev-specs

Development Specifications:
    - Palette: 56 colors
    - OAM: 256B
    - Colors on screen: 25 colors/scanline
        - BG
        - 4 sets of 3 colors for tiles
        - 4 colors per sprites
    - Sprite dimensions:
        - 16x16
        - 24x24
    - Sound: 5 channels
        - 2 square
        - 1 triangle
        - 1 white noise
        - 1 delta-pulse code modulation (DPCM) of 6 bits

### SNES

About:
    Year: 1990
    Processor: Nintendo's custom Ricoh 5A22
    Bus: 16bit
    CPU Clock: 1.79MHz, 2.68MHz or 3.58MHz
    GPU Clock: Same as CPU
    RAM: 128KB
    VRAM: 64KB
    Audio RAM: 64KB
    Resolution: 256x224/512x448

Development Specifications:
    Palette: 15 bits (32768 colors)
    OAM: 544B
    Sprite dimensions:
        - 8x8
        - 16x16
        - 32x32
        - 64x64
    Colors per sprite: 16
    Max sprites on screen: 128 (32/scanline)
    Background Layers: 4
    Sound: 8 channels, 32KHz 16-bit Stereo

### GameBoy

About:
    Year: 1989
    Processor: Custom Sharp LR35902
    Bus: 8bit
    CPU Clock: 4.19MHz
    RAM: 8KB (can be expanded to 32KB)
    ROM:
        - internal: 256B
        - cartdridges: 256K/512K/1M/2M/4M/8MB
    VRAM: 8KB (internal)
    Resolution: 160x144
    Colors: 2 bits (4 "graytones")

Development Specifications:
    - OAM: 160B (4B/sprite)
    Sprite dimensions:
        - 8x8
        - 8x16
    Color per sprite: 16 colors
    Max sprites on screen: 40
    Sound: 2 wave pulse generators

### GameBoy Advance

About:
    Year: 2001
    Processor: ARM7-TDMI¹ with embedded memory
    Bus: 16bit
    Co-Processor: Z80 8bit 4/8MHz (for GB/GBC compatibility)
    CPU Clock: 16.8MHz
    GPU Clock: ~5.5MHz (59.73FPS)
    RAM: 32KB (CPU)
    VRAM: 92KB (internal)
    DRAM: 256KB (external to CPU)
    Resolution: 240x160 (3:2)

Development Specifications:
    Palette: 15-bit X1B5G5R5
        - Character Mode: 512 colors
        - Bitmapped Mode: 32768 colors
    OAM: 160B (4 bytes/sprite)
    Sprite dimensions:
        - 8x8
        - 8x16
        - 16x8
        - 16x16
    Colors: 1 palette for entire screen (256 colors)
    Max sprites on screen: 256
    Sound: Dual 8-bit DAC² for Stereo Sound (DirectSound)

    ¹: ARM + 16-bit Thumb + JTAG Debug + fast Multiplier + enhanced ICE
    ²: Digital-Analogic Converter

## 2. Inside the GBA

### Hardware overview

Components that can be identified:
    - D-pad, A, B, L, R and Start/Select Buttons
    - Processor & Co-processor (side by side)
    - Audio Processor
    - U3 GBA Registers
    Cartdridge:
        - ROM
        - SaveData

Each one has addresses related to an item about them.
Read-Only Addresses:
    - Buttons
    - Some internal registers (ex: scanline count register)
    - ROM (bup)

Write-Only Addresses:
    - Interrupts (!)
    - Some internal registers

(!): Altough Interrupts are read-only, you can perform `or` operations
     with them, but you MUST NOT! It can bring unwanted behaviours, since
     it'll wait for all interrupts setted to be thrown.

### Memory Addresses



## 3.