/* Quick find algorithm.
 * An array of integers. p and q are connected if and only if a[p] == a[q].
 * The array is initiaized with a[i] == i.
 * For every addition, we go through the array and change all entries with same name as p to have same name as q.
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

void printTime(clock_t t1, clock_t t2) {
    float diff((float) t2 - (float) t1);
    cout << "\n== Time =====\n";
    cout << diff << " µs\n";
    cout << diff / 1000 << " ms\n";
    cout << diff / CLOCKS_PER_SEC << " s" << "\n";
    cout << "=============\n";
}

void print(int p, int q, int id[], int N) {
    cout << p << " => " << q << " : ";
    for (int i = 0; i < N; ++i) {
        cout << id[i] << "\n"[i < N - 1];
    }
}

int main(int argc, char *argv[]) {
    freopen("../data/uf.txt", "r", stdin);
    ios::sync_with_stdio(false);
    ostream_iterator<int> output(cout, " ");
    clock_t t1 = clock();

    int N, i, p, q;
    cin >> N;
    int id[N];
    for (i = 0; i < N; i++)
        id[i] = i;
    print(0, 0, id, N);

    while (cin >> p >> q) {
        int t = id[p];
        if (t == id[q]) continue;
        for (i = 0; i < N; ++i) {
            if (id[i] == t)
                id[i] = id[q];
        }
        print(p, q, id, N);
    }
    clock_t t2 = clock();
    printTime(t1, t2);
    return 0;
}