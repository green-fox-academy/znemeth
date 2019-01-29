//
// Created by NEMETH on 2019.01.29..
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter();
    Counter(int f);

    int field;
    int temp;

    void add(int number);
    void add();
    int get();
    void reset();

};


#endif //COUNTER_COUNTER_H
