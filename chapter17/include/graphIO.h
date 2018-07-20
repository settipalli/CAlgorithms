#ifndef CALGORITHMS_GRAPHIO_H
#define CALGORITHMS_GRAPHIO_H

// Graph processing input output interface.

template<typename Graph>
class IO {
public:
    static void shows(const Graph &);
    static void scanEZ(Graph &);
    static void scan(Graph &);
};

#endif //CALGORITHMS_GRAPHIO_H
