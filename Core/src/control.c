#include "control.h"
#include <math.h>

float PHI_T = 0.8f;
float S_T = 1e-20f;

float get_lambda(float phi, float psi)
{
    float base = 1.0f - powf((phi / PHI_T), 2.5f);
    return base + 0.2f * psi;
}

bool check_collapse(float phi, float phi_dot)
{
    return (phi >= PHI_T && phi_dot >= S_T);
}
