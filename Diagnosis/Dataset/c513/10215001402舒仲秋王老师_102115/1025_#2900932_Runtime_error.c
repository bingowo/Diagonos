#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int com(char s[])
{
    int ret[100],l=strlen(s),i,flag=0;
    for(i=0;i<100;i++) ret[i]=1;
    for(i=0;i<l;i++) ret[s[i]-'A']=0;
    for(i=0;i<100;i++)
        if(ret[i]==0) flag++;
    return flag;
}

int cmp(const void *a,const void *b)
{
    char* d1,* d2;
    d1=*((char**)a),d2=*((char**)b);
    int t1=com(d1),t2=com(d2),t;
    if(t1!=t2) t=t2-t1;
    else t=strcmp(d1,d2);
    return t;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int j,n,flag;char s[105][105];
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%s",s[j]);
        flag=j;
        qsort(s,j-1,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<flag;j++) printf("%s\n",s[j]);
    }
    return 0;
}

