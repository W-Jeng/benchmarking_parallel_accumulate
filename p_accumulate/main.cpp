#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <execution>
#include "custom_accumulator.h"
#include <boost/math/special_functions.hpp>

int main() {
    
    std::vector<long> vec;
    long num_values = 100000;

    for (long i = 0; i < num_values; ++i) {
        vec.push_back(i);
    }

    long ans = CustomAccumulator::parallel(vec.begin(),vec.end());
    std::cout << "Single threaded Ans: " << std::accumulate(vec.begin(),vec.end(),0) << std::endl;;
    std::cout << "Parallel Ans: " << ans << std::endl;
    


    return 0;

}