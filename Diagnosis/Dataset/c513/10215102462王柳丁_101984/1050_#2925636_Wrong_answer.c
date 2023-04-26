#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sitef(char *a1,char *a)//返回a1[n]在a中出现的位置
{
    int i,j;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]==a1[0])
        {
            for(j=0;j<strlen(a1);j++)
            {
                if(a1[j]!=a[i+j])break;
            }
            j=j-1;
            if(j==(strlen(a1)-1))return (i+j);
        }
    }
}
int sitel(char *a1,char *a)//返回a1[0]在a中出现的位置
{
    int i=strlen(a)-1;
    int n=strlen(a1)-1;
    int j;
    for(;i>=0;i--)
    {
        if(a[i]==a1[n])
        {
            for(j=0;j<strlen(a1);j++)
            {
                if(a1[n-j]!=a[i-j])break;
            }
            j=j-1;
            if(j==n)return (i-j);
        }
    }
}

int main()
{
   int T;
   scanf("%d",&T);
   int i;
   for(i=0;i<T;i++)
   {
       char s1[81],s2[81],s[81];
       scanf("%s",s1);
       scanf("%s",s2);
       scanf("%s",s);
       int a1=sitef(s1,s);
       //printf("(a1=%d)\n",a1);
       int a2=sitel(s2,s);
       //printf("(a2=%d)\n",a2);
       if(a1>a2)
       {
           a2=sitel(s1,s);
           a1=sitef(s2,s);
       }
       int res=a2-a1-1;
       printf("case #%d:\n",i);
       printf("%d\n",res);
   }
    return 0;
}
