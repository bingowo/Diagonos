#include <stdio.h>
#include <stdlib.h>
void time(int res[],int num)
{
    for(int i=0;i<1001;i++)
        res[i]=res[i]*num;
    for(int i=1000;i>0;i++)
    {
        while(res[i]>=10)
        {
            res[i]=res[i]-10;
            res[i-1]=res[i-1]+1;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int k=0;k<T;k++)
    {
        printf("case #%d:",k);
        int a,n;
        int num=a;
        scanf("%d %d",&a,&n);
        int res[1001];
        int i=1000;
        while(a!=0)
        {
            res[i]=a%10;
            i=i-1;
            a=a/10;
        }
        for(int j=0;j<n;j++)
            time(res,num);
        i=0;
        while(res[i]==0)
            i++;
        for(int v=i;v<1001;v++)
            printf("%d",res[v]);
        printf("%c",10);

    }
    return 0;
}
