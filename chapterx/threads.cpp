#include <iostream>
#include <pthread.h>

using namespace std;

void* threadProc(void *param) {
    for (int count = 0; count < 3; ++count) {
        cout << "Message " << count << " from " << pthread_self() << endl;
        pthread_exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);

    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, nullptr, threadProc, nullptr);
    pthread_create(&thread2, nullptr, threadProc, nullptr);
    pthread_create(&thread3, nullptr, threadProc, nullptr);

    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    pthread_join(thread3, nullptr);

    return 0;
}