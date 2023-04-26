#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n;
        scanf("%d",&n);
        long long int result;
        if(n==1)
        {
            result=1;
        }
        else if(n==2)
        {
            result=2;
        }
        else if(n==3)
        {
            result=4;
        }
        else if(n==4)
        {
            result=8;
        }
        else
        {
        	long long int a1=1,a2=2,a3=4,a4=8;
            for(int j=0;j<n-4;j++)
            {
                result=a1+a2+a3+a4;
                a1=a2;
                a2=a3;
                a3=a4;
                a4=result;
            }
        }
        printf("case #%d:\n",i);
        printf("%lld\n",result);

    }
    return 0;
}