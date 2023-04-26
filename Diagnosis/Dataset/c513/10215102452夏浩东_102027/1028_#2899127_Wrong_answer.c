#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return *A-*B;
}
int cmp2(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return *B-*A;
}
int main()
{
    char c,h;
    int num=0,cnt=0;
    int L[100]={0},NL[100]={0};
    scanf("%c",&c);
    for(num=0;h!='\n';num++)
    {
        scanf("%d",&L[num]);
        h=getchar();
    }
    if(c=='A') qsort(L,num,sizeof(int),cmp1);
    else qsort(L,num,sizeof(int),cmp2);
    for(int i=1;i<num;i++)
    {
        if(L[i]!=L[i-1])
        {
            NL[cnt]=L[i-1];
            cnt++;
        }
    }
    if(L[num-1]!=L[num-2]) NL[cnt]=L[num-1];
    for(int i=0;i<cnt;i++) printf("%d ",NL[i]);
    printf("%d\n",NL[cnt]);
    return 0;
}