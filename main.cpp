#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <execution>
#include "c_accumulate.h"
 

int main() {
    /*
    std:: vector<int> vec(10);
    std:: iota(std::begin(vec),std::end(vec),1);
    const auto result = std::reduce(std::execution::par,std::begin(vec),
                                    std::end(vec));
    std:: cout << result;
    */
    std::vector<int> vec = {1,2,3,4,5,6};

    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << "\n";
    }
    long ans = C_Accumulate::parallel(&vec[0], &vec[0] + vec.size());
    std::cout << "ans: " << ans << std::endl;
    return 0;
}