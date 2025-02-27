#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void *thread1_function(void *arg);
void *thread2_function(void *arg);

int main() {
	pthread_t thread1, thread2; //thread declaration
	
	void* file;
	pthread_create(&thread1, NULL, thread1_function, NULL);
	//thread is created
	pthread_join(thread1, &file); // process waits for thread to finish.

  pthread_create(&thread2, NULL, thread2_function, file);
  pthread_join(thread2, NULL); // process waits for thread to finish.
	
}
void *thread1_function(void *arg) {
	// the work to be done by the thread is defined in this function
  int fd = open("test.txt",O_WRONLY);
	pthread_exit(fd);
}
void *thread2_function(void *arg) {
	// the work to be done by the thread is defined in this function
  int fd = atoi(arg);
  n = 12;
  char buff[50] = "Hello its T2";
  write(fd, buff, n);
  pthread_exit(NULL);
}
