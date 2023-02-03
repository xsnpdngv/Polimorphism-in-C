// developer.h
#ifndef DEVELOPER_H_
#define DEVELOPER_H_

typedef struct developerFuncs developerFuncs_t;

typedef struct developer
{
    const developerFuncs_t *vptr;
    int developerAttr;

} developer_t;

developer_t *developer_Create(/* args */);
void developer_Destroy(void *developer);
void developer_WriteCode(void *developer, const char *specification);

#endif // DEVELOPER_H_
