#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
   int t;
   scanf("%d\n",&t);
   for(int i=0;i<t;i++)
   {
       char s[250];
       char s2[250];int k=0;
       gets(s);
       int len=strlen(s);
       int p[26]={0};
       int idx[250]={0};
       for(int i=0;i<len;i++)
       {
           if(s[i]==' '||s[i]>'Z'||s[i]<'A')
           {
              // s2[i]=s[i];
               idx[i]=1;
           }
           else if(s[i]>='A'&&s[i]<='Z')
           {
               p[s[i]-'A']++;
           }
       }
       for(int i=0;i<26;i++)
       {
           int temp=p[i];
           for(int j=0;j<temp;j++)
                s2[k++]=i+'A';
       }
       int cnt=0;
       printf("case #%d:\n",i);
       for(int i=0;i<len;i++)
       {
           if(idx[i]==1)
                printf("%c",s[i]);
           else{
                printf("%c",s2[cnt++]);
           }
       }
       printf("\n");
   }
}
