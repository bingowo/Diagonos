#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void*b)
{
    int s1=*(int*)a,s2=*(int*)b;
    if(s1<s2) return -1;
    else return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    int s[t];
    for(int i=0;i<t;i++) scanf("%d",&s[i]);
    long long int temp=s[0];
    for(int i=1;i<t;i++)
    {
        temp=temp^s[i];
    }
    if(temp!=0)
    {
        printf("-1");
    }
    else
    {
        qsort(s,t,sizeof(int),cmp);
        long long unsigned all=0;
        for(int i=1;i<t;i++)
        {
            all+=s[i];
        }
        printf("%llu",all);
    }
    return 0;
}