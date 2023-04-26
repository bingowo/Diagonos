#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct data
{
    char str[200];
};
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
    struct data d1,d2;
    d1=*((struct data*)a),d2=*((struct data*)b);
    int t1=com(d1.str),t2=com(d2.str),t;
    if(t1!=t2) t=t2-t1;
    else t=strcmp(d1.str,d2.str);
    return t;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int j,n;
        struct data s[505];
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%s\n",s[j].str);
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++) printf("%s\n",s[j].str);
    }
    return 0;
}

