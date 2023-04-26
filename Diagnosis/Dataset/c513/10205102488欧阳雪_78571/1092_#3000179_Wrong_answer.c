#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_LEN 10000    //定义竖式运算的精度，数值可改变
#define INT(x) int x[MAX_LEN] = {0}     //高精度数的定义方式
void assign(int* x,int y)
{
    if(y>=0)    x[0] = 1;
    else
    {
        x[0] = 0;
        y=-y;
    }
    for(int i=MAX_LEN-1;i>=1&&y;i--)
    {
        x[i] = y%10;
        y/=10;
    }
}
void mul(int* x,int y)
{
    int r=0;
    if((!x[0]&&y<=0) || (x[0]&&y<0))
    {
        x[0]=!x[0];
        y=-y;
    }
    for(int i=MAX_LEN-1;i>=1;i--)
    {
        int tmp = x[i]*y +r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
void print(int* x)
{
    int flag = 0;
    if(!x[0])   printf("-");
    for(int i=1;i<MAX_LEN;i++)
    {
        if(!flag && !x[i])  continue;
        flag = 1;
        printf("%d",x[i]);
    }
    if(!flag)   printf("0");
    printf("\n");
    //return 0;
}
int main()
{
	char s[1001]={0};
	scanf("%s",s);
	int cnt[1001]={0};
	int len=strlen(s);
	if(len==1){
		printf("%d",1);
		return 0;
	} 
	
	if(s[0]!=s[1])cnt[0]=2;//计算每个位置可能的种数 
	else cnt[0]=1;
	if(s[len-1]!=s[len-2])cnt[len-1]=2;
	else cnt[len-1]=1;
	for(int i=1;i<len-1;i++)
	{
		if(s[i]!=s[i-1]&&s[i]!=s[i+1])cnt[i]=3;
		else if(s[i]==s[i-1]&&s[i]==s[i+1])cnt[i]=1;
		else cnt[i]=2;
	}
	
	INT(ANS); 
	memset(ANS,0,sizeof(ANS));
	assign(ANS,1);
	for(int j=0;j<len;j++)
	{
		mul(ANS,cnt[j]);
	}
	
	print(ANS);
	return 0;
}