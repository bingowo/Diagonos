#include<stdio.h>
int main()
{char s[1000000];
 scanf("%s",s);
 int start=0,len1=0,len2=0,len=0;
 int m[128];
 int i;
 for(i=0;i<128;i++)
 {m[i]=-1;}
 int t=0;
 char c;
 for(i=0;s[i];i++)
 { int d;
   c=s[i];
   if(m[c]>=t)
   {int j;
    for(j=t;j<i&&s[j]!=s[i];j++)
    {start=j;
     len1=j-t+1;
    }
    t=m[c]+1;
    m[c]=i;
   }
   else
   {m[c]=i;
   if(len<i-t+1)
   {start=t;
    len2=i-t+1;
   }
    }
    if(len1>=len2) len=len1;
    else len=len2;
    if(len>d) d=len;
 }
 for(i=0;i<len;i++)
 printf("%c",s[start+i]);
 return 0;
}
