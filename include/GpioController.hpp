#ifndef GPIO_CONTROLLER_H
#define GPIO_CONTROLLER_H


#include <iostream>
#include "hardware/gpio.h"
#include "pico/stdlib.h"


class GpioController {
  public:
    GpioController();
  //GPIO setup  
    void set();


    //interrupt loop
    void interrupt();
 
  private:
    static const char* gpio_irq_str[4];
  //GPIO event
    static std::string gpio_event_string(uint32_t eventFlag);
  //callback for GPIO  
    static void gpio_callback(uint gpio, uint32_t eventFlag);
};
#endif

