#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    long long int m;
    scanf("%lld",&m);
    for(int i=0;i<m;i++)
    {
        long long int a,b,n;
        scanf("%lld%lld%lld",&a,&b,&n);
        long long int s[n+1];
        for(int k=0;k<n;k++)
            s[k]=0;
        s[0]=1;
        int l=1,w=0;
        for(int k=0;k<b;k++)
        {
            long long int jin=0;
            for(int p=0;p<n;p++)
            {
                long long int c=s[p];
                s[p]=(s[p]*a+jin)%10;
                jin=(c*a+jin)/10;
            }
        }
        printf("case #%d:\n",i);
        for(int d=n-1;d>=0;d--)
        printf("%lld",s[d]);


    }
    return 0;
}

