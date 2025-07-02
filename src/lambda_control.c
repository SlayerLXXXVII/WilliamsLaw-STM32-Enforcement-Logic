#include "lambda_control.h"

// Default enforcement: linear decay
void lambda_enforcement_strategy_default(LambdaPacket *pkt) {
    if (pkt->phi >= pkt->phi_crit) {
        pkt->lambda = 0.0f; // collapse enforcement
    } else {
        // linear interpolation
        pkt->lambda = (pkt->phi_crit - pkt->phi) / pkt->phi_crit;
    }
}
