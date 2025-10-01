# ESP32 Bluetooth Speaker (A2DP) with MAX98357 I2S Amplifier

**Author:** Muhammad Nabin  
**Date:** 2025-10-02  

---

## 📖 Overview
This project transforms an **ESP32 development board** into a **Bluetooth speaker** by using the **A2DP sink profile**.  
The ESP32 receives audio from a phone, laptop, or other Bluetooth audio source and sends it to a **MAX98357 I2S digital audio amplifier**, which drives a speaker.

This setup allows you to stream music directly from **YouTube, Spotify, or local media players** over Bluetooth to your custom DIY speaker.

---

## 🔌 Hardware Requirements
- ESP32 Development Board (e.g., DevKit V1, WROOM)
- MAX98357A I2S Audio Amplifier Module
- 4–8 Ω Speaker (3W or greater recommended)
- USB cable or regulated 5 V power supply
- Jumper wires and breadboard (for prototyping)

---

## 🪛 Wiring

| MAX98357 Pin | ESP32 Pin |
|--------------|-----------|
| **LRC / WS** | GPIO **26** |
| **BCLK**     | GPIO **27** |
| **DIN**      | GPIO **25** |
| **VIN**      | 5V (recommended for best audio output) |
| **GND**      | GND |
| **SD**       | leave floating or tie to 3.3V (ON) |
| **GAIN**     | Floating = 15 dB, GND = 9 dB, 3.3V = 18 dB |

🔊 **Speaker Connection:** connect the speaker across `OUT+` and `OUT-` (do **not** connect to GND).

---

## 📦 Required Libraries
Install these libraries in Arduino IDE via **Library Manager**:
- [AudioTools](https://github.com/pschatzmann/arduino-audio-tools) (for I2S management)
- [ESP32-A2DP](https://github.com/pschatzmann/ESP32-A2DP) (for Bluetooth A2DP sink)

Also, ensure you have the latest **ESP32 board support package** (version `2.0.x` or later).

---

## 🔊 Usage Instructions
1. Wire the ESP32 and MAX98357 as described above.  
2. Flash the sketch from this repository to your ESP32.  
3. Power the ESP32 with USB or an external **5 V supply**.  
4. On your phone/PC, scan for Bluetooth devices → select **`32_MusicBox By Nabin`**.  
5. Play audio from YouTube, Spotify, or any media app → sound will output from the speaker.  

---

## ⚡ Tips for Better Sound
- Use a **solid 5 V power supply** (≥ 1 A). Running on 3.3 V reduces output power.  
- Tie **GAIN → 3.3 V** for the loudest setting (~18 dB).  
- Use a **4 Ω speaker** for maximum volume (compared to 8 Ω).  
- Place your speaker in a **small enclosure or box** to improve volume and bass response.  
- Check **phone Bluetooth settings**: disable *Absolute Volume* in Android developer options if volume is capped.  


---

## 📝 License
MIT License — Free to use, modify, and share.  
Credit to **Muhammad Nabin** for design and implementation.

---

## 💡 Future Improvements
- Add **OLED display** for track/connection status.  
- Add **buttons/IR remote** for play/pause/skip.  
- Add **battery power management** for portable use.  
- Integrate **EQ/DSP features** with AudioTools library.
