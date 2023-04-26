#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Max 1000000007
#define Mod 210
int subint(char*s,int l,int r)
{
    int a=0;
    for(int i=l;i<=r;i++)
    {
        a*=10;
        a+=s[i]-'0';
        a%=Mod;
    }
    return a;
}
int main()
{
   int n;
   char s[101];
   scanf("%d",&n);
   for(int t=0;t<n;t++)
   {
       scanf("%s",s);
       int f[100][210]={0};
       for(int i=0;i<strlen(s);i++)
       {
           f[i][subint(s,0,i)]+=1;
           f[i][subint(s,0,i)]%=Max;
           for(int j=0;j<i;j++)
           {
               int temp=subint(s,j+1,i);
               for(int k=0;k<Mod;k++)
               {
                   f[i][(k+Mod+temp)%Mod]+=f[i][k];
                   f[i][(k+Mod+temp)%Mod]%=Max;
                    f[i][(k+Mod-temp)%Mod]+=f[i][k];
                   f[i][(k+Mod-temp)%Mod]%=Max;

               }
           }
           
       }
           int ans=0;
           for(int k=0;k<Mod;k++)
           {
               if(!(k%2)||!(k%3)||!(k%5)||!(k%7)))
               {
                   ans+=f[strlen(s)-1][k];
                   ans%=Max;
               }
           }
           printf("%d\n",ans);
       
   }
}
