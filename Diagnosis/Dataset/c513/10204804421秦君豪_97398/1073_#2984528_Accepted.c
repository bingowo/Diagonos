#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


typedef long long int lli;


lli left(lli a,lli b)

{
    int cout=0;
//    printf("%lld%lld",a,b);
    for(lli i=a;i<=b;i++)
    {
        if (i%9==0) cout++;
    }
    return cout;
}


lli f(lli n)
{
    lli ans=0;
    int a[19];
    int i=0;
    lli tmp;
//    printf("pass");
    while(n!=0)
    {
        a[i]=n%10;
        n/=10;
        i++;
    }
    for (int j=i-1;j>=0;j--)
    {
        ans=ans*9+a[j];
    }
    return ans;
}

int main(void)
{
    lli a,b;
//    char a[19],b[19];
//    memset(a,0,19);
//    memset(b,0,19);
//    int x[18]={0},y[18]={0};

    scanf("%lld %lld",&a,&b);

    lli a1=f(a);
    lli b1=f(b);

    lli count=b1-a1+1;


    lli countb = f(b-b%10)/9+left(b-b%10,b);
    lli counta = f(a-a%10)/9+left(a-a%10,a);
    printf("%lld",count-(countb -counta));



    return 0;

}
