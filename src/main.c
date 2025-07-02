#include "lambda_control.h"
#include "utils.h"   // ADC, timing, UART helpers

int main(void) {
    SystemInit();  // Platform-specific init if needed

    LambdaPacket pkt = {0};

    while (1) {
        // Sample sensors into pkt
        read_sensors(&pkt);
        pkt.phi_crit = PHI_CRIT_VALUE;

        // Enforce collapse logic
        lambda_enforcement_strategy_default(&pkt);

        // Actuate system
        apply_control(pkt.lambda);

        // Log results
        log_packet(&pkt);
    }

    return 0;
}
