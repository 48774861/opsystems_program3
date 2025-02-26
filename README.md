# Operating Systems: Programming 2
Name: Marc Pham  
CS5343 student must perform Program 1 and Program 2 only.
## Program 1
Program 1 asks us to use the fork() system call to create a hierarchy of 3 processes such that P is the parent of P1 and P1 is the parent of P2. The program `program1.c` begins by having the Parent process (P) create a Child process (P1) using `fork()` within the `main()` function. An if statement is used to distinguish between the Parent (P) and the Child (P1) processes. The Child process (P1) then uses `fork()` again to create its own Child (P2). Each process (P, P1, and P2) then prints out the ID of its corresponding parent or child. 

Looking at the snapshot (program1_output.png), we see that P (id: 5542) has a child P1 (id: 5542). Additionally, we see that P1 has a child P2 (id: 5543).
![plot](program1_output.png)
## Program 2
Program 2 asks us to create two child processes for the parent process, forcing the parent process to wait for both child processes to finish. The program `program2.c` begins by having the parent process create the first child process using `fork()` within the `main()` function. An if statement is then used to distinguish between the parent and first child process. The parent process uses `fork()` again to create its second child process. The parent process and each of the two child processes  then print out the ID of its corresponding parent or child.  

Looking at the snapshot (program2_output.png), we see that the parent process (id: 5987) has two child processes, one with id: 5988 and another with id: 5989. The parent process waits for all child processes, which is why the output for both child processes appears.
![plot](program2_output.png)
