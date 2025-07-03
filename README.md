# Williams Law – STM32 Enforcement Logic (Harmony Cell v2)

This repository contains firmware and validation data implementing **Williams Law**, a deterministic collapse model for controlled energy recovery.

## Collapse Criteria
- **Impulse imbalance**: Φ ≥ Φₜ  (N·s)
- **Entropy rate**:       ẊΦ ≥ Sₜ = (k_B · ln Ωₜ) / τ  (J·K⁻¹·s⁻¹)

## Control Law
λ(Φ, ψ) = λ₀ [1 – (Φ/Φₜ)²·⁵ ] + 0.2·ψ

## Hardware
- MEMS strain sensor @ 1 MHz, 10 µs resolution
- STM32F7 (Cortex-M7 @ 216 MHz) – real-time control
- Piezoelectric actuators for coherence injection

## Build & Flash (see `src/README.md`)
1. Open `src/` in STM32CubeIDE or PlatformIO.
2. Build the project.
3. Flash to STM32F7 board.

## Validation Data (`validation/`)
- `entropy_threshold.csv` — Ωₜ microstate data
- `collapse_plot.png`     — Φ vs time & entropy threshold overlay
- `film_test_results.csv` — Condensation film rupture results

## Paper & Figures (`docs/`)
- `WilliamsLaw_Expose.pdf` — Full exposé
- `docs/figures/`           — Diagrams & plots

## License
Licensed under the MIT License. See [LICENSE](LICENSE).
