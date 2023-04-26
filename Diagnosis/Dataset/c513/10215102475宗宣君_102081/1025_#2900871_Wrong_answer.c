#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int number(char*a)
{
    int i = 1,m = 1,j;
    while(a[i]!='\0')
    {
        int n = 1;
        for(j = 0;j<i;j++)
        {if(a[j]==a[i]) {n = 0;break;}}
        if(n) m++;
        i++;
    }
    return m;
}
int cmp(const void*a,const void*b)
{
    char *s1,*s2;
    s1 = (char*)a;s2 = (char*)b;
    int res1,res2;
    res1 = number(s1);res2 = number(s2);
    if(res1<res2) return 1;
    else if(res1==res2) return strcmp(s1,s2);
    else return -1;

}
int main()
{
    int T,n,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        scanf("%d",&n);
        char s[n][21];
        for(j = 0;j<n;j++)
            scanf("%s",s[j]);
        qsort(s,n,21,cmp);
        for(j = 0;j<n;j++)
            printf("case #%d:\n%s\n",i,s[j]);
    }
    return 0;
}
