#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char* del(char *s)
{
    char*p=s,*q=s,*temp=s;
    int flag=0,sign=0;
    while(*q!='\0')
    {
        if(*q==*(q+1))
        {
            flag=1;temp=q;
        }
        if(flag==1)
        {
            while(*temp==*q) q++;
            *temp='\0';
            if(*q=='\0') break;
            strcat(p,q);
            q=temp;
            if(*q==*(q-1)) sign=1;
        }
        if(flag==0) q++;
        flag=0;
    }
    if(sign==1) del(p);
    return p;
}
int main()
{
   int T;
   scanf("%d",&T);
   char s[110];
   for(int cas=0;cas<T;cas++)
   {
       scanf("%s",s);
       int len=strlen(s);
       int min=len;
       for(int i=0;i<len;i++)
       {
           int k=0; char t[110];
           for(int j=0;j<=i;j++)
           {
               t[k++]=s[j];
           }
           for(int j=i;j<len;j++)
           {
               t[k++]=s[j];
           }
           t[k++]='\0';
           char* p=del(t);
           if(strlen(p)<=min) min=strlen(p);
       }
       printf("case #%d:\n",cas);
       printf("%d\n",len+1-min);
   }
   return 0;
}
