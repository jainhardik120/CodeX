#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>

int readers_count = 0;
std::mutex mtx;
sem_t rw_mutex, mutex;

void reader(int id) {
    while (true) {
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);

        // Read the data

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);

        // Continue reading
    }
}

void writer(int id) {
    while (true) {
        sem_wait(&rw_mutex);

        // Write data

        sem_post(&rw_mutex);

        // Continue writing
    }
}

int main() {
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    const int num_readers = 3;
    const int num_writers = 2;
    std::thread readers[num_readers];
    std::thread writers[num_writers];

    for (int i = 0; i < num_readers; i++) {
        readers[i] = std::thread(reader, i);
    }

    for (int i = 0; i < num_writers; i++) {
        writers[i] = std::thread(writer, i);
    }

    for (int i = 0; i < num_readers; i++) {
        readers[i].join();
    }

    for (int i = 0; i < num_writers; i++) {
        writers[i].join();
    }

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}
