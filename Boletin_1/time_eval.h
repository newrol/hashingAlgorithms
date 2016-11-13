#ifndef TIME_EVAL_H_INCLUDED
#define TIME_EVAL_H_INCLUDED


#include <time.h>
#include <sys/time.h>

///Get time diference between a and b in ms
double timeval_diff(struct timeval *a, struct timeval *b);

#endif // TIME_EVAL_H_INCLUDED
