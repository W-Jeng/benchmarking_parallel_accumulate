#include "c_accumulate.h"
#include<iostream>
long C_Accumulate::parallel(int* begin, int* end) {
    long sum = 0;
    while(begin != end) {
        sum += *begin;
        begin++;
    }
    return sum;
}