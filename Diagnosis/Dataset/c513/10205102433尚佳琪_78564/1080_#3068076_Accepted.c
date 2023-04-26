#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    int cnt,v[100];
} BIGINT ;

void DIV2(BIGINT *n)//除以2运算(10->2
{
	int carry=0,i;
	if (n->v[n->cnt-1]<2)
    {
		n->cnt--;
		carry=1;
	}
	for (i=n->cnt-1;i>=0;i--)
    {
		int t=10*carry+n->v[i];
		n->v[i]=t/2;
		carry=t%2;
	}
}
void MUL2ADD(BIGINT *n, int d) //*2+1运算(2->10
{
	int carry=d,i;
	for (i=0;i<n->cnt;i++)
    {
		int t=carry+n->v[i]*2;
		n->v[i]=t%10;
		carry=t/10;
	}
	if (carry>0)
        n->v[n->cnt++]=carry;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        char line[102];
        int i;
        BIGINT n;
        scanf("%s",line);
        n.cnt=strlen(line);
        for (i=0;i<n.cnt;i++)
            n.v[i]=line[n.cnt-i-1] -'0';
        int s[334],cnt=0;
        while (n.cnt>0) //10->2
        {
            s[cnt++]=n.v[0]%2;
            DIV2(&n);
        }//0在最低位，后续当作最高位，即倒置
        for (i=0;i<cnt;i++)  //2->10
            MUL2ADD(&n,s[i]);
        if (n.cnt==0)
        {
            n.cnt++;
        }
        printf("case #%d:\n",j);
        for (i=n.cnt-1;i>=0;i--)
        {
            printf("%d",n.v[i]);
        }
        printf("\n");
    }
}
