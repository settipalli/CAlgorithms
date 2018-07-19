#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template<typename S, typename T>  using map = unordered_map<S, T>;

template<typename T> using set = unordered_set<T>;

int main() {
    freopen("../data/graph.txt", "r", stdin);
    ios::sync_with_stdio(false);

    int V;
    cin >> V;

    map<int, set<int>> G;

    for (int v = 0; v < V; ++v) {
        set<int> adj;
        G.insert({v, adj});
    }

    int v, w;
    while (cin >> v >> w) {
        G[v].insert(w);
        G[w].insert(v);
    }

    for (pair<int, set<int>> element: G) {
        cout.width(2);
        cout << element.first <<" : ";
        for(int w: element.second) {
            cout.width(2);
            cout << w << " ";
        }
        cout << endl;
    }
}