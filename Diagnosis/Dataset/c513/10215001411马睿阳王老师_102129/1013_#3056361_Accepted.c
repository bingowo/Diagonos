#include<stdio.h>
#include<string.h>

long long int G(long long int m,long long int n)
{
    if(m%n==0) return n;
    else if(n%m==0) return m;
    else if(m>n)
    {
        m=m-n;
        return G(m,n);
    }
    else if(m<=n)
    {
        n=n-m;
        return G(m,n);
    }
}
int main()
{
    long long int A=0,B=0,C=1,D=0;
    int i=0,j=0,l=0,t=0;
    char a[1000];
    scanf("%s",a);
    l=strlen(a);
    for(i=0;i<l&&a[i]!='.';i++)
   {
        if(a[i]=='2') A=A*3-1;
        else if(a[i]=='1'||a[i]=='0') A=A*3+a[i]-'0';
   }
   //分数的计算
   for(i+=1;i<l;i++)
   {
       if(a[i]=='2')
       {
           B=B*3-1;
           C=C*3;
       }
       else if(a[i]=='1'||a[i]=='0')
       {
           B=B*3+a[i]-'0';
           C=C*3;
       }
   }
   if(B<0) D=-B;
   else D=B;
   t=G(D,C);
   B/=t;
   C/=t;
   if(B==0) printf("%lld",A);
   else
   {
       if(A==0) printf("%lld %lld",B,C);
       else if(A<0&&B>0)
       {
           A++;
           B=C-B;
           printf("%lld %lld %lld",A,B,C);
       }
       else if(A>0&&B<0)
       {
           A--;
           B=C+B;
           printf("%lld %lld %lld",A,B,C);
       }
       else printf("%lld %lld %lld",A,B,C);
   }
   return 0;
}
