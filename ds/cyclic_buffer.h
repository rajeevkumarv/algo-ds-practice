//
// Created by rajverm2 on 27/05/20.
//

#ifndef ALGO_PRACTICE_CYCLIC_BUFFER_H
#define ALGO_PRACTICE_CYCLIC_BUFFER_H

#include <vector>

class cyclic_buffer {
    std::vector<int> buffer;
    int start = -1;
    int end = -1;
    int N = 0;
public:
    cyclic_buffer(int size):buffer(size),N(size){}

    void add(int a);
    void pop_front();
    void pop_back();

    bool empty() { return start == -1 && end == start; }
    inline int next(int x){ return (x+1)%N; }
    inline int back(int x) { return x > 0 ? x-1 : N-1; }
    int size() { return end <= start ? end+N-start : end-start; }
    inline int front() { return buffer[start]; }
    inline int back() { return buffer[back(end)]; }
};


#endif //ALGO_PRACTICE_CYCLIC_BUFFER_H
