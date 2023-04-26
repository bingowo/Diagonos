#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int a[9],flag=0;
        for(int i=0;i<9;i++)scanf("%d",&a[i]);
        for(int i=0;i<9;i++)
        {
            if(a[i]!=0)
            {
                if(a[i]==1)printf("x^%d",8-i);
                else if(a[i]==-1)printf("-x^%d",8-i);
                else if(a[i]>0)printf("+%d^x%d",a[i],8-i);
                else printf("%d^x%d",a[i],8-i);
                flag=-1;
            }
        }
        if(flag==0)printf("0");
        printf("\n");
    }
}