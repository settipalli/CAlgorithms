#ifndef CALGORITHMS_GRAPHCC_H
#define CALGORITHMS_GRAPHCC_H

template<typename Graph>
class CC {
private:
    // implementation dependent code.
public:
    CC(const Graph &);

    int count(); // returns the number of connected components

    bool connect(int, int);
};

#endif //CALGORITHMS_GRAPHCC_H
