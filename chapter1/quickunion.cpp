/*
 * Quick Union
 * Based on the concept of roots.
 * If two points are connected, they should have same root.
 */

#include <iostream>

using namespace std;

void toString(int p, int q, int id[], int N) {
    cout << p << " => " << q << " : ";
    for (int i = 0; i < N; ++i) {
        cout << id[i] << "\n"[i < N - 1];
    }
}

int findRoot(int p, int id[], int N) {
    int k = p;
    while(k != id[k]) k = id[k];
    return k;
}

int main() {
    freopen("../data/uf.txt", "r", stdin);
    ios::sync_with_stdio(false);

    int N, p, q;
    cin >> N;
    int id[N];
    for (int i = 0; i < N; ++i) {
        id[i] = i;
    }
    toString(0, 0, id, N);
    while (cin >> p >> q) {
        int pRoot = findRoot(p, id, N);
        int qRoot = findRoot(q, id, N);
        if (pRoot == qRoot) continue;
        id[pRoot] = qRoot;
        toString(p, q, id, N);
    }

    return 0;
}