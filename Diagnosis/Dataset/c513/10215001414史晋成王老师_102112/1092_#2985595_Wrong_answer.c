#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mul(int a[],int f)
{ int j,k,n=1100,t,s,flag=0;
    for(j=0;j<n;j++)
   { t=a[j]*f+flag;
     a[j]=t%10;
     flag=t/10;
}
    
}
int main()
{char s[1200];
long long int i,j,k,n,m;
int a[1100]={0};
scanf("%s\n",s);
n=strlen(s);
a[0]=1;
for(i=0;i<n;i++)
{ if (n==1) break;
    if(i==0)
{ if(s[i]!=s[i+1]) mul(a,2);
}
else if(i==n-1)
{if (s[i]!=s[i-1]) mul(a,2);}
else 
{ if (s[i]!=s[i-1]&&s[i]!=s[i+1]) mul(a,3);
else if (s[i]==s[i-1]&&s[i]!=s[i+1]) mul(a,2);
else if (s[i]!=s[i-1]&&s[i]==s[i+1]) mul(a,2);
    
}
}
for(m=1009;m>=0;m--)
{if (a[m]!=0) break;}
 for(j=m;j>=0;j--)
 printf("%d",a[j]);
}