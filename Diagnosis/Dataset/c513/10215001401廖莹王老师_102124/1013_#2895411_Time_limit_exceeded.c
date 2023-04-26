#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int GCD(int m,int n)
{
    if(n<=m && m%n==0)
        return n;
    else if(n>m)
        return GCD(n,m);
    else return GCD(n,m%n);
}
int main()
{
    char s[1000];
    int i,number=0,h=0,k,l=0,m=0,n=0;
    long long int a=0;
    scanf("%s",s);
    for(i=0;s[i]!='.' && s[i];i++)number++;
    k=number;

    for(i=0;s[i]!='.'&& s[i];i++)
    {
        if(s[i]=='1')a=a+1*pow(3,number-1);
        if(s[i]=='0')a=a+0*pow(3,number-1);
        if(s[i]=='2')a=a+(-1)*pow(3,number-1);
        number--;
    }

    if(s[i]=='.')
    {
         i++;
      for(h=0;s[i];i++)h++;
      n=pow(3,h);
    for(i=i-h;s[i];i++)
    {
        if(s[i]=='1')m=m+1*pow(3,h+k-i);
        if(s[i]=='0')m=m+0*pow(3,h+k-i);
        if(s[i]=='2')m=m+(-1)*pow(3,h+k-i);
    }
     l=GCD(abs(m),abs(n));
     m=m/l;n=n/l;
     if(a>0){if(m>0)printf("%lld %d %d",a,m,n);
     if(m<0)printf("%lld %d %d",a-1,n+m,n);}
     if(a==0)printf("%d %d",m,n);
     if(a<0){if(m<0)printf("%lld %d %d",a,-m,n);
     if(m>0)printf("%lld %d %d",a+1,n-m,n);}
    }
    else printf("%lld",a);

    return 0;
}
