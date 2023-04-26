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
    scanf("%c",mode);
    int s[N];
    int i=0;
    while(scanf("%d",&s[i]))
    i++;
    if(mode=='A')
    qsort(s,i,sizeof(int),cmp1)
    if(mode=='D')
    qsort(s,i,sizeof(int),cmp2)
    for(int j=0;j<i;j++)
    printf("%d",s[j]);
    return 0;
}