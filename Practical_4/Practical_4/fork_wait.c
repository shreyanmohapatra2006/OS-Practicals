#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Parent waits for child to finish
int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // child process
        printf("Child running...\n");
        sleep(2);                      // simulate some work
        printf("Child finished.\n");
    } else if (pid > 0) {
        // parent process
        wait(NULL);                    // wait for child to end
        printf("Parent: child completed, now exiting.\n");
    } else {
        perror("fork");
    }
    return 0;
}

//output

Child running...
Child finished.
Parent: child completed, now exiting.
