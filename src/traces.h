#ifndef TRACES_H
#define TRACES_H

#include <stdio.h>

#ifdef  DEBUG
#   define TRACE_PREFIX        "%s +%d (%s) \t=> "
#   define TRACE_PREFIX_DATA   __FILE__, __LINE__, __FUNCTION__
#else
#   define TRACE_PREFIX        "(%s +%d) \t=> "
#   define TRACE_PREFIX_DATA   __FUNCTION__, __LINE__
#endif

#define TRACE_DBG_BASE(argModule, argFormat,...)                    \
    fprintf(    stdout,                                             \
                "DBG: %s \t :: " TRACE_PREFIX argFormat "\n",       \
                argModule, TRACE_PREFIX_DATA,                       \
                ##__VA_ARGS__ );                                    \
    fflush( stdout )

#define TRACE_ERR_BASE(argModule, argFormat,...)                    \
    fprintf(    stderr,                                             \
                "ERR: %s \t :: %s +%d (%s) \t=> " argFormat "\n",   \
                argModule, __FILE__, __LINE__, __FUNCTION__,        \
                ##__VA_ARGS__ );                                    \
    fflush( stderr )

#endif  /*< TRACES_H */
