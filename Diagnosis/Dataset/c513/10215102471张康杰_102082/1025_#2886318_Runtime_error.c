#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Count(char*s)
{
    int table[256],number = 0;
    memset(table,-1,sizeof(int)*256);
    int len = strlen(s),i;
    for(i = 0;i < len;i++)
    {
        if(table[s[i]] == -1)
        {
            number++;
            table[s[i]] = 1;
        }
    }
    return number;
}
int cmp(const void*a,const void*b)
{
    char*pt1,*pt2;
    pt1 = *(char**)a,pt2 = *(char**)b;
    if(Count(pt1) != Count(pt2))
        return Count(pt2) - Count(pt1);
    else
        return strcmp(pt1,pt2);

}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n,j;
        scanf("%d",&n);
        char input[n][21];
        for(j = 0;j < n;j++)
        {
            scanf("%s",input[j]);
        }
        qsort(input,n,sizeof(char*),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < n;j++)
            printf("%s\n",input[j]);

    }

    return 0;
}