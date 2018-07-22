/* Recursive knapsack implementation */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
    int size;
    int value;
};

int knap(int capacity, Item items[], int N, int depth) {
    static int callCount = 0;
    ++callCount;
    cout << string(depth, ' ') << "knap(" << capacity << "): cc:" << callCount << endl;
    int maxValue = 0;
    for (int i = 0; i < N; ++i) {
        int leftOverSpace = capacity - items[i].size;
        if (leftOverSpace >= 0) {
            // if any space is left
            int t = knap(leftOverSpace, items, N, depth + 4);
            if (t + items[i].value > maxValue)
                maxValue = t + items[i].value;
        }
    }
    return maxValue;
}

int main() {
    ios::sync_with_stdio(false);
    ifstream fin("../data/knapsack.txt");
    int N;
    fin >> N;
    Item items[N];
    for (int i = 0; i < N; ++i) {
        fin >> items[i].size >> items[i].value;
    }
    int maxValue = knap(17, items, N, 0);
    cout << "Max value: " << maxValue << endl;
    return 0;
}