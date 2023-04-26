#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a, const void* b)
{
    char *m = *(char**)a, *n = *(char**)b;
    int lem = strlen(m), len = strlen(n);
    int i,j;
    int flatm = 1, flatn = 1;
    int t = 0;
    int ni[35];
    for(i=0; i<=lem; i++)
    {
        if(i == lem)
            break;
        if(m[i]>='0' && m[i]<='9')
        {
            flatm = 0;
            break;
        }
    }
    for(j=0; j<=len; j++)
    {
        if(j == len)
            break;
        if(n[j]>='0' && n[j]<='9')
        {
            flatn = 0;
            break;
        }
    }
    if(flatm*flatn == 1)
        return strcmp(m,n);
    else
    {
        if(flatn == 1)
            return 1;
        if(flatm == 1)
            return -1;
        if(flatm==0 && flatn==0)
        {
            
            
            
            
        }
        
        
        
    }
    
}

int main()
{
    char num[105][35];
    int i = 0, j = 0;
    while(scanf("%s", num[i]) != EOF)
        i++;
    qsort(num,i,sizeof(num[0]),cmp);
        

    return 0;
}
