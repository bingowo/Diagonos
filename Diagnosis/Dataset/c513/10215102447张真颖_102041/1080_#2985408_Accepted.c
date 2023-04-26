#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;
    int v[101];
}BIGINT;

void Div(BIGINT* n)
{
    int carry=0;
    if(n->v[n->cnt-1]<2)
    {
        n->cnt--;
        carry=1;
    }//判断最高位是否需要借位
    for(int i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;//计算除以二
    }
}
void mul2add(BIGINT*nn,int d)
{
    int carry=d;//技巧：加的数直接作为进位，不用另写加法
    for(int i=0;i<nn->cnt;i++)
    {
        int t=carry+nn->v[i]*2;
        nn->v[i]=t%10;
        carry=t/10;
    }
    if(carry>0) nn->v[nn->cnt++]=carry;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        BIGINT n;
        char line[102]={0};
        scanf("%s",line);
        n.cnt=strlen(line);
        for(int i=0;i<strlen(line);i++)
            n.v[i]=line[n.cnt-i-1]-'0';//倒序输入n值，方便后续除法是忽略前置0
        int bin[334]={0},cnt=0;
        while(n.cnt>0)
        {
            bin[cnt++]=n.v[0]%2;
            Div(&n);
        }//计算二进制数
        BIGINT nn;
        nn.cnt=0;
        nn.v[0]=0;
        for(int i=0;i<cnt;i++)
            mul2add(&nn,bin[i]);//用霍纳规则算十进制数
        if(nn.cnt==0)
            nn.cnt+=1;
        printf("case #%d:\n",i);
        for(int i=nn.cnt-1;i>=0;i--)
            printf("%d",nn.v[i]);
        printf("\n");
    }
    return 0;
}