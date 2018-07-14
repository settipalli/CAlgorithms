/*
 * Weighted Quick Union
 * Link smaller tree to larger tree.
 * Keep track of the size in an separate array.
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
    int i;
    for (i = p; i != id[i]; i = id[i]);
    return i;
}

int main() {
    freopen("../data/uf.txt", "r", stdin);
    ios::sync_with_stdio(false);

    int N, p, q;
    cin >> N;
    int id[N], sz[N];

    for (int i = 0; i < N; i++) {
        id[i] = i; // each element is its own root.
        sz[i] = 1; // default size is 1 for all roots.
    }

    toString(0, 0, id, N);
    toString(0, 0, sz, N);

    while (cin >> p >> q) {
        int pRoot = findRoot(p, id, N);
        int qRoot = findRoot(q, id, N);
        if (pRoot == qRoot) continue;
        if (sz[pRoot] < sz[qRoot]) {
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            id[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        toString(p, q, id, N);
        toString(p, q, sz, N);
    }

    return 0;
}
