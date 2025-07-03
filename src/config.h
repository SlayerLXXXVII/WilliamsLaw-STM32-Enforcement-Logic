#ifndef CONFIG_H
#define CONFIG_H

// Impulse debt threshold (Φₜ, N·s)
#define PHI_THRESHOLD      12.0f

// Entropy-rate threshold parameters
#define KB                 1.380649e-23f
#define OMEGA_T            1.9e6f     // microstate count
#define TAU                1e-12f     // 1 ps in seconds
#define S_THRESHOLD        ((KB * logf(OMEGA_T)) / TAU)

// Control law constants
#define LAMBDA_0           10.0f      // baseline rigidity
#define EXPONENT_N         2.5f
#define FEEDBACK_K         0.2f

// Sensor sampling
#define PHI_SAMPLE_RATE_HZ 1000000    // 1 MHz

#endif // CONFIG_H
