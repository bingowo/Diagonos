提交 #2899867
#	送交者	题目	语言	提交时间	评测时间	结果	耗时	内存	评测机
2899867	10215001418	1022. 邮件地址排序	C	2022-03-05 23:47:45	2022-03-05 23:47:51	
Runtime error: 80
0.668	232.059	Seattle
 C
 Copy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10000
typedef struct{char name[N],address[N];}mail;

int compare(const void*a,const void*b)
{
    mail c=*(mail*)a;
    mail d=*(mail*)b;
    if(strcmp(c.address,d.address)!=0)
      {
          if(strcmp(c.address,d.address)<0)return -1;
          else if(strcmp(c.address,d.address)>0)return 1;
    }
    else if(strcmp(c.name,d.name)<=0)return 1;
    else if(strcmp(c.name,d.name)>0)return -1;
    }

int main()
{
    int n,i,j,k;
    char t[10000][N];
    mail *s;
    scanf("%d",&n);
    s=(mail*)malloc(n*sizeof(mail));
    for(i=0;i<n;i++)scanf("%s",t[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;t[i][j]!='@';j++)s[i].name[j]=t[i][j];
        j--;
        for(j+=1,k=0;t[i][j]!='\0';j++,k++)s[i].address[k]=t[i][j];

    }
    qsort(s,n,sizeof(s[0]),compare);
    for(i=0;i<n;i++)printf("%s%s\n",s[i].name,s[i].address);
    free(s);
    return 0;
}