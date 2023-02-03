// developer.c
#include "developer.h"
#include "developer_private.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// public:

developer_t *developer_Create(/* args */)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    developer_t *developer = malloc(sizeof(developer_t));
    developer_Build(developer/* args */);
    return developer;
}


void developer_Destroy(void *developer)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    ((developer_t *)developer)->vptr->destroy(developer);
}


void developer_WriteCode(void *developer, const char *specification)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    ((developer_t *)developer)->vptr->writeCode(developer, specification);
}


// protected:

void developer_Build(void *developer/* args */)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    memset(developer, 0, sizeof(developer_t));
    ((developer_t *)developer)->vptr = developer_Funcs();
}


static __typeof__(*developer_Funcs()->writeCode) developer_WriteCodeBase;
static __typeof__(*developer_Funcs()->destroy) developer_DestroyBase;

const developerFuncs_t *developer_Funcs(void)
{
    static developerFuncs_t funcs =
    {
        .writeCode = developer_WriteCodeBase,
        .destroy = developer_DestroyBase,
        .isInitialized = 1
    };

    return &funcs;
}


// private:

static void developer_WriteCodeBase(void *developer, const char *specification)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    (void)developer;
    (void)specification;
    printf("Developer version of Hello World! (Base implementation)\n");
}

static void developer_DestroyBase(void *developer)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    free(developer);
}
