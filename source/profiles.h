#include "light_utils.h"
#include "matrix.h"
#include "settings.h"

/* Update ticks based on profile settings */
static inline void updateAnimationSpeed(void) {
  animationSkipTicks = profiles[currentProfile].animationSpeed[currentSpeed];
  animationTicks = 0;
}

void reactiveFade(led_t *ledColors);
void reactiveFadeKeypress(led_t *ledColors, uint8_t row, uint8_t col);
void reactiveFadeInit(led_t *ledColors);
