#include <stdio.h>
#include "config.h"
#include "sensor_interface.h"
#include "lambda_control.h"
#include "actuator_driver.h"

int main(void) {
    // HAL and hardware init
    sensor_init();
    actuator_init();

    LambdaPacket pkt;
    pkt.psi = 0.0f;

    while (1) {
        // 1. Sample Phi
        pkt.phi = read_phi();

        // 2. Compute lambda
        compute_lambda(&pkt);

        // 3. Update psi based on control (e.g., inject coherence)
        pkt.psi = /* derive new psi from lambda or other logic */ 0.0f;

        set_psi(pkt.psi);

        // 4. (Optional) Log via UART
        // printf("Phi: %.2f, Psi: %.2f, Lambda: %.2f\n", pkt.phi, pkt.psi, pkt.lambda);
    }
    return 0;
}
