#include "profiles.h"
#include "matrix.h"
#include "miniFastLED.h"

unsigned short animatedPressedBuf[NUM_ROW * NUM_COLUMN] = {0};
const int FADE_STEP = 40;
const int FADE_VAL = 150;

void setWhiteColor(int index, uint8_t value) {
  if (animatedPressedBuf[index] < value) {
    animatedPressedBuf[index] = value;
  }
}

void reactiveFade(led_t *ledColors) {
  for (int i = 0; i < NUM_ROW * NUM_COLUMN; i++) {
    if (animatedPressedBuf[i] > FADE_VAL) {
      animatedPressedBuf[i] -= FADE_STEP;
      ledColors[i].p.blue = FADE_VAL;
      ledColors[i].p.red = FADE_VAL;
      ledColors[i].p.green = FADE_VAL;
    }
    else if (animatedPressedBuf[i] > FADE_STEP) {
      animatedPressedBuf[i] -= FADE_STEP;
      ledColors[i].p.blue = animatedPressedBuf[i];
      ledColors[i].p.red = animatedPressedBuf[i];
      ledColors[i].p.green = animatedPressedBuf[i];
    } else if (animatedPressedBuf[i] > 0) {
      ledColors[i].p.blue = 0;
      ledColors[i].p.red = 0;
      ledColors[i].p.green = 0;
      animatedPressedBuf[i] = 0;
    }
  }
}

void reactiveFadeKeypress(led_t *ledColors, uint8_t row, uint8_t col) {
  // pressed key
  setWhiteColor(row * NUM_COLUMN + col, FADE_VAL);

  // neighbour keys
  uint8_t valNeighbour = FADE_VAL / 3;
  setWhiteColor(row * NUM_COLUMN + col - 1, valNeighbour);
  setWhiteColor(row * NUM_COLUMN + col + 1, valNeighbour);
  setWhiteColor((row - 1) * NUM_COLUMN + col + 1, valNeighbour);
  setWhiteColor((row - 1) * NUM_COLUMN + col , valNeighbour);
  setWhiteColor((row + 1) * NUM_COLUMN + col + 1, valNeighbour);
  setWhiteColor((row + 1) * NUM_COLUMN + col, valNeighbour);
}

void reactiveFadeInit(led_t *ledColors) {
  for (int i = 0; i < NUM_ROW; i++) {
    for (int j = 0; j < NUM_COLUMN; j++) {
      animatedPressedBuf[i * NUM_COLUMN + j] = i * FADE_VAL + FADE_VAL * 2;
    }
  }

  int NAME_BASE_DUR = 8;

  // S
  animatedPressedBuf[30] = FADE_VAL * (NAME_BASE_DUR + 1);
  // P
  animatedPressedBuf[24] = FADE_VAL * (NAME_BASE_DUR + 2);
  // C
  animatedPressedBuf[46] = FADE_VAL * (NAME_BASE_DUR + 3);

  setAllKeysToBlank(ledColors);
}
