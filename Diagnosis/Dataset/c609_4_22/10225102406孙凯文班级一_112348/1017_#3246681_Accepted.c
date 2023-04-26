#include<stdio.h>
#include<stdlib.h>
int cmpA(const void *A,const void*B)
{
    int a=*(int *)A;
    int b=*(int *)B;
    return a-b;
}
int cmpB(const void *A,const void*B)
{
    int a=*(int *)A;
    int b=*(int *)B;
    return b-a;
}
int main()
{
    int a,b[1000],i=0;
    char c;
    scanf("%c",&c);
    while(scanf("%d",&a)!=EOF) b[i]=a,i++;
    if(c=='A') qsort(b,i,sizeof(b[0]),cmpA);
    if(c=='D') qsort(b,i,sizeof(b[0]),cmpB);
    printf("%d ",b[0]);
    for(int j=1;j<i;j++)
    {
        if(b[j]!=b[j-1]) printf("%d",b[j]);
        if(j!=i-1&&b[j]!=b[j-1]) printf(" ");
    }
    return 0;
}