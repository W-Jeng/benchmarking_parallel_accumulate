#include "custom_accumulator.h"
#include<iostream>

long CustomAccumulator::parallel(std::vector<int>::iterator begin,std::vector<int>::iterator end) {
    long sum = 0;
    for(auto ele = begin; ele != end; ++ele) {
        std::cout << "ele: " << *ele << "\n";
    }
    return sum;
}