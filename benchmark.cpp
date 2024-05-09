#include "benchmark.h"

#if OS_WINDOWS

#include <windows.h>

static f64 os_get_current_time(void) {
    LARGE_INTEGER time_large, frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time_large);
    
    return (f64)time_large.QuadPart / (f64)frequency.QuadPart;
}

#else

#include <sys/time.h>
#include <sys/resource.h>

static f64 os_get_current_time(void) {
    struct timeval time_val;
    struct timezone tzp;
    gettimeofday(&time_val, &tzp);
    
    return time_val.tv_sec + time_val.tv_usec * 1e-6;
}

#endif


#include <stdio.h>

BenchmarkTimer::BenchmarkTimer(char *_name) {
    name = _name;
    time = os_get_current_time();
}

BenchmarkTimer::~BenchmarkTimer(void) {
    time = os_get_current_time() - time;
    printf("%s time: %.3fs\n", name, time);
}