#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int cnt;//记录大整数的位数
    int v[101];//记录每一位的值，v[0]个位，v[1]十位
}BIDINT;

void DIV2(BIDINT *n)//大整数的除2问题
{
    int a=0;
    if(n->v[n->cnt-1]<2)
    {
        n->cnt--;
        a=1;
    }
    for(int i=n->cnt-1;i>=0;i--)
    {
        int t=10*a+n->v[i];
        n->v[i]=t/2;
        a=t%2;
    }
}

void ADD1(BIDINT *n)//大整数的+1问题
{
    int a=0,i=1;
    n->v[0]=n->v[0]+1;
    a=n->v[0]/10;
    n->v[0]=n->v[0]%10;
    while(a!=0 && i<n->cnt)
    {
        n->v[i]+=a;
        a=n->v[i]/10;
        n->v[i]=n->v[i]%10;
        i++;
    }
    if(a!=0)
    {
        n->v[i]=a;
        n->cnt++;
    }
}
int main()
{
    char s[110];
    scanf("%s",s);
    int sign=1;
    int len=strlen(s);
    BIDINT n={0,{0}};
    for(int i=len-1;i>=1;i--)
    {
        n.v[n.cnt++]=s[i]-'0';
    }
    if(s[0]=='-')
        sign=-1;
    else
    {
        n.v[n.cnt++]=s[0]-'0';
    }
    int bin[400]={0},cnt=0;
    while(n.cnt>0)
    {
        int t=n.v[0]%2;
        bin[cnt++]=t;
        DIV2(&n);
        if(sign==-1 && t)
        {
            if(n.cnt==0)
            {
                n.cnt++;
                n.v[0]=1;
            }
            else
                ADD1(&n);
        }
        sign=-sign;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        printf("%d",bin[i]);
    }
    printf("\n");
    return 0;
}
