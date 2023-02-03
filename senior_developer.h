// senior_developer.h - implements/extends developer
#include "developer.h"

typedef struct
{
    developer_t base;
    int seniorDeveloperAttr;

} seniorDeveloper_t;

seniorDeveloper_t *seniorDeveloper_Create(/* args */);
// developer_Xxx() functions are applicable
