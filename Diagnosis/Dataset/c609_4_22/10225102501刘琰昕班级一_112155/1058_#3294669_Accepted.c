#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义大数BIGINT,v[0]放个位数,v[1]放十位数...
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
//大数加1
void ADD1(BIGINT *n)
{
    int carry=0,i=1;
    n->v[0]=n->v[0]+1;
    carry=n->v[0]/10;
    n->v[0]=n->v[0]%10;
    while(carry!=0&&i<n->cnt)
    {
        n->v[i]+=carry;
        carry=n->v[i]/10;
        n->v[i]=n->v[i]%10;
        i++;
    }
    if(carry!=0)
    {
        n->v[i]=carry;
        n->cnt++;
    }
}

int main()
{
    //输入大数
    char s[110];
    scanf("%s",s);
    int sign=1,len=strlen(s);//sign记录n的符号,len记录s的长度
    BIGINT n={0,{0}};
    for(int i=len-1;i>=1;i--)
        n.v[n.cnt++]=s[i]-'0';
    if(s[0]=='-')sign=-1;
    else n.v[n.cnt++]=s[0]-'0';
    //用bin存取答案,cnt存取答案的位数
    int bin[400]={0},cnt=0;
    //大数模2,只需要考虑最低位(取正余)
    while(n.cnt>0)//直到n变为0
    {
        int temp=n.v[0]%2;
        bin[cnt++]=temp;
        DIV2(&n);
        if(sign==-1&&temp)//被除数为负且余数不为0时候,余数才需要处理(-1)
        {
            if(n.cnt==0)
            {
                n.cnt++;
                n.v[0]=1;
            }
            else ADD1(&n);
        }
        sign=-sign;
    }
    //输出
    for(int i=cnt-1;i>=0;i--)
        printf("%d",bin[i]);
    printf("\n");
    return 0;
}