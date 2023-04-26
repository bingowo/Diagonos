#include <stdio.h>
#include <stdlib.h>
#define N 32
int dec(int n)
{
    int s[N]={0},sum,comp,k=0;
    do{
        s[k++]=n%2;//k位数组
        n=n/2;
    }while(n);
    /*for(int i=0;i<k;i++)
            printf("%d ",s[i]);
    printf("\n");*/
    sum=1;
    comp=sum;
    for(int i=1;i<k;i++)
    {
        if(s[i]!=s[i-1])
            sum++;
        else
        {
            if(s[i]==0)
            {
                sum=0;continue;
            }
            else
                sum=1;
        }
        if(comp<sum) comp=sum;
    }
    return comp;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%d\n",dec(n));
    }
    return 0;
}
