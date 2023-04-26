#include <stdio.h>
#include <stdlib.h>
#include<string.h>
long long int gcd(long long int x,long long int y)
{
    if(x%y==0)return y;
    else return(gcd(y,x%y));
}
int main()
{
    int i;
    long long int sum1 = 0,sum2 = 0,mom = 0;char a[31];
    scanf("%s",a);
    for(i = 0;a[i]!='\0'&&a[i]!='.';i++)
    {
        if(a[i]=='2')sum1 = sum1*3-1;
        else if(a[i]=='0')sum1 = sum1*3;
        else if(a[i]=='1')sum1 = sum1*3+1;
    }
    if(a[i]=='.')
    {
        i++;
        for(mom = 1;a[i]!='\0';i++)
    {
        mom*=3;
       if(a[i]=='2')sum2 = sum2*3-1;
        else if(a[i]=='0')sum2 = sum2*3;
        else if(a[i]=='1')sum2 = sum2*3+1;
    }
    }
    if(sum1>0&&sum2<0)sum2 = mom+sum2,sum1--;
    else if(sum1<0&&sum2>0)sum2 = mom-sum2,sum1++;

    if(sum2==0)printf("%ld",sum1);
    else if(sum1==0&&sum2<0)printf("%ld %ld",sum2/gcd(mom,-sum2),mom/gcd(mom,-sum2));
    else if(sum1 ==0&&sum2>0)printf("%ld %ld",sum2/gcd(mom,sum2),mom/gcd(mom,sum2));
    else if(sum1!=0&&sum2!=0)printf("%ld %ld %ld",sum1,sum2/gcd(mom,sum2),mom/gcd(mom,sum2));

}
