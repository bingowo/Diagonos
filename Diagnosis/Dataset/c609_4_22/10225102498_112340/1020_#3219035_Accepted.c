#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a, const void* b)
{
    char *m = (char*)a, *n = (char*)b;
    int lem = strlen(m), len = strlen(n);
    int i,j;
    int flatm = 1, flatn = 1;
    int t = 0;
    int sum = 0, sun = 0;
    for(i=0; i<lem; i++)
    {
        if(m[i]>='0' && m[i]<='9')
        {
            flatm = 0;
            sum = sum*10 + m[i] - '0';
        }
    }
    for(j=0; j<len; j++)
    {
        if(n[j]>='0' && n[j]<='9')
        {
            flatn = 0;
            sun = sun*10 + n[j] - '0';
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
            if(sum > sun)
                return 1;
            if(sum < sun)
                return -1;
            if(sum == sun)
                return strcmp(m,n);
        }
    }
}

int main()
{
    char num[105][35];
    //num = (char**)malloc(sizeof(char*)*105);

    int i = 0, j = 0;
    for(j=0; j<105; j++)
    {
        //num[j] = (char*)malloc(sizeof(char)*35);
        memset(num[j], 0, sizeof(char)*35);
    }
    while(scanf("%s", num[i]) != EOF)
        i++;

    qsort(num,i,sizeof(num[0]),cmp);
    for(j=0; j<i; j++)
        printf("%s ", num[j]);

    return 0;
}
