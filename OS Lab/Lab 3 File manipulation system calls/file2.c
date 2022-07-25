#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    // open
    int fd = open("test.txt",  O_CREAT|O_RDWR, 0642);
    if (fd == -1)
        printf("Cannot open file!\n");
    else
        printf("File opened sucessfully\n");

    // write
    char buffer1[] = "hello world";
    write(fd, buffer1, strlen(buffer1));
    printf("Write: %s\n", buffer1);

    // seek
    lseek(fd, 0, SEEK_SET);

    // read
    char buffer2[12];
    read(fd, buffer2, 11);
    buffer2[11] = 0;
    printf("Read: %s\n", buffer2);

    // close
    if (close(fd) == -1)
        printf("Cannot close file!\n");
    else
        printf("File closed sucessfully\n");

    return 0;
}
