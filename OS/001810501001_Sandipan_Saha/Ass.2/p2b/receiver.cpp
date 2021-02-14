#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include <fcntl.h> 
 #include<mqueue.h>
#include <sys/msg.h>
#include<cstring>

using namespace std;

#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 80
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

signed main() {

    pid_t pid = getpid();
    FILE *f = fopen("processes.txt", "a");
    string str = "/" + to_string(pid);
    char *name = (char *)str.c_str();
    fprintf(f, "%s\n", name);
    fclose(f);

    mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
    mqd_t mqd = mq_open(name, O_CREAT|O_RDONLY, QUEUE_PERMISSIONS, &attr);
    char buff[MSG_BUFFER_SIZE];

    while(true) {
        int num = mq_receive(mqd, buff, MSG_BUFFER_SIZE, NULL);
        if(!strcmp(buff, "exit")) break;
        
        printf("New Report: %s\n", buff);
        fflush(stdin);
    }
    mq_close(mqd);
    mq_unlink(name);

    return 0;
}
