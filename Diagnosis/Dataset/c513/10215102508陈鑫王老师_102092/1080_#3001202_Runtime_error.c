#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {int cnt,v[101];}BIGINT;
void DIV2(BIGINT*n)
{
    int carry=0,i;
    if(n->v[n->cnt-1]<2)
    {
        n->cnt--;
        carry=1;
    }
    for(i=n->cnt-1;i>=0;i--)
    {
        int t=carry*10+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}
void MUL2ADD(BIGINT *n,int d)
{
    int carry=d;
    for(int i=0;i<n->cnt;i++)
    {
        int t=n->v[i]*2+carry;
        n->v[i]=t%10;
        carry=t/10;
    }
    if(carry>0)n->v[n->cnt++]=carry;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        char s[102];
        scanf("%s",s);
        BIGINT n={0,{0}};
        n.cnt=strlen(s);
        for(int i=0;i<n.cnt;i++)
        {
            n.v[i]=s[n.cnt-i-1]-'0';
        }
        int ans[334],cnt=0;
        while(n.cnt>0)
        {
            s[cnt++]=n.v[0]%2;
            DIV2(&n);
        }
        for(int i=0;i<cnt;i++)MUL2ADD(&n,s[i]);
        printf("case #%d:\n",k);
        if(n.cnt==0)n.cnt++;
        for(int i=n.cnt-1;i>=0;i--)
        {
            printf("%d",n.v[i]);
        }
        printf("\n");




    }
    return 0;
}
