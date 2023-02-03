// senior_developer.c
#include "senior_developer.h"
#include "developer_private.h"

#include <stdlib.h>
#include <stdio.h>


static const developerFuncs_t *seniorDeveloper_Funcs(void);

// public:

seniorDeveloper_t *seniorDeveloper_Create(/* args */)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    seniorDeveloper_t *seniorDeveloper = malloc(sizeof(seniorDeveloper_t));
    developer_Build(seniorDeveloper/* args */); // inherit
    ((developer_t *)seniorDeveloper)->vptr = seniorDeveloper_Funcs();
    // ...

    return seniorDeveloper;
}


// private:

static __typeof__(*developer_Funcs()->writeCode) seniorDeveloper_WriteCode;
static __typeof__(*developer_Funcs()->destroy) seniorDeveloper_Destroy;

static const developerFuncs_t *seniorDeveloper_Funcs(void)
{
    static developerFuncs_t funcs = {};
    if( ! funcs.isInitialized)
    {   // inherit
        funcs = *developer_Funcs();
        // override
        funcs.writeCode = seniorDeveloper_WriteCode;
        funcs.destroy = seniorDeveloper_Destroy;
    }

    return &funcs;
}

// virtual method overrides

static void seniorDeveloper_WriteCode(void *developer, const char *specification)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    (void)developer;
    (void)specification;
    fprintf(stdout, "Senior Developer version of Hello World! (Descendant implementation)\n");
}

static void seniorDeveloper_Destroy(void *developer)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    free(developer);
}
