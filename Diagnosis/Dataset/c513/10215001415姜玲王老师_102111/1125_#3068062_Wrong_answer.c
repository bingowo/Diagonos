#include <stdio.h>
#include <stdlib.h>
#include<string.h>
long long gcd(long long a,long long b)
{
    if(a%b) gcd(b,a%b);
    else return b;
}
long long POW(long long a,long long b)
{
    long long c=a,i;
    for(i=0;i<b;i++)
    {
        c*=a;
    }
    return c;
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
    printf("case #%d:\n",i);
    long long k1,k2,k3;
    long long p1,p2,temp,p3;
    char a[17];
    scanf("%s",a);
   long long s1=0,s2=0,s3=0,s4,s5;
   for(k1=0;a[k1]!='.';k1++)
   {
       s1=s1*10+a[k1]-'0';
   }
   for(k2=k1+1;a[k2]!='['&&k2<strlen(a);k2++)
   {
       s2=s2*10+a[k2]-'0';
   }
   for(k3=k2+1;a[k3]!=']'&&k3<strlen(a);k3++)
   {
       s3=s3*10+a[k3]-'0';
   }
   if(s2==0&&s3==0) printf("%lld\n",s1);
else{
    if(s3==0)

        {

            p2=POW(10,k2-k1-1);
            p1=s1*p2+s2;
            temp=gcd(p1,p2);
            p2/=temp;
            p1/=temp;
            printf("%lld/%lld\n",p1,p2);
        }
        else{
            p1=(POW(10,k3-k1-2)-POW(10,k2-k1-1));
            temp=gcd(p1,s3);
            p1/=temp;
            s3/=temp;
            p2=POW(10,k2-k1-1);
            s4=p2*s1+s2;
            temp=gcd(s4,p2);
            s4/=temp;
            p2/=temp;
            s5=s4*p1+s3*p2;
            p3=p1*p2;
            temp=gcd(p3,s5);
            s5/=temp;
            p3/=temp;
            printf("%lld/%lld\n",s5,p3);
        }
}

   }
}
