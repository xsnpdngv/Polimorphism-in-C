// senior_developer.c
#include "senior_developer.h"
#include "developer_private.h"

#include <stdlib.h>
#include <stdio.h>


static const developerFuncs_t *seniorDeveloperFuncs(void);

// public:

seniorDeveloper_t *seniorDeveloperCreate(/* args */)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    seniorDeveloper_t *seniorDeveloper = malloc(sizeof(seniorDeveloper_t));
    developerBuild(seniorDeveloper/* args */); // inherit
    ((developer_t *)seniorDeveloper)->vptr = seniorDeveloperFuncs();
    // ...

    return seniorDeveloper;
}


// private:

static __typeof__(*developerFuncs()->writeCode) seniorDeveloperWriteCode;
static __typeof__(*developerFuncs()->destroy) seniorDeveloperDestroy;

static const developerFuncs_t *seniorDeveloperFuncs(void)
{
    static developerFuncs_t funcs = {};
    if( ! funcs.isInitialized)
    {   // inherit
        funcs = *developerFuncs();
        // override
        funcs.writeCode = seniorDeveloperWriteCode;
        funcs.destroy = seniorDeveloperDestroy;
    }

    return &funcs;
}

// virtual method overrides

static void seniorDeveloperWriteCode(void *developer, const char *specification)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    (void)developer;
    (void)specification;
    fprintf(stdout, "Senior Developer version of Hello World! (Descendant implementation)\n");
}

static void seniorDeveloperDestroy(void *developer)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    free(developer);
}
