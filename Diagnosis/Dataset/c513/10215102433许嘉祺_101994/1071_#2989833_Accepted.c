#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++)
    {
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        a=a%10007;
        b=b%10007;
        if (k==0)
            printf("1");
        else
        {
            int a1=1,b1=1;

            for (int j=1; j<=n; j++)
                a1=a1*a%10007;
            for(int j=1; j<=m; j++)
                b1=b1*b%10007;
            int num,start;
            if (n>m) n=m;
            if (n!=0)
            {
                int c1=1,d1=1;
                for(int j=1;j<=n;j++){
                    c1=c1*j%10007;
                    d1=d1*(k-j+1)%10007;
                }
                int f=1;
                for (;f<=10007;f++ )
                    if (f*c1%10007==d1) break;

                printf("%d\n",((a1*b1)%10007)*f%10007);
            }
            else printf("%d\n",(a1*b1)%10007);

        }

    }

    return 0;
}