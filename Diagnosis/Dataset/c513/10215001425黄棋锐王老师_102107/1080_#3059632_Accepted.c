#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	int cnt;//计位数 
	int v[102];//v[0]个位,v[1]十位,v[2]百位 
}BIGINT;// 需要两个信息，位数和每一位上的数字 ，int类型
void DIV2(BIGINT*n)//BIGINT除以2 
{	int carry=0,i;
	if(n->v[n->cnt-1]<2) //首位小于2，除以2后位数会减少
	{
	  n->cnt--;//位数减少，相当于直接跳到下一位除2，如15/2实际为（10+5）/2
	  carry=1;//进位数，次高位得1(1*10) 
    }
	for(i=n->cnt-1;i>=0;i--)//除法从最高位开始
	{   int t=carry*10+n->v[i];//此位加进位数后的计算值 
		n->v[i]=t/2;
		carry=t%2;//进位数，carry要么1要么0 
	}
}

void  MUL2ADD(BIGINT*n,int d)//二进制转十进制 
{//乘法从最低位开始
	int carry=d,i;//carry-进位 ，d为0时任然有效 
	for (i=0;i<n->cnt;i++) {//后面加一位数，已有的位的数都要乘2 
		int t=carry+n->v[i]*2;// 进位后的计算值， 
		n->v[i]=t%10;//此位有效十进制数 
		carry=t/10;//进位数 
	}
	if (carry>0) n->v[n->cnt++]=carry;//carry非0表示位数不够，最高位容不下，需要加位数，即进1，如 carry=1,v[i]=7,carry=(7*2+1)/10=1，得到v[i+1]=1,v[i]=5 

}
int main()
{   int k,T;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {  char line[102]={'\0'};
 	scanf("%s",line);
 	printf("case #%d:\n",k);
 	BIGINT n;
 	n.cnt=strlen(line);//总位数
 	int i;
 	for(i=0;i<n.cnt;i++)
 		n.v[i]=line[n.cnt-1-i]-'0';
 	int er[334]={0},cnt=0;
 	while(n.cnt>0)//十进制转二进制 ,BIGINT除到计位数cnt为0，最后一次n.v[o]为0或1 
 	{
 		er[cnt++]=n.v[0]%2;//直接顺序加就已经是倒转的二进制了 
 		DIV2(&n); //BIGINT除以2 
	 }
 	for (i=0;i<cnt;i++) MUL2ADD(&n,er[i]);//二转十，从二的最高位开始算 
 	if(n.cnt==0) n.cnt++;//全为0 
 	for(i=n.cnt-1;i>=0;i--) printf("%d",n.v[i]); //输出 
 	printf("\n");
 }
	return 0;
}