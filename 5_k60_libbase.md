# k60 Control - libbase

## Author: Peter Tse (mcreng), Dipsy Wong

### Introduction

This sections include controls to basic peripherals provided by the MCU. In your SmartCar development, you may seldom use these configurations, but these can help you a lot since you have a greater freedom using libbase than libsc. Understanding these could also allow you to develop the project with a more appropriate mindset.

### Pin Configuration

There are 144 pins in a k60 chip and each pin has a specific role. Consider the following excerpt on pin assignments of k60 chips.

![img](https://i.imgur.com/zaqsUqe.png)

Each pin has a default functionality, but one can alter its functionality through pin configuration. Consider pin #1, its default is a pin for ADC (Analog-Digital Converter), but you can alter it by changing it to a GPIO pin (PTE0), a SPI pin and a UART pin, etc.

The pin configurations are defined in `libsccc/inc/libsc/k60/config/<group name>.h` For example for `2017_inno.h`, we have the following excerpt.

```C++
#define LIBSC_ST7735R_RST libbase::k60::Pin::Name::kPte3
#define LIBSC_ST7735R_DC libbase::k60::Pin::Name::kPte0
#define LIBSC_ST7735R_CS libbase::k60::Pin::Name::kPte4
#define LIBSC_ST7735R_SDAT libbase::k60::Pin::Name::kPte1
#define LIBSC_ST7735R_SCLK libbase::k60::Pin::Name::kPte2
```

Here it defines the five pins of `ST7735R` to correspond to the five pins (according to the pin names) of the chip. Since the module uses SPI (you will learn it in later sections), we will find a `SpiMaster` definition in `libsccc/inc/libsc/st7735r.h`.

```C++
SpiMaster m_spi;
```

When the class `St7735r` is being constructed, the following member initialization is triggered.

```C++
St7735r::St7735r(const Config &config)
		: m_spi(GetSpiConfig()) /* ... */ { /* ... */ }
```

The function `GetSpiConfig()` is defined in `libsccc/src/libsc/st7735r.cpp`

```C++
St7735r::SpiMaster::Config GetSpiConfig()
{
	St7735r::SpiMaster::Config config;
	config.sout_pin = LIBSC_ST7735R_SDAT;
	config.sck_pin = LIBSC_ST7735R_SCLK;
	/* OMITTED */
	return config;
}
```

We can see the pin is being used to configure the module by passing it to SPI configurations.

As a `SpiMaster` class is created, its constructor located at `libsccc/src/libbase/k60/spi_master.cpp`is called.

```C++
SpiMaster::SpiMaster(const Config &config)
		: m_sin(nullptr),
		  m_sout(nullptr),
		  m_sck(nullptr),

		  m_is_init(false)
{
	/* OMITTED */
	InitPin(config);
	/* OMITTED */
}
```

Inside `InitPin(const Config)`,  we have

```C++
void SpiMaster::InitPin(const Config &config)
{
	if (config.sin_pin != Pin::Name::kDisable)
	{
		Pin::Config sin_config;
		sin_config.pin = config.sin_pin;
		sin_config.mux = PINOUT::GetSpiSinMux(config.sin_pin);
		m_sin = Pin(sin_config);
	}
  
  /* OMITTED */
}
```

And finally, the function `PINOUT::GetSpiSinMux(Pin::Name)` in  `libsccc/src/libbase/k60/pinout/<mcu_name>.cpp` allows one to alter the functionalities of the pins.

```C++
Pin::Config::MuxControl Mk60f15Lqfp144::GetSpiSinMux(const Pin::Name pin)
{
	switch (pin)
	{
	default:
		assert(false);
		// no break

	case Pin::Name::kPta17:
	case Pin::Name::kPtb17:
	case Pin::Name::kPtb23:
	case Pin::Name::kPtc7:
	case Pin::Name::kPtd3:
	case Pin::Name::kPtd14:
	case Pin::Name::kPte3:
		return Pin::Config::MuxControl::kAlt2;

	case Pin::Name::kPte1:
		return Pin::Config::MuxControl::kAlt7;
	}
}
```

The pin configurations are similar for other protocols, just that the functions for them are located in different places.

### GPIO

#### GPI

#### GPO

### PWM

### ADC

### UART

---

### PIT

PIT,  Periodic Interrupt Timer, a listener function will be triggered periodically when the timer count a specific time, during the program run time. Be careful, when PIT is triggered, the normal program rundown will pause. Therefore, if PIT is called too frequently, your program cannot run.

Location: `libbase/k60/pit.h`

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

Flash is the permanent memory in the MCU, which means you can get back the variable value when your smart car is turned off.  Be careful, memory may crash if you turn off your smartcar while saving value to flash.

Location : `libbase/k60/flash.h`

| Config             | Datatype  | Description                              |
| ------------------ | --------- | ---------------------------------------- |
| `sectorStartIndex` | `uint8_t` | start sector, change only if you are sure what are you doing |
| `size`             | `size_t`  | memory size, default is 4096 Byte, don't waste memory |

###### Read/Write to Flash

If you have only one type of variables to save, you can directly pass an array pointer to the function. 

```C++
#include "libbase/k60/flash.h"
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
using libbase::k60::Flash;

int main(){
  Flash flash(Flash::Config);
  int myArray[10] = {};
  memset(myArray, 0, sizeof(myArray));
  flash.Read(myArray,sizeof(myArray));	
  //first time: destroyed datas, all nan
  //second time onwards: {0,1,2,3,4,5,6,7,8,9}
  for(int i=0;i<10;i++) myArray[i]=i;
  flash.Write(myArray,sizeof(myArray));
  return 0;
}
```

If you need to save more than one type of variables, I will suggest you to build a new byte array and use `memcpy()` to copy values.

```C++
Byte byte[15];
int v1 = 0;
float v2 = 0;
bool v3 = true;
uint16_t v4 = 0;
char v5 = '';
char* v6 = "hi";

//retriving stored data here
flash.Read(byte,15);
memcpy(v1,byte,4);
memcpy(v2,byte+4,4);
memcpy(v3,byte+8,1);
memcpy(v4,byte+9,2);
memcpy(v5,byte+11,1);
memcpy(v6,byte+12,3);

//saving data
memcpy(byte,v1,4);
memcpy(byte+4,v2,4);
memcpy(byte+8,v3,1);
memcpy(byte+9,v4,2);
memcpy(byte+11,v5,1);
memcpy(byte+12,v6,3);
flash.Write(byte,15);
```

To ensure the data is not `nan`, you can use `==` operator. 

```C++
if(variable==variable){
    //this variable is a number
}
else{
    //this varialbe is not a number
}
```



