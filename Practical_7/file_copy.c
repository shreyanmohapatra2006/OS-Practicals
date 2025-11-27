#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

// Copy file using system calls: open, read, write, close
int main(int argc, char *argv[]) {
    int in, out;
    ssize_t nread;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    in = open(argv[1], O_RDONLY);
    if (in < 0) {
        perror("open source");
        return 1;
    }

    out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        perror("open destination");
        close(in);
        return 1;
    }

    while ((nread = read(in, buffer, BUF_SIZE)) > 0) {
        if (write(out, buffer, nread) != nread) {
            perror("write");
            close(in);
            close(out);
            return 1;
        }
    }

    close(in);
    close(out);

    printf("File copied successfully.\n");
    return 0;
}

//output

$ ./file_copy source.txt dest.txt
File copied successfully.
