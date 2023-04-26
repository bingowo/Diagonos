#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    long long num;
    int h;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.h!=s2.h)
        return s2.h-s1.h;
    else
    {
        if(s1.num>s2.num)
            return 1;
        else return -1;
    }
}

int main()
{
   int t;
   scanf("%d\n",&t);
   for(int i=0;i<t;i++)
   {
       int n;
       scanf("%d",&n);
       node a[n];
       for(int i=0;i<n;i++)
       {
           char s[25];
           scanf("%s",s);
           int len=strlen(s),flag=0,k=0;
           a[i].num=0;
           if(s[0]=='-')
           {
               flag=1;
               k++;
               a[i].h=s[1]-'0';
           }
           else
           {
               a[i].h=s[0]-'0';
           }
           for(int j=k;j<len;j++)
           {
                a[i].num=a[i].num*10+s[j]-'0';
           }
           if(flag==1)
                a[i].num=-a[i].num;
       }
       qsort(a,n,sizeof(a[0]),cmp);
       printf("case #%d:\n",i);
       for(int i=0;i<n;i++)
        printf("%lld ",a[i].num);
       printf("\n");

   }
}
