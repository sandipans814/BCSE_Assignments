#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include <fcntl.h> 
#include<cstring>

using namespace std;

signed main() {

    mkfifo("temp", 0666);
    char sent[101], received[101];
    int fd;

    while(true) {
        fd = open("temp", O_RDONLY);
        read(fd, received, sizeof received);
        if(strcmp(received, "bye\n")) printf("User 1 >> %s", received);
        else {
            close(fd);
            break;
        }

        fd = open("temp", O_WRONLY);
        printf("User 2 >> ");
        fgets(sent, 101, stdin);
        printf("\n");
        write(fd, sent, strlen(sent)+1);
        close(fd);
        if(!strcmp(sent, "bye\n")) break;
    }

    return 0;
}
