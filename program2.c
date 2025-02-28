#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Declarations for Thread Functions.
void *thread1_function(void *arg);
void *thread2_function(void *arg);

int main() {
  pthread_t thread1, thread2; // Thread declarations.

  // Stores the File Descriptor returned by thread1.
  void* file;
  
  // Creates and waits for thread1 to open and return the file descriptor.
  pthread_create(&thread1, NULL, thread1_function, NULL);
  pthread_join(thread1, &file);
  
  // Creates and waits for thread2 to write to test.txt
  pthread_create(&thread2, NULL, thread2_function, file);
  pthread_join(thread2, NULL);
	
}

void *thread1_function(void *arg) {
  // Opens "test.txt" and allow write-only and create access
  int fd = open("Thread.txt",O_WRONLY|O_CREAT,0642);
  
  // Casts the file descriptor as void* so file will accept it.
  pthread_exit((void*)(intptr_t)fd);
}

void *thread2_function(void *arg) {
  // Get the int file descriptor from void* 
  int fd = (int)(intptr_t)arg;
  
  int n = 12;
  char buff[50] = "Hello its T2";
  
  // Write the text above to the file and output something if it succeeds or fails.
  if (write(fd, buff, n) == -1) {
    perror("Failed to write");
  } else {
    printf("Successfully wrote to the file.\n");
  }
  
  pthread_exit(NULL);
}
