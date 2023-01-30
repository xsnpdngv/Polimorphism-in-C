// developer.c
#include "developer.h"
#include "developer_private.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// public:

developer_t *developerCreate(/* args */)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    developer_t *developer = malloc(sizeof(developer_t));
    developerBuild(developer/* args */);
    return developer;
}


void developerDestroy(void *developer)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    ((developer_t *)developer)->vptr->destroy(developer);
}


void developerWriteCode(void *developer, const char *specification)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    ((developer_t *)developer)->vptr->writeCode(developer, specification);
}


// protected:

void developerBuild(void *developer/* args */)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    memset(developer, 0, sizeof(developer_t));
    ((developer_t *)developer)->vptr = developerFuncs();
}


static __typeof__(*developerFuncs()->destroy) developerDestroyBase;
static __typeof__(*developerFuncs()->writeCode) developerWriteCodeBase;

const developerFuncs_t *developerFuncs(void)
{
    static developerFuncs_t funcs =
    {
        .destroy = developerDestroyBase,
        .writeCode = developerWriteCodeBase,
        .isInitialized = 1
    };

    return &funcs;
}


// private:

static void developerDestroyBase(void *developer)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    free(developer);
}


static void developerWriteCodeBase(void *developer, const char *specification)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    (void)developer;
    (void)specification;
    printf("printf(\"Hello World!\\n\"); /* Base */\n");
}
