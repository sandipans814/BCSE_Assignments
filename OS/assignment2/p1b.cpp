#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<fcntl.h>

using namespace std;

int main() {

    pid_t pid1, pid2;
    sem_t *child1, *child2;
    child1 = sem_open("X", O_CREAT, O_RDWR, 1);
    child2 = sem_open("Y", O_CREAT, O_RDWR, 0);

    if(fork() == 0) {
        pid1 = getpid();
        for(int i = 1; i <= 10; i++) {
            sem_wait(child1);
            cout << "Process: " << pid1 << ", Iteration: " << i << "\n";
            sleep(1); 
            sem_post(child2);
        }
    }
    else if(fork() == 0) {
        pid2 = getpid();
        for(int i = 1; i <= 10; i++) {
            sem_wait(child2);
            cout << "Process: " << pid2 << ", Iteration: " << i << "\n";
            sleep(2);
            sem_post(child1);
        }
    }
    while(wait(NULL) > 0);
    sem_close(child2);
    sem_close(child1);

    return 0;
}