// senior_developer.h - implements/extends developer
#include "developer.h"

typedef struct
{
    developer_t base;
    int seniorDeveloperAttr;

} seniorDeveloper_t;

seniorDeveloper_t *seniorDeveloper_Create(/* args */);
void developer_Destroy(void *developer) /* override */;
void developer_WriteCode(void *developer, const char *specification) /* override */;
