// developer_private.h
#ifndef DEVELOPER_PRIVATE_H_
#define DEVELOPER_PRIVATE_H_

#include "developer.h"

struct developerVtbl
{
    void (*writeCode)(void *developer, const char *specification);
    void (*destroy)(void *developer);
    int isInitialized;
};

const developerVtbl_t *developer_Vptr(); // access to the virtual table
void developer_Build(void *developer/* args */);

#endif // DEVELOPER_PRIVATE_H_
