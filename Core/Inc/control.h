#ifndef CONTROL_H
#define CONTROL_H

#include <stdbool.h>

void control_loop(void);
float get_lambda(float phi, float psi);
bool check_collapse(float phi, float phi_dot);

extern float PHI_T;
extern float S_T;

#endif // CONTROL_H
