# Toolchain
- A toolchain is a set of tools (compiler, linker and run-time libraries) that compiles source code into an executables that can run on your target device

- A toolchain should support the language that you require and have a solid implementation of POSIX.  

- A standard gnu toolchain consists of: 
        - Binutils : binary utilities, including the assembler and the linker. 
        - GNU Compiler Collection (GCC) : compilers for C,C++,JAVA.. 
        - C library : the priciple interface to the operating system kernel from applications.
  

## Types of toolchain 

### Native toolchain
- This toolchain runs on your workstation and generates code for you workstation (usually x86).
- You can install the natice toolchain on your ubuntu machine using this command:
```sh
sudo apt install build-essential
``` 

### Cross-compiling toolchain
- This toolchain runs on you workstation but generates code for your target.
- **Host-triplet**
  - The **build** machine, where the toolchain is built
  - The **host** machine, where the toolchain will be executed
  - The **target** machine, where the binaries created by the toolchain are excuted 

## Components of toolchain 
### Binutils 
- A set of tool to generate and manipulate binaries for a given cpu architectures
  - **as**, the assembler, generates binary code from assembler source code.
  - **ld**, the linker
  - **ar**,**ranlib**, to generate **.a** archieves, used for libraries...

## Kernel headers 
- The C library and compiled programs need to interact with the kernel

### C/C++ compiler 
- **GCC**: GNU Compiler Collection, the famous free software compiler
- alternative: Clang, LLVM compiler

### C library
- Interface between the  applications and the kernel
- Provides the well-known standard C API to ease application development
  
![image](https://github.com/user-attachments/assets/d4a73ae7-d6ec-46c9-878e-6e4f244b1bc7)


- C libraries: 
  - **glibc**: The standard GNU C library 
  - **eglibc**: This is the embedded GLIBC 
  - **µClibc**
  - **musl libc**
 
## toolchain operations 
### ABI
- When building a toolchain, the ABI (Application binary interface) used to generate binaries needs to be defined.
- ABI, defines the calling conventions (how the arguments are passed, how return value is passed, how system calls are made) and the organization of structures (aligment).
- On ARM, two main ABIs, EABI and OABI, when building a toolchain you need to choose one of them, nowadays, everybody uses EABI.

### Floating Point Support
- Some processors have a floating point, unit, some others do not
  
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

## Building a toolchain using Crosstool-NG 

- **Crosstool-NG allows you to see the process of creating the toolchain.

- Before you can Build a toolchain, you need first a working native toolchain and build tools on your host PC.

- The linux `tar` stands for tape archive, used to create and extract archive files.

```sh
tar [options] [archive-file] [file or directory to be archived]
```

- An archieve file is a file that is compressed of one or more files along with metadata, for easier portability and storage.  

- `-c` : Creating a new archieve.  
- `-x` : Extract files from archieve.  
- `-v` : Displaying verbose output, showing the progress of the archiving/extraction process.
- `-f` : Specifying the filename.

- Note that tar is for archiving files (combines multiple files and directories into one archive file) and not compressing files. Instead, you can use a combination of tar and gzip (compression tool) or zip (combined archiving and compression tool).

### Selecting the toolchain 

- Crosstool-NG can build many different combinations of toolchains, it comes with a set of samples that cover many of the common use-cases.

- Use `./ct-ng list-samples`to generate this list.

- You can see the default configuration of a specific architecture by typing :

```sh
$ ./ct-ng show-arm-cortex_a8-linux-gnueabi
[L...]   arm-cortex_a8-linux-gnueabi
    Languages       : C,C++
    OS              : linux-6.4
    Binutils        : binutils-2.40
    Compiler        : gcc-13.2.0
    C library       : glibc-2.38
    Debug tools     : duma-2_5_21 gdb-13.2 ltrace-0.7.3 strace-6.4
    Companion libs  : expat-2.5.0 gettext-0.21 gmp-6.2.1 isl-0.26 libelf-0.8.13 libiconv-1.16 mpc-1.2.1 mpfr-4.2.1 ncurses-6.4 zlib-1.2.13 zstd-1.5.5
    Companion tools :
``` 
- To select this as target configuration you can type
```
$ ./ct-ng arm-cortex_a8-linux-gnueabi
```
- At this point, you can review the configuration and make changes using :
```
$ ./ct-ng manuconfig
```

- Its recommended to change these configurations :  
                  - In **Path and misc** options, desable **Render the toolchain read-only**, it allows modifications to files in the toolchain directory.  
                  - In **target options | floating point**,  select **hardware (FPU)**, it specifies that the toolchain should use hardware floating point operations instead of software-based floating point operations in order to improve performance.  
                  - In **C-library | extra config**, add **--enable-obsolete-rpc**, it ensures that the toolchain's C library can handle legacy RPC calls.  
           
- The configuration data is saved into a file named .config

- ABI stands for **Application binary interface**, defines how components of binary code, such as libraries, programs interact at the binary level.

- ARM architecture uses different ABIs for floatinh point operations :
          - One uses integer registers for floating point parameters
          - Another uses VFP  (vector floating point) 
