#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int cnt;
    int a[101];
}BIGINT;

void DIV2(BIGINT*n)
{
    int cry=0;
    if(n->a[n->cnt-1]<2)
    {
        n->cnt--;
        cry=1;
    }
    for(int i=n->cnt-1;i>=0;i--)
    {
        int t=10*cry+n->a[i];
        n->a[i]=t/2;
        cry=t%2;
    }
    return ;
}

void ADD1(BIGINT*n)
{
    int cry=0,i=1;
    n->a[0]=n->a[0]+1;
    cry=n->a[0]/10;
    n->a[0]=n->a[0]%10;
    while(cry!=0&&i<n->cnt)
    {
        n->a[i]+=cry;
        cry=n->a[i]/10;
        n->a[i]=n->a[i]%10;
        i++;
    }
    if(cry!=0)
    {
        n->a[i]=cry;
        n->cnt++;
    }
    return ;
}

int main()
{
    char s[110];
    scanf("%s",s);
    int sgn=1,len=strlen(s);
    BIGINT n={0,{0}};
    for(int i=len-1;i>0;i--)
    {
        n.a[n.cnt++]=s[i]-'0';
    }
    if(s[0]=='-') sgn=-1;
    else
    {
        n.a[n.cnt++]=s[0]-'0';
    }
    int bin[400]={0},cnt=0;
    while(n.cnt>0)
    {
        int tmp=n.a[0]%2;
        bin[cnt++]=tmp;
        DIV2(&n);
        if(tmp&&sgn==-1)
        {
            if(n.cnt==0)
            {
                n.cnt++;
                n.a[0]=1;
            }
            else ADD1(&n);
        }
        sgn=-sgn;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        printf("%d",bin[i]);
    }
    printf("\n");
    return 0;
}
