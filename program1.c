#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int m;
    int n;
} ThreadParams;

void *thread_function(void *arg);

int main() {
	pthread_t a_thread; //thread declaration
	ThreadParams params;
	params.m = 5;
	params.n = 7;
	
	void *result;
	pthread_create(&a_thread, NULL, thread_function, &params);
	//thread is created
	pthread_join(a_thread, &result); //process waits for thread to finish .
	//Comment this line to see the difference
	printf("%d",params.m);
	printf(" + ");
	printf("%d",params.n);
	printf(" = ");
	printf("%d",(int)result);
}
void *thread_function(void *arg) {
	// the work to be done by the thread is defined in this function
	printf("Inside Thread\n");
	ThreadParams* params = (ThreadParams*)arg;
	int m = params->m;
	int n = params->n;
	
	pthread_exit(m+n);
}
