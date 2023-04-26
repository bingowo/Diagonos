#include<stdio.h>
#include<stdlib.h>
#define N 100
int cmp1(const void* e1,const void* e2)
{
    return (*(int*)e1)-(*(int*)e2);
}
int cmp2(const void* e1,const void* e2)
{
    return -(*(int*)e1)+(*(int*)e2);
}
int main()
{
    char mode;
    scanf("%c\n",&mode);
    int s[N];
    int i=0,n=0,t=0;
    while(scanf("%d",&s[i])!=EOF)
    i++;
    for(n=0;n<i;n++)
    {
        for(t=n+1;t<i;t++)
        {
            if(s[t]==s[n])
            {
                for(;t+1<i;t++)
                s[t]=s[t+1];
            }
        }
    }
    if(mode=='A')
    qsort(s,i,sizeof(int),cmp1);
    if(mode=='D')
    qsort(s,i,sizeof(int),cmp2);
    for(int j=0;j<i;j++)
    printf("%d ",s[j]);
    return 0;
}