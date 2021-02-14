#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>
#include<fcntl.h>
#include<thread>

using namespace std;

class item {
public:
    int itemId;
    int prodId;
    int conId;
    int payload;

    item(int prodId) {
        itemId = rand();
        this->prodId = prodId;
        payload = 1000 + rand()%9000;
    }

    void setConId(int conId) {
        this->conId = conId;
    }

    void display() {
        cout << "<-- Item Details -->\n";
        cout << "-ItemId : " << itemId << "\n";
        cout << "-ProducerId : " << prodId << "\n";
        cout << "-ConsumerId : " << conId << "\n";
        cout << "-Payload : " << payload << "\n";
    }
};

signed main() {
    srand(time(NULL));

    int prodCnt, conCnt, buffSize;
    cout << "Enter number of producers : ";
    cin >> prodCnt;
    cout << "Enter number of consumers : ";
    cin >> conCnt;
    cout << "Enter Buffer Size : ";
    cin >> buffSize;

    queue<item> buffer;
    sem_t *mutex = sem_open("mutex", O_CREAT, O_RDWR, 1);
    sem_t *items = sem_open("items", O_CREAT, O_RDWR, 0);
    sem_t *spaces = sem_open("spaces", O_CREAT, O_RDWR, buffSize);

    auto producer = [&](int id) {
        sem_wait(spaces);
        sem_wait(mutex);
        cout << "[ New Item produced by Producer " << id << " ]\n";
        item newItem = item(id);
        buffer.push(newItem);
        sleep(1);
        sem_post(mutex);
        sem_post(items);
    };

    auto consumer = [&](int id) {
        sem_wait(items);
        sem_wait(mutex);
        item x = buffer.front();
        buffer.pop();
        x.setConId(id);
        x.display();
        sleep(1);
        sem_post(mutex);
        sem_post(spaces);
    };

    vector<thread> producers, consumers;
    for(int i = 1; i <= prodCnt; i++) {
        producers.push_back(thread(producer, i));
    }

    for(int i = 1; i <= conCnt; i++) {
        consumers.push_back(thread(consumer, i));
    }

    for(auto &th : producers) th.join();
    for(auto &th : consumers) th.join();

    sem_close(mutex);
    sem_close(items);
    sem_close(spaces);
    sem_unlink("mutex");
    sem_unlink("items");
    sem_unlink("spaces");

    return 0;
}