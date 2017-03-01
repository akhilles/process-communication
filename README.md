# Process Communication: Linux Processes and IPC
Given a list of integers find the Minimum, Maximum, and the Sum of the numbers. The list will be in a text file you generate. You may use any form of interprocess communication (IPC) to partition the file/array into chunks and distribute work to more than one processes (if there are multiple ones) (e.g., pipes, shared memory, or additional (perhaps more sophisticated) inherent process system calls).

## How to Execute
Problem 1:  
`./pa.sh <input file> <output file>`  
`./pa.sh 100k.in part_a.out`  
Problem 2:  
`./pb.sh <input file> <output file> <number of processes>`  
`./pb.sh 100k.in part_b.out 8`  
Problem 3:  
`./pc.sh <input file> <output file> <number of processes>`  
`./pc.sh 100k.in part_c.out 8`  
Problem 4:  
`./pd.sh <input file> <output file> <depth of process tree>`  
`./pd.sh 100k.in part_d.out 4`

## Files
Code files:  
`info.h`  
`part_a.c`  
`part_b.c`  
`part_c.c`  
`part_d.c`  

Test input file:  
`100k.in`