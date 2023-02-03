// developer.h
#ifndef DEVELOPER_H_
#define DEVELOPER_H_

typedef struct developerVtbl developerVtbl_t;

typedef struct developer
{
    const developerVtbl_t *vptr; // pointer to 'virtual table' of member functions
    int developerAttr;

} developer_t;

developer_t *developer_Create(/* args */);
/* virtual */ void developer_Destroy(void *developer);
/* virtual */ void developer_WriteCode(void *developer, const char *specification);

#endif // DEVELOPER_H_
