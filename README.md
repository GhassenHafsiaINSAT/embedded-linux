# embedded-linux
A toolchain is set of packages needed to create a software for a specific device
It will be used to generate: 
- the bootloader
- the kernel
- the root filesystem

toolchains are usually based on either: 
- GNU project and the compiler system GCC
- Low Level Virtual Machine  (LLVM)

the standard GNU toolchain includes: 
- compilers able to compile C, C++, Aseembly, JAVA
- Binutils to turn assembly code into binary ("as") and link bojects to create executable files ("id")
- C library implemeting POSIX APIs able to talk to this kernel
- Debugger
