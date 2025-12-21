# Image Viewer in Pure C

A minimal **PPM (P6) image viewer** written in **C using SDL2**.  
The program reads a PPM image from **stdin** and renders it **pixel-by-pixel** using an `SDL_Surface`.

This project is focused on learning low-level image rendering and SDL basics.

---

## Supported Format

- **PPM (P6 – binary)**
- 8-bit RGB
- No scaling or color correction

---

## How It Works

1. Reads and ignores the PPM magic number (`P6`)
2. Reads image `width` and `height`
3. Skips the max color value line (`255`)
4. Reads raw RGB bytes (`R G B` per pixel)
5. Draws each pixel directly onto an SDL window surface

---

## Build

Make sure SDL2 is installed.

```sh
gcc image.c -o image `sdl2-config --cflags --libs`
```
## Run
```sh
./image < image.ppm
```



## Notes

The SDL window size matches the PPM image dimensions.
Rendering is done on the CPU, one pixel at a time

Pixels are drawn using SDL_FillRect with a 1×1 SDL_Rect

Correct (x, y) mapping is required to avoid image rotation

An event loop is required to keep the window responsive
