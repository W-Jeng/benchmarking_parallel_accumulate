#include "custom_accumulator.h"
#include<iostream>
#include<numeric>
#include<vector>
#include<thread>

long long accumulation_wrapper(std::vector<long>::iterator begin, std::vector<long>::iterator end, long long& ref_val);

long long CustomAccumulator::parallel(std::vector<long>::iterator begin,std::vector<long>::iterator end) {
    if (end-begin < 1000) {
        return std::accumulate(begin, end, 0);
    }
    const long MAX_THREADS = 7;
    std::vector<long long> accumulation_values(MAX_THREADS, (long) 0);

    int total_size = std::distance(begin, end);
    int average_accumulation_per_thread = total_size/MAX_THREADS;
    std::cout << "average accumulation: " << average_accumulation_per_thread << "\n";
    std::vector<std::thread> thread_containers;

    for (int i = 0; i < MAX_THREADS; ++i) {
        std::vector<long>::iterator thread_specific_begin = begin+i*average_accumulation_per_thread;
        std::vector<long>::iterator thread_specific_end = (i != MAX_THREADS-1) ? begin+(i+1)*average_accumulation_per_thread : end;
        
        std::thread new_thread(accumulation_wrapper, thread_specific_begin, thread_specific_end, std::ref(accumulation_values[i]));
        thread_containers.push_back(std::move(new_thread));
        
    }
    
    for(auto& thread : thread_containers) {
        thread.join();
    }
    long long total_sum = std::accumulate(accumulation_values.begin(), accumulation_values.end(), 0ll);

    for (int i = 0; i < MAX_THREADS; ++i) {
        std::cout << "accumulation val: " << accumulation_values[i] << std::endl;
    }
   
    return total_sum;
}

long long accumulation_wrapper(std::vector<long>::iterator begin,std::vector<long>::iterator end, long long& ref_val) {
    ref_val = std::accumulate(begin, end, 0ll);
    return ref_val;
}