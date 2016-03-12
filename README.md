# arm-none-eabi-startup

Startup code, vector tables and default exception/interrupt handlers for variuos uCs

## Supported families 

### STM32

* STM32F10x 
* STM32F2xx
* STM32F4xx
* STM32L0xx

### NXP

* LPC17xx
* LPC40xx

### EFM32

* EFM32G
* EFM32GG
* EFM32HG
* EFM32JG
* EFM32LG
* EFM32PG
* EFM32TG
* EFM32WG
* EFM32ZG
* EZR32LG
* EZR32WG

## Requirements

Library requires the following symbols defined in linker script:

```
__top_of_stack - end of RAM area where stack located
__idata_start  - start of initializers section
__data_start   - start of initialized data section
__data_end     - end of initialized data section
__bss_start    - start of zero-filled data section
__bss_end      - end of zero-filled data section
```

## Startup

Startup code is unified and very simple. It consists of `Reset_Handler` and two `weak` initializating functions. 

#### Reset handler
```C++
//------------------------------------------------------------------------------
void Reset_Handler()
{
    if( __low_level_init() )
    {
        memcpy(__data_start, __idata_start, __data_end - __data_start); // copy initialized variables
        memset(__bss_start, 0, __data_end - __bss_start);               // zero-fill uninitialized variables
        __libc_init_array();                                            // low-level init & ctor loop
    }
    main();
}
//------------------------------------------------------------------------------
```
#### Initializating functions
```C++
//------------------------------------------------------------------------------
__attribute__ ((weak))
void _init()
{
}
//------------------------------------------------------------------------------
int __low_level_init()
{
    return 1;
}
//------------------------------------------------------------------------------

```

