# Kernel 
- The kernel is the component that is reponsible for managing resources, interfacing with the hardware and providing an API offering a useful level of abstraction to user space programs.

- Application running in user space run at a low CPU privilege level, they generally make library calls.

- The primary interface between the user space and the kernel space is the C library, translating the user level functions into kernel system calls.

- The system call interface uses an architecture-specific method tp qwitch th CPU from low privileges user mode to high privileges kernel mode, allowing access to all memory addresses and CPU registers.

- The system call  handler dispatches the call to the appropriate kernel subsystem.

- The hardware itself invokes a kernel function by raising an interrupt.

## Building the kernel 

- The Linux kernel is designed to work on a wide range of architectures, but it requires configuration and compilation specific to the target architecture.

- There are over 38,000 files in the kernel containing C source code, header files and assembly code.

- The main directories of inrerest are:  
    -  `arch`:            This contains arechitecutre-specific files, a subdirectory for each architecture.
    - `Doccumentation`:   This contains kernel doccumentation.
    - `drivers`:          This contains device drivers, a  subdirectory for each driver.  
    - `fs`     :          This contains filesystem code
    - `inlcude`:          This contains the kernel header files, including those required when building the toolchain.
    - `init`:              This contains the kernel start-up code  
    - `kernel`:           This contains core functions, like schudeling, locking timers, power management.
    - `mm`:               This contains memory management unit.
    - `net`:              This contains network protocoles.

## Kernel configuration 
- One of the stengths of linux is the degree to which you can configure the kernel to suit different jobs.

- The configuration options are declared in a herarchy of files named *kconfig*.  

## Compiling 
- The kernel build system, *kbuild*, is a set of make scripts that take the configuration information from the .config file
- 
