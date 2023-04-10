#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = open("file", O_RDONLY);
    // perror("");
    write(fd, "hello", 5);
    printf("%s\n", strerror(errno));
}