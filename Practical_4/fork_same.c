#include <stdio.h>
#include <unistd.h>

// Same program, same code for parent and child
int main() {
    printf("Before fork\n");

    pid_t pid = fork();      // create child process

    // both parent and child execute this line
    printf("After fork, PID = %d\n", getpid());

    return 0;
}

// output

Before fork
After fork, PID = 1234
After fork, PID = 1235
