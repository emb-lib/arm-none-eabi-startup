# arm-none-eabi-startup

Startup code, vector tables and default exception/interrupt handlers for various uCs

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

Library requires the following symbols to be defined in the user's linker script:

```
__top_of_stack - end of RAM area where stack located
__idata_start  - start of initializers section
__data_start   - start of initialized data section
__data_end     - end of initialized data section
__bss_start    - start of zero-filled data section
__bss_end      - end of zero-filled data section
```

## Startup

Startup code is unified and very simple. It consists of `Reset_Handler` and two `weak` initialization functions. 

### Reset handler
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
### Initialization functions
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
At first, `__low_level_init()` function called. The function by default returns `1` that means to perform initialization of RAM data objects. The user can override this function - in particular, to set up clock speed, check type of start ('cold', 'warm', etc.) and return `0` if required that causes skip of initialization.

The second initialization function `_init()` called from `__libc_init_array()`<sup>[1](#footnote1)</sup> just before calling of global class-object constructors.

This flexible approach allows for the user to run custom initialization code to satisfy user's project demands.

## Debug and Release options

### Default handler stubs

Vector table uses weak handler stubs that can be overrided in the user's project code. There are two sets of the stubs - for debug and release configurations. Debug configuration includes sepatate 'empty' function for each handler:

```C++
__attribute__ ((noreturn))
static void default_handler() { for(;;) { } }

```
and special function for HardFault_Handler:

```C++
static void hf_handler()
{
    volatile int i = 0;         //  debug variable: set non-zero value to 
    while(!i) { }               //  return from handler - this figures out 
                                //  an address where HW fault raises
}
```
Such code allows the user to change value of internal variable `i` to cause return from the handler and, therefore, jump to program address where Hard Fault had occured.

In release configuration all vector table addresses point to the same default handler. This reduces code memory consumption.

### Control

By default, debug configuration is turned on. The user can switch release configuration by definition of `NDEBUG` macro with `-D` command line option.

<hr>
<a name="footnote1"></a>[1] Library function from GCC toolchain.
