#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{char s[1200];
long long int i,j,k,n,m;
scanf("%s\n",s);
n=strlen(s);
j=1;
for(i=0;i<n;i++)
{ if (n==1) break;
    if(i==0)
{ if(s[i]!=s[i+1]) j*=2;
}
else if(i==n-1)
{if (s[i]!=s[i-1]) j*=2;}
else 
{ if (s[i]!=s[i-1]&&s[i]!=s[i+1]) j*=3;
else if (s[i]==s[i-1]&&s[i]!=s[i+1]) j*=2;
else if (s[i]!=s[i-1]&&s[i]==s[i+1]) j*=2;
    
}
}
printf("%lld",j);
    
}