#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
 int T;
 scanf("%d",&T);
 char s[65];
 int N;
 long long int ans;
 for(int i=0;i<T;i++)
 {
     int p[128]={0};
     for(int j=0;j<128;j++)p[j]=-1;
     scanf("%s",s);
     int l=strlen(s);
//printf("%s\n",s);
     ans=0;N=0;
     for(int k=0;k<l;k++){
     if(p[s[k]]==-1)
     {
         N+=1;
         if(N==1)
         {
            p[s[k]]=N;
         }
        else if(N==2)p[s[k]]=0;
        else p[s[k]]=N-1;
     }
     }
     N=N>2?N:2;
     for(int k=0;k<l;k++)
     {
    //     printf("%d\n",p[s[k]]);
         ans=ans*N+p[s[k]];
     }

     printf("case #%d:\n%lld\n",i,ans);
  //   printf("%d\n",N);

 }



}
