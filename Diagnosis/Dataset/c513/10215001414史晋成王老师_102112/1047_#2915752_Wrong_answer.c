#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct shu
{int num; char str;};
int main()
{ int T,i,j,k,cnt,rcnt; char s[1100]; char prev; struct shu f[1200];
scanf("%d\n",&T);
for(i=0;i<T;i++)
{scanf("%s\n",s);
     rcnt=0;k=0;cnt=0;
     for(prev=s[k++];s[k];cnt++,prev=s[k++])
     { if(prev!=s[k]) {f[rcnt].str=prev;f[rcnt++].num=cnt;cnt=0;}
         }
        f[rcnt].str=prev;f[rcnt++].num=cnt; 
        printf("case #%d:\n",i);
        for(j=0;j<rcnt;j++)
        { printf("%d%c",f[j].num,f[j].str);
        }
        printf("\n");
}
    
}