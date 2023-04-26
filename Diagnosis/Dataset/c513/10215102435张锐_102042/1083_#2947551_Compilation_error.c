#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        long long unsigned temp=f(n);
        int num=0;
        for(int j=1;j<=n;j++)
        {
            int temp=j;
            while(temp%5==0) {num++;temp=temp/5;}
        }
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}