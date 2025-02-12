#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

const int BUFFER_SIZE = 5;

std::vector<int> buffer;
std::mutex mtx;
std::condition_variable producer_cv, consumer_cv;

void producer() {
    for (int i = 1; i <= 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        while (buffer.size() == BUFFER_SIZE) {
            producer_cv.wait(lock);
        }
        buffer.push_back(i);
        std::cout << "Produced: " << i << std::endl;
        consumer_cv.notify_all();
    }
}

void consumer() {
    for (int i = 1; i <= 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        while (buffer.empty()) {
            consumer_cv.wait(lock);
        }
        int item = buffer.back();
        buffer.pop_back();
        std::cout << "Consumed: " << item << std::endl;
        producer_cv.notify_all();
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
