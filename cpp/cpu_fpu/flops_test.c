#include <stdio.h>
#include <time.h>

#define N 10000000000 // 操作次数

int main() {
    double a = 1.5, b = 2.5, c = 0.0;
    struct timespec start, end;

    // 获取开始时间
    clock_gettime(CLOCK_MONOTONIC, &start);

    // 执行大量的乘加操作
    for (int i = 0; i < N; i++) {
        c += a * b; // 每次迭代执行一次乘法和一次加法
    }

    // 获取结束时间
    clock_gettime(CLOCK_MONOTONIC, &end);

    // 计算总时间（以秒为单位）
    double time_taken = end.tv_sec - start.tv_sec;
    time_taken += (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    // 打印结果
    printf("Result of computation: %f\n", c);
    printf("Time taken: %f seconds\n", time_taken);
    printf("TFLOPS: %f\n", (N / time_taken) / 1e12); // 转换为 TFLOPS
    printf("GFLOPS: %f\n", (N / time_taken) / 1e9);  // 转换为 GFLOPS

    return 0;
}


// #include <iostream>
// #include <chrono>

// int main() {
//     const long long num_operations = 1e9; // Number of floating-point operations
//     float a = 1.0, b = 2.0, c; // Sample floating-point variables

//     // Start the timer
//     auto start = std::chrono::high_resolution_clock::now();

//     // Perform floating-point operations
//     for (long long i = 0; i < num_operations; ++i) {
//         c = a * b; // Example operation: multiplication
//     }

//     // Stop the timer
//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<float> duration = end - start;

//     // Calculate GFLOPS
//     float gflops = (num_operations * 4) / duration.count() / 1e9; // 4 operations per iteration

//     std::cout << "Total time: " << duration.count() << " seconds" << std::endl;
//     std::cout << "Performance: " << gflops << " GFLOPS" << std::endl;

//     return 0;
// }


// gcc -O2 -o flops_test flops_test.c -lm
