#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ char s[1100];
long long int l,i,j,n,m,s,t;
scanf("%s",s);
l=strlen(s);
if(l==1) printf("1");
else
{ n=1;
for(i=0;i<l;i++)
 {if(i==0)
  { if(s[i]!=s[i+1]) {n*=2;n%=1000000007;}
  }
  else if (i==l-1)
  { if(s[i]!=s[i-1]) {n*=2;n%=1000000007;}
  }
  else
  { if(s[i]==s[i-1]&&s[i]!=s[i+1]) {n*=2;n%=1000000007;}
    else if(s[i]==s[i+1]&&s[i]!=s[i-1]) {n*=2;n%=1000000007;}
    else if(s[i-1]==s[i+1]&&s[i]!=s[i+1]) {n*=2;n%=1000000007;}
    else if(s[i-1]!=s[i]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]) {n*=2;n%=1000000007;}
  }
 }
 printf("%lld",n);
 
}
}