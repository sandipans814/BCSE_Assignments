#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main() {

    pid_t pid1, pid2;

    if(fork() == 0) {
        pid1 = getpid();
        for(int i = 1; i <= 10; i++) {
            cout << "Process: " << pid1 << ", Iteration: " << i << "\n";
            sleep(1); 
        }
    }
    else if(fork() == 0) {
        pid2 = getpid();
        for(int i = 1; i <= 10; i++) {
            cout << "Process: " << pid2 << ", Iteration: " << i << "\n";
            usleep(500000);
        }
    }
    while(wait(NULL) > 0);

    return 0;
}