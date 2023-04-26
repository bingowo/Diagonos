#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1001
typedef struct{char name[N],address[N];}mail;

int compare(const void*a,const void*b)
{
    mail c=*(mail*)a;
    mail d=*(mail*)b;
          if(strcmp(c.address,d.address)<0)return -1;
          else if(strcmp(c.address,d.address)>0)return 1;
          else if(strcmp(c.name,d.name)<=0)return 1;
          else if(strcmp(c.name,d.name)>0)return -1;
    }

int main()
{
    int n,i,j,k,len;
    char w[10000],**t;
    mail *s;
    scanf("%d",&n);
    t=(char**)malloc(n*sizeof(char*));
    s=(mail*)malloc(n*sizeof(mail));
    for(i=0;i<n;i++)
   {
      scanf("%s",w);
      len=strlen(w);
      t[i]=(char*)malloc(len*sizeof(char));
      t[i]=w;
      for(j=0;t[i][j]!='@';j++)s[i].name[j]=t[i][j];
      for(k=0;t[i][j]!='\0';j++,k++)s[i].address[k]=t[i][j];
  }
    qsort(s,n,sizeof(mail),compare);
    for(i=0;i<n;i++)printf("%s%s\n",s[i].name,s[i].address);
    free(s);

    return 0;
}