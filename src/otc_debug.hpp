#ifndef __OTC_DEBUG_HPP_INCLUDED__
#define __OTC_DEBUG_HPP_INCLUDED__

#define OTC_DEBUG_ON
#include <stdlib.h>
namespace otc
{
    void debug(const char* msg, ...);
    void dump_buffer(unsigned char *buffer, size_t length);
}

#endif
