#include "pros/competition.hpp"

#include <arm_neon.h>
#include <iostream>
#include <stdint.h>

extern "C" {
void vexDisplayPrintf(int32_t xpos, int32_t ypos, uint32_t bOpaque, const char* format, ...);
}

void myAutonomous() {
    std::cout << "Running autonomous!" << std::endl;
}

void myDriverControl() {
    std::cout << "Running driver control!" << std::endl;
}

void myDisabled() {
    std::cout << "Running disabled!" << std::endl;
}

int main() {
    std::cout << "Adding callbacks!" << std::endl;
    zest::competition::register_autonomous(myAutonomous);
    zest::competition::register_driver_control(myDriverControl);
    zest::competition::register_disabled(myDisabled);
    std::cout << "printing hello world!" << std::endl;

    vexDisplayPrintf(10, 60, 1, "Hello World!\n");
}
