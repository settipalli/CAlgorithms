#ifndef CALGORITHMS_GRAPH_H
#define CALGORITHMS_GRAPH_H

struct Edge {
    int v, w;
    Edge (int v = -1, int w = -1): v(v), w(w) { }
};

class GRAPH {
private:
    // implementation dependent code
public:
    GRAPH(int, bool);
    ~GRAPH();
    int V() const;
    int E() const;
    bool directed() const;
    int insert(Edge);
    int remove(Edge);
    bool edge(int, int);
    class adjIterator {
    public:
        adjIterator(const GRAPH k, int);
        int beg();
        int nxt();
        bool end();
    };
};

#endif //CALGORITHMS_GRAPH_H
