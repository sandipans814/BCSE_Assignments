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

void send(char *name, char *msg) {
    mq_attr attr;
    attr.mq_curmsgs = 0, attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES, attr.mq_msgsize = MAX_MSG_SIZE;
    mqd_t mqd = mq_open(name, O_CREAT|O_WRONLY, QUEUE_PERMISSIONS, &attr);
    mq_send(mqd, msg, strlen(msg)+1, 0);
    mq_close(mqd);
}

signed main() {

    while(true) {
        printf("Broadcast >> ");
        char msg[MAX_MSG_SIZE];
        scanf("%s", msg);

        FILE *f = fopen("processes.txt", "r");
        char name[20];
        while(fscanf(f, "%s", name) != EOF) send(name, msg);
        if(!strcmp(msg, "exit")) break;
    }

    return 0;
}
