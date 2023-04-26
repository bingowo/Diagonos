#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int cnt;
    int v[101];
}BIGINT;

void DIV2(BIGINT*n)
{
    int i,carry=0;
    if(n->v[n->cnt-1]<2)
    {
        n->cnt--;
        carry=1;
    }
    for(i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}

void MUL2ADD(BIGINT*n,int d)
{
    int i,carry=d;
    for(i=0;i<n->cnt;i++)
    {
        int t=carry+n->v[i]*2;
        n->v[i]=t%10;
        carry=t/10;
    }
    if(carry>0) n->v[n->cnt++]=carry;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char ln[102];
        int j;
        BIGINT n;
        scanf("%s",ln);
        n.cnt=strlen(ln);
        for(j=0;j<n.cnt;j++)
            n.v[j]=ln[n.cnt-j-1]-'0';
        int bin[334];
        int cnt=0;
        while(n.cnt>0)
        {
            bin[cnt++]=n.v[0]%2;
            DIV2(&n);
        }
        printf("case #%d:\n",i);
        for(j=0;j<cnt;j++)
            MUL2ADD(&n,bin[j]);
        if(n.cnt==0) n.cnt++;
        for(j=n.cnt-1;j>=0;j--)
            printf("%d",n.v[j]);
        printf("\n");
    }
    return 0;
}
