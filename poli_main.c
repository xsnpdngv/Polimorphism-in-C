#include "developer.h"
#include "senior_developer.h"

#include <stdio.h>

int main()
{
    developer_t *developer = developerCreate();
    developerWriteCode(developer, "hello world");
    developerDestroy(developer);
    fprintf(stderr, "\n");

    seniorDeveloper_t *seniorDeveloper = seniorDeveloperCreate();
    developerWriteCode(seniorDeveloper, "hello world");
    developerDestroy(seniorDeveloper);
    fprintf(stderr, "\n");

    developer_t *anyDeveloper = (developer_t *)seniorDeveloperCreate();
    developerWriteCode(anyDeveloper, "hello world");
    developerDestroy(anyDeveloper);
    fprintf(stderr, "\n");
}
