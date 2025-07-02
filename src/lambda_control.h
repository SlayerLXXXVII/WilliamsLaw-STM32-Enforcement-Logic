#ifndef LAMBDA_CONTROL_H
#define LAMBDA_CONTROL_H

#define LAMBDA_PROTOCOL_VERSION 1.0f
#define PHI_CRIT_VALUE 1.0f  // Default critical symmetry debt

// Data packet passed to enforcement logic
typedef struct {
    float phi;        // Symmetry debt value
    float phi_crit;   // Collapse threshold
    float psi;        // Coherence field level
    float lambda;     // Enforcement strength
} LambdaPacket;

// Enforcement strategies
void lambda_enforcement_strategy_default(LambdaPacket *pkt);

#endif // LAMBDA_CONTROL_H
