// senior_developer.h - implements/extends developer
#include "developer.h"

typedef struct
{
    developer_t base;
    int seniorDeveloperAttr;

} seniorDeveloper_t;

seniorDeveloper_t *seniorDeveloperCreate(/* args */);
// developerXxx() functions are applicable
