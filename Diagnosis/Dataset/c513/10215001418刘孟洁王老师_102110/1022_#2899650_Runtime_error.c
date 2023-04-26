#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100000
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
    qsort(s,n,sizeof(mail),compare);
    for(i=0;i<n;i++)printf("%s%s\n",s[i].name,s[i].address);
    free(s);
    return 0;
}
