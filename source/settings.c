#include "settings.h"
#include "profiles.h"

/*
 * Active profiles
 * Add profiles from source/profiles.h in the profile array
 */
profile profiles[] = {
    {reactiveFade, {4, 3, 2, 1}, reactiveFadeKeypress, reactiveFadeInit}
};

/* Set your defaults here */
uint8_t currentProfile = 0;
const uint8_t amountOfProfiles = sizeof(profiles) / sizeof(profile);
volatile uint8_t currentSpeed = 0;
uint8_t ledIntensity = 0;
led_t color_correction = (led_t){.rgb = 0x80FF99};
led_t color_temperature = (led_t){.rgb = 0xFFFFFF};
