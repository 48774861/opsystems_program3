#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
	pid_t p1,p2;
	
	// Parent P creates one child P1
	p1=fork();
	
	if(p1==0) // Child P1 runs
	{
	        p2=fork(); // Child P1 creates one child P2 of its own.
		if(p2==0) // Child P2 runs
		{
			printf("I am child P2 having id %d\n",getpid());
			printf("My parent P1's id is %d\n",getppid());
		}
		else // Child P1 continue to run here.
		{
			waitpid(p2,NULL,0); // P1 waits for its child P2 to finish.
			printf("I am child P1 having id %d\n",getpid());
		        printf("My parent P's id is %d\n",getppid());
		}
	}
	else // Parent P runs here
	{
		waitpid(p1,NULL,0); // Parent P waits to child P1 to finish.
		printf("I am parent P having id %d\n",getpid());
                printf("My child P1's id is %d\n",p1);
	}
}
