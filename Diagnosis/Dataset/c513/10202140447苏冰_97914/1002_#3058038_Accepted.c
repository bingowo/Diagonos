#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
       char s[70];
       scanf("%s",s);
       int r=0;
       int a[130];
       memset(a,-1,sizeof(a));
       a[s[0]]=1;
       for(int i=1;i<strlen(s);i++)
       {
           if(a[s[i]]==-1)
           {
               a[s[i]]=r;
               if(r==0)r=2;
               else if(r>0) r++;
           }
       }
       if(r<2) r=2;
       long long ans=0;
       for(int i=0;i<strlen(s);i++)
       {
           ans=ans*r+a[s[i]];
       }
       printf("case #%d:\n%lld\n",cas,ans);
    }
    return 0;
}

