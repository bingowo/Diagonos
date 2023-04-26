#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{char *name,*address;}mail;

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
    char w[1000001],**t;
    mail *s;
    scanf("%d",&n);
    t=(char**)malloc(n*sizeof(char*));
    s=(mail*)malloc(n*sizeof(mail));
    for(i=0;i<n;i++)
   {
      scanf("%s",w);
      len=strlen(w);
      strcpy(t[i]=(char*)malloc((len+1)*sizeof(char)),w)
      s[i].name=(char*)malloc(len*sizeof(char));
      s[i].address=(char*)malloc(len*sizeof(char));
      for(j=0;t[i][j]!='@';j++)s[i].name[j]=t[i][j];
      for(k=0;t[i][j]!='\0';j++,k++)s[i].address[k]=t[i][j];
      s[i].address[k]='\0';
  }
    qsort(s,n,sizeof(mail),compare);
    for(i=0;i<n;i++)printf("%s%s\n",s[i].name,s[i].address);
    free(s);

    return 0;
}