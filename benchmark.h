#pragma once
/*

Benchmark timer C++ utility for measuring execution time of your code.
Depends on base layer(common.h): https://github.com/mohamed6000/base_layer

*/

#include "common.h"

struct BenchmarkTimer {
    char *name;
    f64 time;

    BenchmarkTimer(char *_name);
    ~BenchmarkTimer(void);
};

#ifndef BENCHMARK_STR_JOIN1
#define BENCHMARK_STR_JOIN1(a, b) a##b
#endif

#ifndef BENCHMARK_STR_JOIN
#define BENCHMARK_STR_JOIN(a, b) BENCHMARK_STR_JOIN1(a, b)
#endif

#ifndef BENCHMARK_SCOPE
#define BENCHMARK_SCOPE(name) BenchmarkTimer BENCHMARK_STR_JOIN(timer, __LINE__)(name)
#endif

#ifndef BENCHMARK_FUNCTION
#define BENCHMARK_FUNCTION() BenchmarkTimer BENCHMARK_STR_JOIN(timer, __LINE__)((char *)__FUNCTION__)
#endif

// @note: should be used with BENCHMARK_END
#ifndef BENCHMARK_BEGIN
#define BENCHMARK_BEGIN(name) { BenchmarkTimer BENCHMARK_STR_JOIN(timer, __LINE__)(name)
#endif

// @note: used after BENCHMARK_BEGIN
#ifndef BENCHMARK_END
#define BENCHMARK_END() }
#endif
