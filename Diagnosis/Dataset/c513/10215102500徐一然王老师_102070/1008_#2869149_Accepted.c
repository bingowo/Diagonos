#include<stdio.h>

int main()
{
    int count,a,b,num=0,max=20;
    int A[20];
    int B[20];
    int *p1=A;
    int *p2=B;
    scanf("%d",&count);
    while(count--)
    {
        for(int i=0;i<20;i++)A[i]=1;
        for(int j=0;j<20;j++)B[j]=1;
        scanf("%d %d",&a,&b);
        while(a)
        {
            if(a%2==1)
            {
                *p1=2;
            }
            else
            {
                *p1=1;
            }
            a=a/2;
            p1++;
        }
        p1=A;
        while(b)
        {
            if(b%2==1)
            {
                *p2=2;
            }
            else
            {
                *p2=1;
            }
            b=b/2;
            p2++;
        }
        p2=B;
        while(max--)
        {
            if (*p1!=*p2)
            {
                num++;
            }
            p1++;
            p2++;
        }
        printf("%d\n",num);
        p1=A;
        p2=B;
        num=0;
        max=20;
    }
}
