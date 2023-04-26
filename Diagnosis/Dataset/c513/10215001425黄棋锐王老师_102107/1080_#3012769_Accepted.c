#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	int cnt;//计位 
	int v[102];//v[0]个位,v[1]十位,v[2]百位 
}BIGINT;
void DIV2(BIGINT*n)//BIGINT除以2 
{	int carry=0,i;
	if(n->v[n->cnt-1]<2) //首位小于2
	{
	  n->cnt--;//位数减少
	  carry=1;//次高位得1(1*10) 
    }
	for(i=n->cnt-1;i>=0;i--)
	{   int t=carry*10+n->v[i];//此位的计算值 
		n->v[i]=t/2;
		carry=t%2;//carry要么1要么0 
	}
}

void  MUL2ADD(BIGINT*n,int d)
{
	int carry=d,i;
	for (i=0;i<n->cnt;i++) {
		int t=carry+n->v[i]*2;
		n->v[i]=t%10;
		carry=t/10;
	}
	if (carry>0) n->v[n->cnt++]=carry;

}








int main()
{   int k,T;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {  char line[102]={'\0'};
 	scanf("%s",line);
 	printf("case #%d:\n",k);
 	BIGINT n;
 	n.cnt=strlen(line);
 	int i;
 	for(i=0;i<n.cnt;i++)
 		n.v[i]=line[n.cnt-1-i]-'0';
 	int s[334]={0},cnt=0;
 	while(n.cnt>0)//十进制转二进制 
 	{
 		s[cnt++]=n.v[0]%2;//直接顺序加就已经是倒转的二进制了 
 		DIV2(&n); //BIGINT除以2 
	 }
 	for (i=0;i<cnt;i++) MUL2ADD(&n,s[i]);//二转十 
 	if(n.cnt==0) n.cnt++;
 	for(i=n.cnt-1;i>=0;i--) printf("%d",n.v[i]); 
 	printf("\n");
 }
	return 0;
}