#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    unsigned char c;
    c=getchar();
    int gcd(int m,int n);
    for(int i=0;i<n;i++)
    {
        int m=0,cnt=0;
        while((c=getchar())!='\n')
        {
            int wor=c;
            m++;
            for(int j=0;wor!=0;j++)
            {
                cnt+=(wor&1);
                wor=wor>>1;
            }
        }
        m*=8;
        printf("%d/%d\n",cnt/gcd(cnt,m),m/gcd(cnt,m));
    }
    return 0;
}
int gcd(int m,int n)
{
    int r;
    while(n)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}