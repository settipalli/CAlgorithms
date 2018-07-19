#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter4/Stack.cpp"

using namespace std;

int main() {
    srand(time(NULL));
    int N = 1000000;
    Stack<int> s(0);
    for (int i = 0; i < N; ++i) {
        s.push((rand() % N) + 1);
    }

    int count = 0;
    while (!s.empty() && ++count) {
        cout.width(5);
        cout << s.pop() << " ";
    }
    cout << endl << "Count: " << count;
    return 0;
}