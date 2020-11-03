///
/// Created by Buğra Kadirhan.
///

#include <HGLog.hpp>
#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>

void HGLog (const char *filename, const char *func, int line, const char *fmt, ...) 
{
    va_list ap;
    time_t raw_time;
    struct tm *t;
    char buffer [128];

    va_start (ap, fmt);
    time (&raw_time);
    t = localtime (&raw_time);
    strftime (buffer, sizeof (buffer), "%c", t);
    fprintf (stderr, "[%s %s %s:%d] ", buffer, func, strrchr (filename,'/') + 1, line);
    vfprintf (stderr, fmt, ap);
    va_end (ap);
}

void HGExit (int status)
{
    exit (-1);
}