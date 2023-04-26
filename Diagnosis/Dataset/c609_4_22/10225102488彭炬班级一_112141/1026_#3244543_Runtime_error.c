#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char *p)
{
    int a[26];
    for(int i = 0;i < 27;i++)
        a[i] = 0;
    int i = 0,count = 0;
    while(*(p+i) >= 'A')
    {
        if(a[*(p+i) - 'A'] == 0)
        {
            a[*(p+i) - 'A'] = 1;
            count++;
        }
        i++;
    }
    return count;
}

int cmp(const void *a,const void *b)
{
    char *p1 = *(char (*)[21])a;
    char *p2 = *(char (*)[21])b;
    if(len(p1)==len(p2))
        return strcmp(p1,p2);
    else
        return len(p2) - len(p1);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j = 0;j < T;j++)
    {
        int n;
        scanf("%d",&n);
        int row = n;
        char s[row][21];
        while(n--)
            scanf("%s",s[n]);
        qsort(s,row,sizeof(s[0]),cmp);
        printf("case #%d:\n",j);
        for(int i = 0;i < row;i++)
            printf("%s\n",s[i]);
    }
    return 0;
}
