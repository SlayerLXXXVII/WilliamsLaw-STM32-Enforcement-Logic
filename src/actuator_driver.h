#ifndef ACTUATOR_DRIVER_H
#define ACTUATOR_DRIVER_H

// Initialize actuator driver (GPIO, PWM)
void actuator_init(void);

// Set coherence injection level (psi)
void set_psi(float psi);

#endif // ACTUATOR_DRIVER_H
