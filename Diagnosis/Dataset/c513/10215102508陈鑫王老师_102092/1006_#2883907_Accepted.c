#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
   int T;
   scanf("%d",&T);
   getchar();
   for(int i=0;i<T;i++)
   {
       char S[61];
       scanf("%s",&S);
      long long int w,ans;
       w=pow(3,(strlen(S)-1));
       ans=0;
       for(long long int j=0;j<strlen(S);j++)
       {
           if(S[j]=='-')
           {
               ans=ans-w;
           }
           if(S[j]=='1')ans=ans+w;
           w=w/3;
       }
       printf("case #%d:\n%lld\n",i,ans);
   }
   return 0;
}
