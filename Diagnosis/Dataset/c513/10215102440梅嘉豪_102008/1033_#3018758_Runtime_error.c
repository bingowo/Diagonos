#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
static char* month[] ={"pop","no","zip"};

int main()
{
    char *p=strdup("abcd");
    p[3]=0;
    //printf("%s",p);
    //free(p);
}
