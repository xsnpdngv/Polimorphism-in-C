// senior_developer.c
#include "senior_developer.h"
#include "developer_private.h"

#include <stdlib.h>
#include <stdio.h>


static const developerVtbl_t *seniorDeveloper_Vptr(void);

// public:

seniorDeveloper_t *seniorDeveloper_Create(/* args */)
{
    fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
    seniorDeveloper_t *seniorDeveloper = malloc(sizeof(seniorDeveloper_t));
    developer_Build(seniorDeveloper/* args */); // inherit
    ((developer_t *)seniorDeveloper)->vptr = seniorDeveloper_Vptr(); // reach the virtual table
    // ...

    return seniorDeveloper;
}


// private:

// declarations of the actual implementations of the virtual methods
static __typeof__(*developer_Vptr()->writeCode) seniorDeveloper_WriteCode;
static __typeof__(*developer_Vptr()->destroy) seniorDeveloper_Destroy;

static const developerVtbl_t *seniorDeveloper_Vptr(void)
{
    static developerVtbl_t vtbl = {};
    if( ! vtbl.isInitialized)
    {
        // inherit
        vtbl = *developer_Vptr();

        // override
        vtbl.writeCode = seniorDeveloper_WriteCode;
        vtbl.destroy = seniorDeveloper_Destroy;
    }

    return &vtbl;
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
