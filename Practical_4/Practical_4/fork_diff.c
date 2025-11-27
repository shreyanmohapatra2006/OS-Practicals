#include <stdio.h>
#include <unistd.h>

// Same program, different code for parent and child
int main() {
    pid_t pid = fork();      // create child process

    if (pid == 0) {
        // Code executed only by child process
        printf("Child process: PID = %d\n", getpid());
    } else if (pid > 0) {
        // Code executed only by parent process
        printf("Parent process: PID = %d, Child PID = %d\n",
               getpid(), pid);
    } else {
        // fork failed
        perror("fork");
    }
    return 0;
}
