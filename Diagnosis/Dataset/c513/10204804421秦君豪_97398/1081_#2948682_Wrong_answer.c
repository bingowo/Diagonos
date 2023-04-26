#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int mul(int *result,int a,int cnt)
{
    int i,carry=0;
    for(i=0;i<cnt;i++)
    {
        int t= result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
//        printf("pass");
    }
    while (carry>0)
    {
        result[i++]=carry%10;
        carry/=10;
    }
    return i;
}
int main(void)
{
    int T;
    int a,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int cnt=1;
        scanf("%d%d",&a,&n);
        int result[95]={1};


        for(int k=0;k<n;k++)
        {
            cnt=mul(result,a,cnt);
        }


        printf("%d",cnt);

        printf("case #%d:\n",i);

        for (int j=cnt-1;j>=0;j--)
        {
            printf("%d",result[j]);
        }
        printf("\n");
    }
    return 0;
}
