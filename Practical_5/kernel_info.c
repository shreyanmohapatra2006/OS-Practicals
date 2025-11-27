#include <stdio.h>
#include <sys/utsname.h>

// Program to display Linux kernel and CPU info
int main() {
    struct utsname u;

    if (uname(&u) == -1) {
        perror("uname");
        return 1;
    }

    printf("System name : %s\n", u.sysname);
    printf("Node name   : %s\n", u.nodename);
    printf("Release     : %s\n", u.release);  // kernel version
    printf("Version     : %s\n", u.version);
    printf("Machine     : %s\n", u.machine);  // CPU type

    return 0;
}
