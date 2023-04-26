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
        int sign=0;
        for(int i=0;i<9;i++)
        {
            if(a[i]<0)
            {
                sign=1;
                if(i==8)printf("%d",a[i]);
                else if(i==7)
                {
                    if(a[i]==-1)printf("-x");
                    else printf("%dx",a[i]);
                }
                else
                {
                    if(a[i]==-1)printf("-x^%d",8-i);
                    else printf("%dx^%d",a[i],8-i);
                }flag=1;
            }
            if(a[i]>0)
            {
                if(sign==0)
                {
                    if(i==8)printf("%d",a[i]);
                    else if(i==7)
                    {
                        if(a[i]==1)printf("x");
                        else printf("%dx",a[i]);
                    }
                    else
                    {
                        if(a[i]==1)printf("x^%d",8-i);
                        else printf("%dx^%d",a[i],8-i);
                    }
                    sign=1;
                }
                else{
                if(i==8)printf("+%d",a[i]);
                if(i==7)
                {
                    if(a[i]==1)printf("+x");
                    else printf("+%dx",a[i]);
                }
                else
                {
                    if(a[i]==1)printf("+x^%d",8-i);
                    else printf("+%dx^%d",a[i],8-i);
                }}flag=1;
            }
        }
        if(flag==0)printf("0");
        printf("\n");
    }
}
