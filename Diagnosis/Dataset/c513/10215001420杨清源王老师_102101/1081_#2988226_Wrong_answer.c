#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mul(int *ans,int a)
{
    int tmp=0,carry=0;
    for(int i=0; i<100; i++)
    {
        tmp=ans[i]*a+carry;
        ans[i]=tmp%10;
        carry=tmp/10;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0; z<T; z++)
    {
        int a,n,j=99;
        scanf("%d%d",&a,&n);
        int ans[100]= {a},tmp=0,cal=1;
        for(int i=1; i<100; i++)
            ans[i]=0;
        if(n==0)
            ans[0]=0;
        else
        {
            for(int i=1; i<n; i++)
                mul(ans,a);
        }
        printf("case #%d:\n",z);
        while(ans[j]==0)
            j--;
        for(int i=j; i>0; i--)
            printf("%d",ans[i]);
        printf("%d\n",ans[0]);
    }
}
