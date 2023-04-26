#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
typedef struct
{
    int cnt[30];
    char a[30];
}sss;
int cmp(const void*a,const void *b)
{
    int*p=(int*)a;
    int*q=(int*)b;
    return(*p-*q);
}
int main()
{
   int n;
   scanf("%d",&n);
   char x[101];
   sss* s=(sss*)malloc(n*sizeof(sss));
   int i=0;
   for(i=0;i<n;i++)
   {
       scanf("%s",x);
       memset(s[i].cnt,0,sizeof(s[i].cnt));
       int k=0;
       for(int j=0;j<strlen(x)-1;j++)
       {
           s[i].cnt[x[j]-'a']++;
           if(x[j]!=x[j+1]) s[i].a[k++]=x[j];
       }
       s[i].cnt[x[strlen(x)-1]-'a']++;
       s[i].a[k++]=x[strlen(x)-1];
       s[i].a[k++]='\0';
   }
   int ans=0;
   int flag=0;
   for(int j=0;j<n;j++)
   {
       for(int k=j+1;k<n;k++)
       {
            if(strcmp(s[j].a,s[k].a)!=0)
            {
                ans=-1;flag=1;break;
            }
       }
      if(flag) break;
   }
   if(flag==0)
   {
       int mm[30];
       int j=0;int k=0;
       while(s[0].a[j]!='\0')
       {
           char ch=s[0].a[j];
           for(k=0;k<n;k++)
           {
               mm[k]=s[k].cnt[ch-'a'];
           }
           j++;
            qsort(mm,k,sizeof(mm[0]),cmp);
            int lev=mm[k/2];
            for(int d=0;d<n;d++)
            {
                ans+=abs(mm[d]-lev);
            }
       }
   }
   printf("%d\n",ans);
   free(s);
   return 0;
}
