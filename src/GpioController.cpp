#include "GpioController.h"


GpioController::GpioController() {
}


void GpioController::set() {
    std::cout << "Interrupt PICO";
    //using pin 3
    gpio_set_dir(3,GPIO_IN);
    gpio_set_irq_enabled_with_callback(3, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &GpioController::gpio_callback);
}


//infinite loops for handling interrupts
void GpioController::interrupt() {
    while(1) {
    }
}


//GPIO interrupt events
const char* GpioController::gpio_irq_str[4] = {
"LEVEL_LOW", "LEVEL_HIGH", "EDGE_FALL", "EDGE_RISE"
};


// Converting event flags
std::string GpioController::gpio_event_string(uint32_t eventFlag) {
    std::string event_str;
    //Iterates  the possible interrupt events
    for (uint i = 0; i < 4; i++) {
        uint mask = (1 << i);
        if (eventFlag & mask) {    
            event_str += gpio_irq_str[i];  
            eventFlag &= ~mask;


            if (eventFlag) {
                event_str += " ";  
            }
        }
    }
    return event_str;
}


//GPIO interrupt call back
void GpioController::gpio_callback(uint gpio, uint32_t eventFlag) {


    std::string event_str = GpioController::gpio_event_string(eventFlag);


    std::cout << "GPIO " << gpio << " " << event_str << std::endl;
 }
