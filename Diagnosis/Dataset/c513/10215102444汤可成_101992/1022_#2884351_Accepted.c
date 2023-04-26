#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void* b)
{
    char* pa = *(char**)a;
    char* pb = *(char**)b;
    char* y1 = NULL;
    char* y2 = NULL;
    int i = 0;
    while(*(pa+i) != '@')
    {
        i++;
    }
    y1 = pa+i+1;
    i = 0;
    while(*(pb+i) != '@')
    {
        i++;
    }
    y2 = pb+i+1;
    if(strcmp(y1, y2) == 0 ) return strcmp(pb, pa);
    else return strcmp(y1, y2);
}

int main()
{
    int n = 0;
    char** email = NULL;
    scanf("%d", &n);
    email = (char**)malloc(n*sizeof(char*));
    int i = 0;
    char s[1000001] = {0};
    char* p = NULL;
    for(i = 0; i<n; i++)
    {
        scanf("%s", s);
        int len = strlen(s);
        p = (char*)malloc((len+1)*sizeof(char));
        strcpy(p, s);
        *(email + i) = p;
    }
    qsort(email, n, sizeof(char*), cmp);
    for(i = 0; i<n; i++)
    {
        printf("%s\n", *(email+i));
    }
    for(i = 0; i<n; i++)
    {
        p = email[i];
        free(p);
    }
    free(email);
    return 0;
}
