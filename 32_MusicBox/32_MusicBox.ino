/*
  ESP32 Bluetooth Speaker (A2DP) -> MAX98357 I2S Amplifier
  --------------------------------------------------------
  Author / Credit: Muhammad Nabin
  Date: 2025-10-02

  Description:
    - Creates a Bluetooth Classic A2DP sink named "MyMusic".
    - Decoded audio is sent over I2S to the MAX98357 class-D amplifier.

  Wiring (from your diagram):
    MAX98357  ->  ESP32
      LRC/WS  ->  GPIO 26
      BCLK    ->  GPIO 27
      DIN     ->  GPIO 25
      VIN     ->  5V (recommended; 3.3V works but quieter)
      GND     ->  GND
      SD      ->  X
      GAIN    ->  X

  Libraries:
    - AudioTools (for ESP_I2S)
    - ESP32-A2DP (BluetoothA2DPSink)
*/

#include <Arduino.h>
#include "ESP_I2S.h"
#include "BluetoothA2DPSink.h"

// --- I2S pin mapping to match your diagram ---
static const uint8_t I2S_SCK   = 27;  // BCLK  -> MAX98357 BCLK
static const uint8_t I2S_WS    = 26;  // LRCLK -> MAX98357 LRC/WS
static const uint8_t I2S_SDOUT = 25;  // DATA  -> MAX98357 DIN

// I2S audio device and A2DP sink
I2SClass i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
  Serial.begin(115200);
  delay(100);

  Serial.println();
  Serial.println(F("=== ESP32 Bluetooth Speaker (by Muhammad Nabin) ==="));

  // --- Configure I2S pins explicitly ---
  i2s.setPins(I2S_SCK, I2S_WS, I2S_SDOUT);

  // --- Initialize I2S in TX mode (stereo, 16-bit, 44.1 kHz) ---
  // I2S_MODE_STD and I2S_STD_SLOT_BOTH work well with A2DP stereo output.
  if (!i2s.begin(I2S_MODE_STD,
                 44100,
                 I2S_DATA_BIT_WIDTH_16BIT,
                 I2S_SLOT_MODE_STEREO,
                 I2S_STD_SLOT_BOTH)) {
    Serial.println(F("ERROR: Failed to initialize I2S! Check wiring/power."));
    while (true) { delay(1000); }
  }

  // Optional: set Bluetooth sink volume (0..100)
  a2dp_sink.set_volume(100);

  // --- Start Bluetooth A2DP sink ---
  // This is the name shown on the phone/PC during pairing
  a2dp_sink.start("32_MusicBox By Nabin");

  Serial.println(F("Bluetooth ready. Pair to '32_MusicBox By Nabin' and play audio."));
}

void loop() {
  // Nothing needed here. A2DP + I2S run in background tasks.
}
