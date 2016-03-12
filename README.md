# arm-none-eabi-startup

Startup, vector tables and default exception/interrupt handlers for variuos uCs

Library requires the following symbols defined in linker script:

```
__top_of_stack - end of RAM area where stack located
__idata_start  - start of initializers section
__data_start   - start of initialized data section
__data_end     - end of initialized data section
__bss_start    - start of zero-filled data section
__bss_end      - end of zero-filled data section
```

