# Toolchain?
- A toolchain is a set of tools (compiler, linker and run-time libraries) that compiles source code into an executables that can run on your target device

- A toolchain should support the language that you require and have a solid implementation of POSIX.  

- A standard gnu toolchain consists of: 
        - Binutils : binary utilities, including the assembler and the linker. 
        - GNU Compiler Collection (GCC) : compilers for C,C++,JAVA.. 
        - C library : the priciple interface to the operating system kernel from applications.
  

### Types of toolchain 

- **Native :** This toolchain runs on the same type of system.  

- **Cross :** This toolchain runs on different type of system, development on pc and testing on an embedded target. 

## CPU architectures

- The toolchain should be built according to the capabilities of the target CPU, which includes:   
        - **CPU architectiure**   
        - **Big or little-endian operation :** Some machines can operate in both modes, but the machine code is different dfor each.   
        - **Floating point support :** Not all processors implement a hardware floating point unit, so the toolchain can be configured to call a software floating point library instead.  
        - **Application Binary Interface :** defines how functions, data structures, and system calls are accessed and represented in binary format.  

- you can print the target triplet for which the GCC compiler is configured. This triplet typically includes the architecture, vendor, and operating system.
```sh
$ gcc -dumpmachine

x86_64-linux-gnu
```
## Chosing the C library 

- The programming interface to the Unix operating system is defined in the C language.
- ![image](https://github.com/user-attachments/assets/d4a73ae7-d6ec-46c9-878e-6e4f244b1bc7)


## C libraries: 
- **glibc**: The standard GNU C library 
- **eglibc**: This is the embedded GLIBC 
- **µClibc**
- **musl libc**


### Crosstool-NG is a tool used for building custom cross-compiling toolchains. 
