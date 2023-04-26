#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math,h>
int gcd(long long int a, long long int b)
{ return a?gcd(b%a,a):b;
    
}
int main()
{ long long int ans1,ans2,ans3=1,d;
unsigned int p=0; char s[30];
gets(s);
for(;p<strlen(s);p++)
{ if(s[p]=='.') break;
 ans1=ans1*3;
 if (s[p]=='1') ans1+=1;
 if (s[p]=='2') ans1-=1;
}
p++
for(;p<strlen(s);p++)
{ ans2=ans2*3;
 if (s[p]=='1') ans2+=1;
 if (s[p]=='2') ans2-=1;
 ans3=ans*3;   
}
  d=gcd(abs(ans3),abs(ans2));
  

if(ans2==0) printf("%lld",ans1);
if(ans2!=0)
{ printf("%lld %lld %lld",ans1,ans2/d,ans3/d);
    
}
}