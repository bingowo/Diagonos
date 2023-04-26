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
            if (n!=0){
            for (int j=k; j>=k-n+1; j--)
                if (j%n==0)
                {
                    start=j;
                    break;
                }
            num=1;
            int len=1;
            for (int j=start+1; j<=k; j++)
            {
                int l=j/len;
                num=(num*l)%10007;
                len++;
            }
            for(int j=k-n+1; j<=start; j++)
            {
                int l=j/len;
                num=(num*l)%10007;
                len++;

            }
            printf("%d\n",((a1*b1)%10007)*num%10007);}
            else printf("%d\n",(a1*b1)%10007);

        }

    }

    return 0;
}
