#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
   int T;char s[100];long long num;
   scanf("%d",&T);
   int i=0,lenth,k,j=0;
   while(scanf("%s",s)!=EOF)
   {
       num=0;
       printf("case #%d:\n",j++);
       lenth=strlen(s);
       for(i=0;i<lenth;i++)
       {
           if(s[i]=='-')k=-1;
           else k=s[i]-'0';
           num=num*3+k;
       }
       printf("%lld\n",num);
   }
   
}
