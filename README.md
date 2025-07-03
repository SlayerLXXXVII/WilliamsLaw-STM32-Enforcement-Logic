# Harmony Cell v2 — STM32 Enforcement Logic for Williams Law

This repository contains the full STM32 firmware and validation dataset for enforcing **Williams Law** collapse conditions in a deterministic coherence-driven system.

---

## 🔬 Theory: Williams Law

Collapse occurs when both conditions are met:
- Symmetry Debt Threshold:  **Φ ≥ Φₜ** (Φ in N·s)
- Entropy Rate Threshold:  **𝑑Φ/𝑑t ≥ Sₜ**, where **Sₜ = (k_B · ln Ωₜ) / τ**

This mechanism is enforced in real-time on an STM32F7 microcontroller controlling a physical system (e.g., condensation film, lab plasma analog).

---

## 📟 Hardware

| Component        | Spec                     |
|------------------|--------------------------|
| MCU              | STM32F746 (216 MHz)      |
| Sensor Input     | MEMS strain (1 MHz)      |
| Control Output   | GPIO + piezo injectors   |
| Collapse Actuator| GPIO set on trigger      |

---

## 🧠 Firmware Logic

- Real-time sampling at **10 kHz**
- Running window of Φ values
- Derives 𝑑Φ/𝑑t with 10-sample diff average
- Collapse = **if Φ ≥ Φₜ AND 𝑑Φ/𝑑t ≥ Sₜ**
- Logs system state via UART

---

## 🧪 Validation Dataset

| File                  | Description                                |
|-----------------------|--------------------------------------------|
| `entropy_threshold.csv` | Microstate-derived Ωₜ and Sₜ samples      |
| `collapse_plot.png`     | Collapse event overlay with Φ(t) + Sₜ     |
| `Phi_vs_St_rate.png`    | ΔΦ/Δt vs Entropy Rate comparison           |

---

## 🛠 Build Instructions

1. Open `HarmonyCell.ioc` in STM32CubeMX.
2. Generate code (`Core/` structure will match).
3. Open in STM32CubeIDE or Keil.
4. Flash to STM32F7 dev board.
5. Monitor output via UART @ 115200 baud.

---

## 📜 License

MIT License. Free for scientific and experimental use.

---

## 🧠 Reference

- *Williams Law Exposé: A Deterministic Collapse Model for Coherence-Driven Energy Recovery*
- Harmony Cell v2 STM32 Firmware Implementation
- GitHub QR:  
  ![QR](https://api.qrserver.com/v1/create-qr-code/?size=150x150&data=https://github.com/SlayerLXXXVII/WilliamsLaw-STM32-Enforcement-Logic)
