#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>
#include<fcntl.h>
#include<thread>

using namespace std;

class LightSwitch {
public:
    int counter;
    sem_t *mutex;

    LightSwitch(char *name) {
        counter = 0;
        mutex = sem_open(name, O_CREAT, O_RDWR, 1);
    }

    void lock(sem_t *semaphore) {
        sem_wait(mutex);
        counter++;
        if(counter == 1) {
            sem_wait(semaphore);
        }
        sem_post(mutex);
    }

    void unlock(sem_t *semaphore) {
        sem_wait(mutex);
        counter--;
        if(counter == 0) {
            sem_post(semaphore);
        }
        sem_post(mutex);
    }

    ~LightSwitch() {
        sem_close(mutex);
    }
};

signed main() {
    srand(time(NULL));

    int Db = 0; // shared db
    int writerCnt, readerCnt;
    cout << "Enter number of writer threads : ";
    cin >> writerCnt;
    cout << "Enter number of reader threads : ";
    cin >> readerCnt;

    LightSwitch readSwitch = LightSwitch((char *)"readSwitch");
    LightSwitch writeSwitch = LightSwitch((char *)"writeSwitch");
    sem_t *noReader = sem_open("noReader", O_CREAT, O_RDWR, 1);
    sem_t *noWriter = sem_open("noWriter", O_CREAT, O_RDWR, 1);

    auto writer = [&]() {
        sleep(1 + rand()%2);
        writeSwitch.lock(noReader);
        sem_wait(noWriter);
        cout << "[ New Db value set ]\n";
        Db = rand();
        sem_post(noWriter);
        writeSwitch.unlock(noReader);
    };

    auto reader = [&]() {
        sleep(1 + rand()%2);
        sem_wait(noReader);
        readSwitch.lock(noWriter);
        sem_post(noReader);
        cout << ">> Current Db value : " << Db << "\n";
        readSwitch.unlock(noWriter);
    };

    vector<thread> writers, readers;
    for(int i = 0; i < writerCnt; i++) writers.push_back(thread(writer));
    for(int i = 0; i < readerCnt; i++) readers.push_back(thread(reader));

    for(auto &th : writers) th.join();
    for(auto &th : readers) th.join();

    sem_close(noWriter);
    sem_close(noReader);
    sem_unlink("noWriter");
    sem_unlink("noReader");
    sem_unlink("readSwitch");
    sem_unlink("writeSwitch");

    return 0;
}