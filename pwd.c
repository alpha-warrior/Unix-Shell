#include "headers.h"

void pwd()
{
    char add_curd[10000];

    getcwd(add_curd,10000);
    printf("%s\n",add_curd);
}
