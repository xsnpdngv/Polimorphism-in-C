// developer_private.h
#ifndef DEVELOPER_PRIVATE_H_
#define DEVELOPER_PRIVATE_H_

#include "developer.h"

struct developerFuncs
{
    void (*writeCode)(void *developer, const char *specification);
    void (*destroy)(void *developer);
    int isInitialized;
};

const developerFuncs_t *developerFuncs();
void developerBuild(void *developer/* args */);

#endif // DEVELOPER_PRIVATE_H_
