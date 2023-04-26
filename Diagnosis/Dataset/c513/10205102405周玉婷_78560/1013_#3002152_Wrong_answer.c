#include <stdio.h>
typedef long long lli;
int GCD(int a, int b)
{
    if(a%b==0) return b ;
    else return GCD(b,a%b);
}

int main()
{
    char s[200];
    scanf("%s",s);
    lli p=0;int i;
    for( i=0; s[i]!='.'&&s[i]!=0; i++)
    {
        int temp=s[i]-'0';
        if(temp==0) p=p*3+0 ;
        else if (temp==1) p=p*3+1; 
        else p=p*3-1; 
    }
    lli f1=0,f2=1;//分子，分母
    if(s[i]==0) printf("%lld",p);//无小数
    else
    {
     for(int j=i+1; s[j]; j++)
     {
      int temp=s[j]-'0';
      if(temp==0) f1=f1*3+0 ; 
      else if(temp==1) f1=f1*3+1;
      else f1=f1*3-1; 
      f2=f2*3;
     }
     
        int gcd=GCD(f1,f2);
        f1=f1/gcd;
        f2=f2/gcd;
        if(p==0) printf("%lld %lld",f1,f2);//有且只有小数
        if(p==1&&f1<0) printf("%lld %lld",f2+f1,f2);
        if(p<0&&f1<0) printf("%lld %lld %lld",p,-f1,f2);
        if(p>1&&f1<0) printf("%lld %lld %lld",p-1,f2+f1,f2);
        if(p==-1&&f1>0) printf(" %lld %lld",-(f2-f1),f2);
        if(p<-1&&f1>0)  printf("%lld %lld %lld",p+1,f2-f1,f2);
        if(p>0&&f1>0) printf("%lld %lld %lld",p,f1,f2);
    }
    return 0;
}