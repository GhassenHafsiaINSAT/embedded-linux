# Libraries
- A library is a collection of software.  
- A library is a group of pre-compiled codes, called functions

## Why do we need libraries in programming 

- It saves time
- We don't need to rewrite the function's code each time we need it 

## Types of libraries 

### Static library

- The code to run the file is in one executable file and gets copied into target applications.  
- It is locked into the program at compile time, it can not be modified without recompilation.  
- Due to multiple copies, size is very large.  
- It take much time to execute, beacuase of step of library loading into memory is done multiple times during execution.  
- No compatibility issue because it resides in the executable file.  

### Dynamic library

- Only the adress of the library is provided in the target program so every program can access them without creating copies.  
- It acts as a separate file out of executable so can be moidified at anytime without recompilation.  
- Due to single copy, size is quite smaller.  
- It is faster as the library code is present already in the memory.  
- If the library is removed, then executable file will not work, compatibility issue.  
