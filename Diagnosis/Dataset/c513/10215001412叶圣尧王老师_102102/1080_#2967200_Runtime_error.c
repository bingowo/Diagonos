#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int d[100];
    int cnt;
}bigint;

int chu(int *put,int len,int *out)
{
    int i,pos=0;
    for(i=0;pos<len;i++)
    {
        int t,div=0;
        for(int j=pos;j<len;j++)
        {
            t=put[j]+div*10;
            put[j]=t/2;
            div=t%2;
        }
        out[i]=div;
        if(put[pos]==0)pos++;
    }
    return i;
}
int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[100],out[335];
        printf("case #%d:\n",t);
        scanf("%s",s);
        bigint X={{0},0};
        for(int i=0;i<strlen(s);i++)
        {X.d[i]=s[i]-'0';X.cnt++;}
        int k=chu(X.d,X.cnt,out);
        for(int j=0;j<k;j++)printf("%d",out[j]);
    }
}
