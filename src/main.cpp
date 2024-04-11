#include <stdio.h>
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "GpioController.h"


int main() {
  //initializing the gpio pin function
    stdio_init_all();


    GpioController gpio_controller;
  //settingg up the GPIO
    gpio_controller.set();
  //interrupt loop
    gpio_controller.interrupt();  


    return 0;
}