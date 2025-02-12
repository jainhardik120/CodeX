#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <pthread.h>
#include <semaphore.h>
#include<windows.h>           // for windows

// const int BUFFER_SIZE = 5;

// std::vector<int> buffer;
std::mutex mtx;
int count= 0;
// sem_t empty_slots, filled_slots;

// void producer() {
//     for (int i = 1; i <= 10; ++i) {
//         sem_wait(&empty_slots);
//         std::unique_lock<std::mutex> lock(mtx);
//         buffer.push_back(i);
//         std::cout << "Produced: " << i << std::endl;
//         lock.unlock();
//         sem_post(&filled_slots);
//     }
// }

// void consumer() {
//     for (int i = 1; i <= 10; ++i) {
//         sem_wait(&filled_slots);
//         std::unique_lock<std::mutex> lock(mtx);
//         int item = buffer.back();
//         buffer.pop_back();
//         std::cout << "Consumed: " << item << std::endl;
//         lock.unlock();
//         sem_post(&empty_slots);
//     }
// }

void * increment(void *arg){
    for (int i = 0; i < 100000; i++)
    {
        mtx.lock();
        count++;
        mtx.unlock();
    }
    pthread_exit(0);
}

int main() {
    // sem_init(&empty_slots, 0, BUFFER_SIZE);
    // sem_init(&filled_slots, 0, 0);

    // std::thread producer_thread(producer);
    // std::thread consumer_thread(consumer);

    // producer_thread.join();
    // consumer_thread.join();

    // sem_destroy(&empty_slots);
    // sem_destroy(&filled_slots);
    pthread_t tid[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid[i], NULL, increment, NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }
    
    std::cout << count << std::endl;

    return 0;
}
