#ifndef LAMBDA_CONTROL_H
#define LAMBDA_CONTROL_H

#include "config.h"

// Packet for control computation
typedef struct {
    float phi;       // current impulse debt
    float psi;       // current coherence field
    float lambda;    // computed rigidity
} LambdaPacket;

// Compute lambda based on current phi and psi
void compute_lambda(LambdaPacket *pkt);

#endif // LAMBDA_CONTROL_H
