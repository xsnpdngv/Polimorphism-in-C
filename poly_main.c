#include "developer.h"
#include "senior_developer.h"

#include <stdio.h>

int main()
{
    developer_t *developer = developerCreate();
    developerWriteCode(developer, "hello world");
    // developer->developerAttr
    developerDestroy(developer);

    fprintf(stderr, "----------------------\n");

    seniorDeveloper_t *seniorDeveloper = seniorDeveloperCreate();
    developerWriteCode(seniorDeveloper, "hello world");
    // ((developer_t *)seniorDeveloper)->developerAttr
    // seniorDeveloper->base.developerAttr
    // seniorDeveloper->seniorDeveloperAttr
    developerDestroy(seniorDeveloper);

    fprintf(stderr, "----------------------\n");

    developer_t *anyDeveloper = (developer_t *)seniorDeveloperCreate();
    developerWriteCode(anyDeveloper, "hello world");
    // developer->developerAttr
    developerDestroy(anyDeveloper);
    fprintf(stderr, "\n");
}
