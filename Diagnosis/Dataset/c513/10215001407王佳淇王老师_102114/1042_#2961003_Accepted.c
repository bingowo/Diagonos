#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    char word[20];
}singleword;
long long co=0;
singleword *ans;
int cmp(const void*a,const void*b)
{
    char aa=*((char*)a);
    char bb=*((char*)b);
    return aa-bb;
}

void makeword(char *zong,int l,int k,char*strget)
{
    if(k>=l)
    {
        strget[l]=0;
        strcpy(ans[co++].word,strget);
        return;

    }
    int i,nleft=l-k-1;
    for(i=0;i<strlen(zong)-nleft;i++)
    {
        strget[k]=zong[i];
        makeword(zong+i+1,l,k+1,strget);
    }
}

int cmp2(const void*a,const void*b)
{
    singleword aa=*((singleword*)a);
    singleword bb=*((singleword*)b);

    return strcmp(aa.word,bb.word);
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        co=0;
        char s[20];
        memset(s,0,sizeof(char)*20);
        scanf("%s",s);
        int len=strlen(s),j,k,n,l;
        long long sum=1;
        qsort(s,len,sizeof(char),cmp);
        char ne[20];
        memset(ne,0,sizeof(char)*20);
        for(j=0,k=0;j<len-1;j++)
        {
            if(s[j]!=s[j+1]) ne[k++]=s[j];
        }
        ne[k++]=s[j];
        //printf("test: ne=%s\n",ne);
        n=k;
        for(j=0;j<n;j++)
        {
            sum*=2;
        }

        char str[20];
        memset(str,0,sizeof(char)*20);
        ans=(singleword*)malloc(sizeof(singleword)*sum);
        for(j=1;j<=strlen(ne);j++)
        {
            makeword(ne,j,0,str);
        }

        qsort(ans,co,sizeof(singleword),cmp2);
        printf("case #%d:\n",i);
        for(j=0;j<co;j++)
        {
            printf("%s\n",ans[j].word);
        }

        //printf("i=%d,sum=%d,co=%d\n",i,sum,co);

        free(ans);
    }
    return 0;
}