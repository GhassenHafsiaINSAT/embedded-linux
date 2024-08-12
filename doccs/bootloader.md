# Bootloader

- The bootloader is a piece of code responsible for :
  - Basic hardware initialization
  - Loading of application binary, usually an operating system kernel, from flash storage, form the network, or from another type of non-volatile storage
  - Possibly decompression of the application binary (if it is compressed)
  - Execution of the application
- After finishing these tasks, the bootloader has nothing to do, and the memory used by itself is reused by the kernel 


## Boot sequence

### Bootloaders on BIOS-based x86
- The BIOS is responsible for basic hardware initialization and loading a very small piece of code (first 512 bytes) from non-volatile storage, to the RAM and detect the peripherals
- These 512 bytes, called master boot record MBR, is typically a 1st stage bootloader, which will load the full bootloader itself 
- This sequence is different for modern EFI-based systems

## U-boot bootloader
 
