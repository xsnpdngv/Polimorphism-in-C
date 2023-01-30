// developer.h
#ifndef DEVELOPER_H_
#define DEVELOPER_H_

typedef struct developerFuncs developerFuncs_t;

typedef struct developer
{
    const developerFuncs_t *vptr;
    // attributes ...

} developer_t;

developer_t *developerCreate(/* args */);
void developerDestroy(void *developer);
void developerWriteCode(void *developer, const char *specification);

#endif // DEVELOPER_H_
