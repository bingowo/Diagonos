#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        int n;
        scanf("%d",&n);
        int a=n/4;int num=0;
        for(int i=0;i<=a;i++)
        {
            int t1=n-i*4;
            if(t1==0) {num++;break;}
            int b=t1/3;
            for(int j=0;j<=b;j++)
            {
                int t2=t1-j*3;
                if(t2==0) {num++;break;}
                int c=t2/2;
                for(int k=0;k<=c;k++)
                {
                    int t3=t2-k*2;
                    if(t3==0) {num++;break;}
                    num++;
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
