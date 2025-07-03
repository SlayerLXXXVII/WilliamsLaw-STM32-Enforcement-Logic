#include "lambda_control.h"
#include <math.h>

void compute_lambda(LambdaPacket *pkt) {
    float ratio = pkt->phi / PHI_THRESHOLD;
    float decay = 1.0f - powf(ratio, EXPONENT_N);
    if (decay < 0.0f) decay = 0.0f;
    pkt->lambda = LAMBDA_0 * decay + FEEDBACK_K * pkt->psi;
}
