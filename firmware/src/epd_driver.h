#ifndef INKSIGHT_EPD_DRIVER_H
#define INKSIGHT_EPD_DRIVER_H

#include <Arduino.h>

// Initialize GPIO pins and SPI for EPD
void gpioInit();

// Initialize EPD controller (full refresh mode)
void epdInit();

// Initialize EPD controller in fast refresh mode
void epdInitFast();

// Full-screen display with full refresh (clears ghosting, has black-white flash)
void epdDisplay(const uint8_t *image);

// Deep clear: multi-cycle black/white flush then display image (eliminates stubborn ghosting)
void epdDisplayDeepClear(const uint8_t *image);

// Full-screen display with pre-packed 2bpp data (4-color panels)
void epdDisplay2bpp(const uint8_t *image2bpp);

// A1.1 (JD79665 3.98" 4-color): display a whole frame at a custom resolution.
// The controller must be driven with at least as many rows as the panel has
// (>= 600) or it fails to drive every gate, leaving a line in the middle.
void epdDisplayAt(uint16_t w, uint16_t h, const uint8_t *buf);

// Full-screen display with fast refresh (reduced flashing)
void epdDisplayFast(const uint8_t *image);

// Partial display refresh for a rectangular region
bool epdSupportsPartialRefresh();
void epdPartialDisplay(uint8_t *data, int xStart, int yStart, int xEnd, int yEnd);
void epdPartialDisplayWithOld(uint8_t *data, const uint8_t *oldData, int xStart, int yStart, int xEnd, int yEnd);

// Put EPD into deep sleep mode
void epdSleep();

#endif // INKSIGHT_EPD_DRIVER_H
