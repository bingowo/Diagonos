#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ char s[50000],s2[50000];
 int i,j,n,m,l,k;
 scanf("%d",&n);
 memset(s,0,sizeof(s));
 s[0]='0';
 for(i=0;i<n;i++)
 { memset(s2,0,sizeof(s2));
   for(j=0;j<strlen(s);j++)
   {if(s[j]=='0') s2[j]='1';
    else if(s[j]=='1') s2[j]='0';
   }
   l=strlen(s);
   for(j=l;j<2*l;j++)
   {s[j]=s2[j-l];}
   s[j]=0;
 }
 printf("%s",s);
    
}