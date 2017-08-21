# k60 Control - libbase

## Author: Peter Tse (mcreng), Dipsy Wong

### Introduction

### Pin Configuration

### GPIO

#### GPI

#### GPO

### PWM

### ADC

### UART

---

### PIT

PIT,  Periodic Interrupt Timer, a listener function will be triggered periodically when the timer count a specific time, during the program run time. Be careful, when PIT is triggered, the normal program rundown will pause. Therefore, if PIT is called too frequently, your program cannot run.

| Config    | Datatype     | Description                    |
| --------- | ------------ | ------------------------------ |
| `channel` | `uint8_t`    | 0~3, different                 |
| `count`   | `uint32_t`   | 1 count = timer oscillate once |
| `isr`     | `void(Pit*)` | pit listener                   |

The following code is a led blink per 250ms using pit as control.

```C++
#include "libbase/k60/pit.h"
#include "libsc/led.h"

namespace libbase {
namespace k60 {
Mcg::Config Mcg::GetMcgConfig() {
  Mcg::Config config;
  config.external_oscillator_khz = 50000;
  config.core_clock_khz = 150000;
  return config;
}
}  // namespace k60
}  // namespace libbase

using libbase::k60::Pit;
using libsc::Led;

Led* pLed = nullptr;

void blink(Pit*){
  pLed->Switch();
}

int main(){
  Led::Config ledConfig;
  ledConfig.id = 0;
  Led led(lefConfig);
  Pit::Config pitConfig;
  pitConfig.channel = 0;
  pitConfig.count = 75000*250;
  pitConfig.isr = &blink;
  Pit pit(pitConfig);
  while(1);
  return 0;
}

```





### SPI

### I2C

### Flash

