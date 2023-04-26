#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 21

int cmp(const void*a,const void*b)
{
    return strcmp(*(char(*)[L])a,*(char(*)[L])b);
}

int main()
{
    int n;
    scanf("%d",&n);
    char DNA[n][L];
    for(int i = 0;i < n;i++)
        scanf("%s",DNA[i]);
    qsort(DNA,n,sizeof(DNA[0]),cmp);
    printf("%s\n",DNA[0]);
    for(int i = 1;i < n;i++)
    {
        if(strcmp(DNA[i],DNA[i-1]) == 0)
            continue;
        else
            printf("%s\n",DNA[i]);
    }
    return 0;
}
