#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int n; char s[105];
    for(int i=0;i<n;i++)
    {  int tot[4]={0},ans[4]={0},cnt[4]={0};
       scanf("%s",s);
       int id=0;
       while(s[id])
       {
           ++tot[id%4];
           switch(s[id])
           {
               case 'R':cnt[0]++;ans[0]=id%4;break;
               case 'B':cnt[1]++;ans[1]=id%4;break;
               case 'Y':cnt[2]++;ans[2]=id%4;break;
               case 'G':cnt[3]++;ans[3]=id%4;break;
           }
           id++;
       }
       printf("case #%d:\n",i);
       printf("%d %d %d %d\n",tot[ans[0]]-cnt[0],tot[ans[1]]-cnt[1],tot[ans[2]]-cnt[2],tot[ans[3]]-cnt[3]);
    }
    return 0;
}
