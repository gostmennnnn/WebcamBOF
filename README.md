# WebcamBOF for Adaptix C2

A post-exploitation module for Adaptix C2 that captures images from the target's attached webcam entirely in memory.

**Watermark / Maintainer:** @gostmennnnn

## Features
- Enumerates available webcams via the Windows Media Foundation API.
- Captures the current camera frame and encodes it directly into a compressed JPEG stream.
- Hooks instantly into the **Adaptix C2 Screenshot Viewer** via native `AxAddScreenshot` API (zero on-disk artifacts).
- Zero dependencies — runs fully inline as a Beacon Object File.

## Installation
1. Download or clone this repository.
2. In your Adaptix client, navigate to **AxScript → Script Manager → Load New**.
3. Select the `webcam.axs` script.

## Usage
Simply run the command from an active beacon session. No arguments are required!

```text
beacon > webcam_cap
```
The captured webcam frame will seamlessly and automatically appear in your Adaptix C2 **Screenshots** tab.

Alternatively, you can right-click any Beacon in your session list and select **Webcam** from the interactive menu!

## Building from Source
Pre-compiled components (`_bin/WebcamBOF.x64.o`) are included, but to build from source, ensure you have the MinGW cross-compiler installed on Linux or WSL (`mingw-w64`). 

Run the automated Makefile:
```bash
make
```

## Credits
- Originally created by `@codex_tf2` for Cobalt Strike
- Ported and adapted for Adaptix C2 by `@gostmennnnn`
