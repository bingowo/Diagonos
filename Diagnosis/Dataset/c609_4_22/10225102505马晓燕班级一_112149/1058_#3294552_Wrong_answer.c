#include <stdio.h>
#include <string.h>

typedef struct{ int cnt,v[101];}BIGINT;

void BIGINT_plus(BIGINT* n)//大整数+1
{
    for(int i=0;i<n->cnt;i++)
    {
        n->v[i]++;
        if(n->v[i]>=10)
            n->v[i+1]+=n->v[i]/10,n->v[i]-=10;
    }
    if(n->v[n->cnt])
        n->cnt++;
    // int carry =0,i=0;
    // n->v[i]++;
    // do
    // {
    //     n->v[i]+=carry;
    //     carry= n->v[i]/10;
    //     n->v[i]= n->v[i]%10;
    //     i++;
    // }while(i<n->cnt);
    // if(carry!=0)
    //     n->v[n->cnt++]=carry;
}
void BIGINT_division(BIGINT *n)//大整数/2
{
    int carry=0;//借位
    if(n->v[n->cnt-1]<2)
        n->cnt--,carry=1;
    for(int i=n->cnt-1;i>=0;i--)
    {
       int t=10*carry+n->v[i];
       n->v[i] = t/2;
       carry = t%2;
    }
}

//若余数小于0，所等商加一，余数加上|m|（基数绝对值）
int main()
{
	char num[105]={0};
	scanf("%s",num);
	int len=strlen(num);
	int sign =1;
	//存放大整数
	BIGINT n={0,{0}};
	for(int i=len-1;i>0;i--)//从个位开始放
        n.v[n.cnt++]=num[i]-'0';
	if(num[0]=='-')
        sign=-1;
    else
        n.v[n.cnt++]=num[0]-'0';
    //转换
	if(num[0]==0)
		putchar('0');
	else
    {
        int bin[400]={0},cnt=0;

        while(n.cnt > 0)
        {
            int temp = n.v[0]%2;//大整数%2即尾数%2

            bin[cnt++]=temp;
            BIGINT_division(&n);

            if(sign==-1 && temp!=0)//负数除负数转化成正数除法，则商加一
            {
                if(n.cnt==0)    { n.cnt++,n.v[0]=1; }
                else    BIGINT_plus(&n);//商加一
            }
            sign = -sign;
        }
        for(int i=cnt-1;i>=0;i--)
            printf("%d",bin[i]);
        putchar('\n');
    }
	return 0;
}
