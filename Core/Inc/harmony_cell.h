#ifndef HARMONY_CELL_H
#define HARMONY_CELL_H

#include <stdbool.h>

// Thresholds (can be tuned at runtime or compile-time)
#define PHI_THRESHOLD      0.8f      // N·s
#define EXPONENT_N         2.5f
#define FEEDBACK_K         0.2f

// Entropy rate threshold (J·K^-1·s^-1)
#define KB                  1.380649e-23f
#define OMEGA_T             1.9e6f
#define TAU_PS              1e-12f   // 1 ps
#define S_THRESHOLD         ((KB * logf(OMEGA_T)) / TAU_PS)

// Data packet for sensor values
typedef struct {
    float phi;       // Symmetry debt
    float psi;       // Coherence field
    float phi_dot;   // Rate of change of phi
} HarmonyPacket;

// Initialize Harmony Cell module
void Harmony_Init(void);

// Run one enforcement cycle, returns whether collapse triggered
bool Harmony_Enforce(const HarmonyPacket *pkt, float *out_lambda);

#endif // HARMONY_CELL_H
