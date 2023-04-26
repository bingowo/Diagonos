#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void* a,const void *b)
{
    char *x = (char *)a,*y = (char *)b;
    char *domain_1 = strchr(x,'@'), *domain_2 = strchr(y,'@');
    int m =strcmp(domain_1,domain_2);
    if(m == 0)//主机域名相同
    {
        int n = strcmp(x,y);
        if(n < 0)
            return 1;
        else if (n > 0)
            return -1;
        else
            return 0;
    }else
        return m;
}

int main()
{
    int n;
    scanf("%d",&n);
    char** p = (char **)malloc(n * sizeof(char *));
    for(int i=0;i<n;i++)
    {
        scanf("%s",(*p)+i);
    }
    qsort((*p),n,sizeof(*p),cmp1);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",(*p)+i);
    }
    return 0;
}