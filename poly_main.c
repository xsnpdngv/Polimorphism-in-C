#include "developer.h"
#include "senior_developer.h"

#include <stdio.h>

int main()
{
    developer_t *developer = developer_Create();
    developer_WriteCode(developer, "hello world");
    // developer->developerAttr
    developer_Destroy(developer);

    fprintf(stderr, "----------------------\n");

    seniorDeveloper_t *seniorDeveloper = seniorDeveloper_Create();
    developer_WriteCode(seniorDeveloper, "hello world");
    // ((developer_t *)seniorDeveloper)->developerAttr
    // seniorDeveloper->base.developerAttr
    // seniorDeveloper->seniorDeveloperAttr
    developer_Destroy(seniorDeveloper);

    fprintf(stderr, "----------------------\n");

    developer_t *anyDeveloper = (developer_t *)seniorDeveloper_Create();
    developer_WriteCode(anyDeveloper, "hello world");
    // developer->developerAttr
    developer_Destroy(anyDeveloper);
    fprintf(stderr, "\n");
}
