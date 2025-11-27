#include <stdio.h>
#include <sys/sysinfo.h>

// Program to display configured, free and used memory
int main() {
    struct sysinfo info;

    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return 1;
    }

    long total = info.totalram / (1024 * 1024);  // in MB
    long free  = info.freeram  / (1024 * 1024);
    long used  = total - free;

    printf("Total RAM : %ld MB\n", total);
    printf("Free RAM  : %ld MB\n", free);
    printf("Used RAM  : %ld MB\n", used);

    return 0;
}

//output

Total RAM : 4096 MB
Free RAM  : 1200 MB
Used RAM  : 2896 MB
