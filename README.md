# Process Communication: Linux Processes and IPC
Given a list of integers find the Minimum, Maximum, and the Sum of the numbers. The list will be in a text file you generate. You may use any form of interprocess communication (IPC) to partition the file/array into chunks and distribute work to more than one processes (if there are multiple ones) (e.g., pipes, shared memory, or additional (perhaps more sophisticated) inherent process system calls).

## Usage
|            |                                                              |                                | 
|------------|--------------------------------------------------------------|--------------------------------| 
| Problem 1: | `./pa.sh <input file> <output file>`                         | `./pa.sh 100k.in part_a.out`   | 
| Problem 2: | `./pb.sh <input file> <output file> <number of processes>`   | `./pb.sh 100k.in part_b.out 8` | 
| Problem 3: | `./pc.sh <input file> <output file> <number of processes>`   | `./pc.sh 100k.in part_c.out 8` | 
| Problem 4: | `./pd.sh <input file> <output file> <depth of process tree>` | `./pd.sh 100k.in part_d.out 4` | 

## Files
Code files:  
`info.h`  
`part_a.c`  
`part_b.c`  
`part_c.c`  
`part_d.c`  

Test input file:  
`100k.in`

Output files:  
`part_a.out`  
`part_b.out`  
`part_c.out`  
`part_d.out` 

## How it Works
The following approaces were implemented to compute the minimum, maximum, and sum of a list of numbers in an input file:
  1. Single process
  2. Multiple processes where each process spawns at most one process
  3. Multiple processes where first process spawns all other processes
  4. Multiple processes where each process can spawn multiple other processes (in our implementation, each parent process was forced to spawn exactly two child processes)
        * Number of processes = 2^(k - 1) where k represents the depth of the process tree

## Inter-Process Communication (IPC):  
### Pipes

### Shared Memory
The IPC occurs recursively through a custom function called *process(start, info_struct * info, perProcessRemainder)* which takes in *start*, the start position of each array division, a structure containing *min*, *max*, *sum*, and *count* called *info_start*, and the *perProcessRemainder*, which holds the amount of integers that get allocated per process. The integers are loaded from the input into an array, which is partitioned equally depending on the number of processes (or depth of process tree in the case of problem 4). Pipelines and shared memory are then used as the main form of IPC as a way for the the parent process to communicate with the child process. The information contained within the struct, namely *min*, *max*, and *sum*, are finally written to the chosen output file.

## Analysis
### Time (μs) to Process List of Numbers
|Number of processes| Problem number   |**10**|**100**|**1000**|**10000**|**100000**|    
| :-------------:   |:----------------:|:----:|:-----:|:------:|:-------:|:--------:|    
| 1                 |A                 |1422  |1693   |1262    |1836     |13435     |    
| 4                 |B                 |2569  |2594   |2456    |3867     |9770      |    
|                   |C                 |2377  |2958   |2811    |3698     |10332     |  
|                   |D                 |2320  |2682   |2834    |3685     |8621      |  
| 8                 |B                 |2579  |2881   |3354    |4722     |10927     |      
|                   |C                 |2828  |2448   |2771    |3462     |9177      |    
|                   |D                 |2104  |2570   |2201    |3248     |8573      |    
| 16                |B                 |-     |3406   |3799    |5705     |15516     |      
|                   |C                 |-     |2899   |4935    |4047     |15957     |    
|                   |D                 |-     |3152   |4506    |5178     |14257     |    

    Since we ideally want the number of processes to be on the order of the number of cores for the system, we varied the number of processes to be 1, 4, 8, and 16, though they can be modified as per the user's choice.  
    
    From the table, it is easily observable that for larger input test files and higher number of processes, one can expect larger run times. Note that these run-times were compiled over several runs of each input file in order to record the results more accurately.
    
    
    





