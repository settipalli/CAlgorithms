/*
 * Sieve of Eratosthenes
 * The implementation has four loops.
 *  The goal is to set a[i] to 1 if i is Prime, else set a[i] to 0 if i is not Prime.
 *  In the first pass, all array elements are set to 1.
 *  In the second pass, all array indices that are known to be non Prime are set to 0 (multiples of Primes).
 *  If a[i] is 1 after all known multiples of smaller primes are set to 0, then we know it to be Prime.
 *
 * Complexity: N + N/2 + N/3 + N/5 + N/7 + N/11 + ...
 *  This is less than N + N/2 + N/3 + N/4 + N/5 + ... = NHn ~ N lg N
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

void printTime(clock_t t1, clock_t t2) {
    float diff((float) t2 - (float) t1);
    cout << "\n== Time =====\n";
    cout << diff << " µs\n";
    cout << diff / 1000 << " ms\n";
    cout << fixed << diff / CLOCKS_PER_SEC << " s" << "\n"; // `fixed` => don't display scientific notation.
    cout << "=============\n";
}

int main() {
    ios::sync_with_stdio(false);

    clock_t t1 = clock();

    const int N = (int) pow(10, 4);
    /*
     * within a function, arrays cannot contain more than 10^6 elements
     * global arrays can contain 10^7 elements.
     */
    int a[N]; // a[0] and a[1] are ignored
    fill_n(a, N, 1);

    for (int i = 2; i < N; ++i) {
        if (a[i]) {
            for (int j = i; j * i < N; ++j) {
                a[j * i] = 0;
            }
        }
    }

    int count = 0;
    cout << "Primes: ";
    for (int k = 2; k < N; ++k) {
        if (a[k]) {
            cout << k << "\n"[k < N];
            count++;
        }
    }
    cout << "\n" << count << " Primes.";

    clock_t t2 = clock();
    printTime(t1, t2);
    return 0;
}
