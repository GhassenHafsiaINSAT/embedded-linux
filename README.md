# Embedded Linux
## Project Lifecycle: 
- Elements of embedded system
- System architecture and design choices (storage of programs and data, divide work between kernel device driver and applications, how to initialize the system)
- Writting embedded applications (how to make effective use of the linux process and threads model, and how to manage memory in a resource-constrained device) 
- Debugging and optimizing performance (how to trace, profile, debug your code in applicatios and kernel) 

## The four elements of embedded linux:
- toolchain (compiler and other tools to create code for your target device) 
- boatloader (initialize the board, load and boot the linux kernel)
- kernel (managing system ressources and interfacing with hardware) 
- Root filesystem (libraries and programs running on the kernel) 


## Hardware for embedded linux
- CPU (architecture supported by the kernel) (30 architectures), with MMU.  
- 16 mib ram and 8 mib for non-volatil storage.  
- debug port.   
- mean of loading software from scratch, SD cards, serialinterface (usb).   

GNU : application (commandes ...) /Linux:noyau
1. construire un compilateur:
  - pour des raisons de performance, on a besoin de compiler sur notre pc et pas sur la carte
  - un compilateur native, gere des executable pour la meme machine
  - un compilateur croisé, pour un type d'architecture autre que notre machine
  - on doit alors construire ce compilateur
2. construire un bootloader (u-boot)
3. construire un kernel linux et le compiler avec compilateur deja construit
4. userspace/rootfs/minimal filesystem (busybox) 
5. constatation, refaire ces etapes est penible et prends du temps,
des outils pour automatiser ces 4 etapes, avec YOCTO

 embedded linux is the usage of the linux kernel and open source components in embedded systems
