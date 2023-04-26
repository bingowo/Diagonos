#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* name;
    char* www;

}mail;

int splitstring(char* zong,char sign,char* fen[],int maxn)
{
    int len,i,co=0;
    len=strlen(zong);
    fen[co++]=zong;
    for(i=0;i<len;i++)
    {
        if(zong[i]==sign)
        {
            zong[i]=0;
            fen[co++]=&zong[i+1];
            if(co>=maxn) break;
        }

    }
    return co;

}

int cmp(const void*a,const void*b)
{
    mail* aa=(mail*)a;
    mail* bb=(mail*)b;
    if(strcmp(aa->www,bb->www)>0) return 1;
    else if(strcmp(aa->www,bb->www)<0) return -1;
    else
    {
        if (strcmp(aa->name,bb->name)<=0) return 1;
        else if (strcmp(aa->name,bb->name)>0) return -1;
    }

}

int main()
{
    int n,i,maxn=2,co,len;
    scanf("%d",&n);

    char *s=malloc(1000000);
    memset(s,0,1000000);
    char *fs[2];
    mail *m=(mail*)malloc(n*sizeof(mail));
    memset(m,0,sizeof(mail)*n);
    int np=0;
    for(i=0;i<n;i++)
    {

        char* pointer=s+np;
        scanf("%s",pointer);
        len=strlen(pointer);
        np+=len+1;
        co=splitstring(pointer,'@',fs,maxn);

        m[i].name=fs[0];
        m[i].www=fs[1];
        //printf("test test:i=%d %s@%s\n",i,m[i].name,m[i].www);
    }
    qsort(m,n,sizeof(mail),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s@%s\n",m[i].name,m[i].www);
    }
    free(m);
    free(s);
    return 0;
}
