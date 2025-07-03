#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

// Initialize ADC and timer for sensor sampling
void sensor_init(void);

// Read latest Φ value (impulse debt)
float read_phi(void);

#endif // SENSOR_INTERFACE_H
