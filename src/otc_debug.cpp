#include "otc_debug.hpp"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <string>

#include <pthread.h>

void otc::debug(const char* msg, ...) {
    #ifdef OTC_DEBUG_ON
    time_t rawtime;
    time(&rawtime);
    struct tm * timeinfo = localtime(&rawtime);

    char timeStr[50];
    strftime(timeStr, 50, "%c", timeinfo);
    fprintf(stderr, "otc_debug - %s - %lu: ", timeStr, (size_t)pthread_self());

    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    #endif
}

void otc::dump_buffer(unsigned char *buffer, size_t length) {
    #ifdef OTC_DEBUG_ON
    fprintf(stderr, "[");
    for(size_t i = 0; i < length; i++) {
        fprintf(stderr, "%d,", buffer[i]);
    }
    fprintf(stderr, "]\n");
    #endif
}
