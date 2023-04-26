#include <stdio.h>
#include <stdlib.h>
typedef struct{int cnt,v[101];}BIGINT;

//大数除2
void DIV2(BIGINT *n)
{
	int carry=0;  //carry是借位
	if(n->v[n->cnt-1]<2)
    {
		n->cnt--;
		carry=1;
	}
	for(int i=n->cnt-1;i>=0;i--)
	{
		int t=10*carry+n->v[i];
		n->v[i]=t/2;
		carry=t%2;
	}
}

void MUL2ADD(BIGINT *n,int d)
{
	int carry=d;
	for (int i=0;i<n->cnt;i++)
    {
		int t=carry+n->v[i]*2;
		n->v[i]=t%10;
		carry=t/10;
	}
	if(carry>0)n->v[n->cnt++]=carry;//最高位进位的处理
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        //输入大数
        char line[101]={0};
        BIGINT n;
        scanf("%s",line);
        n.cnt=strlen(line);
        for(int i=0;i<n.cnt;i++)
            n.v[i]=line[n.cnt-i-1]-'0';
        //处理大数变为2进制
        int bin[334],cnt=0;
        while(n.cnt>0)
        {
            bin[cnt++]=n.v[0]%2;
            DIV2(&n);
        }
        //反向霍纳规则计算出转置后对应的10进制大数
        for(int i=0;i<cnt;i++)
            MUL2ADD(&n,bin[i]);
        if(n.cnt==0)
        {
            n.cnt++;
        }
        printf("case #%d:\n",Case);
        for(int i=n.cnt-1;i>=0;i--)
        {
            printf("%d",n.v[i]);
        }
        printf("\n");
    }
    return 0;
}
