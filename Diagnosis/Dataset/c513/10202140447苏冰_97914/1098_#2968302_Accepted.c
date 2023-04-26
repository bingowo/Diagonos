#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
   int a[26]={0};
   int T;
   scanf("%d",&T);
   char s[110];
   for(int cas=0;cas<T;cas++)
   {
       scanf("%s",s);
       memset(a,0,sizeof(a));
       if(strlen(s)>4)
       {
           for(int i=0;i<4;i++)
       {
           int cnt=0;char c;
           for(int j=i;;j+=4)
           {
               if(j>=strlen(s)) break;
               if(s[j]=='!') cnt++;
               else c=s[j];
           }
           a[c-'A']+=cnt;
       }
       }
       else
       {
           int sum=0;
           for(int i=0;i<strlen(s);i++)
           {
               if(s[i]!='!') sum+=s[i]-'A';
           }
           a[48-sum]++;
       }
       printf("case #%d:\n",cas);
       printf("%d %d %d %d\n",a['R'-'A'],a['B'-'A'],a['Y'-'A'],a['G'-'A']);
   }
   return 0;
}
