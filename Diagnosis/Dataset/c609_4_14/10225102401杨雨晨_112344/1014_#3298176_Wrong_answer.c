#include <stdio.h>
#include <math.h>
int Caculate(int x){return x%3==2?x/3+1:x/3;}

int main(){
	int a,b,i,j,m,n;
	int mark;
	double p;
	int num[100];
	mark=0;m=a%b;
	n=1;p=0;
	scanf("%d %d",&a,&b);//输入两个数，整数 用空格分开
	while (b!=n){
		p++;n*=3;
	}//求对数 
	if (m==0){a=a/b;}//求最简值 
	for (i=0;Caculate(a);i++){
		num[i]=a%3;
		a=Caculate(a);
	}//把反向的三进制储存进数组 
	num[i]=a;//最后还剩一个 
	if (a==0)printf("%c",'0');//a是零的特殊情况 
	else {if(p<i+1){//是有整数部分的情况 
	for (j=i;j>=0;j--)
	{if (j==0&&(mark==-1&&num[j]==0)){break;}//小数的最后一位是零要省略 
	printf("%d",num[j]);
	if (j==p&&m!=0){printf("%c",'.');mark=-1;}}}//打印小数点，顺便标记一下这个东西有小数点 
	else {if(a/b!=1)printf("%c%c",'0','.');//没有整数部分 
	for (j=0;j<p-i-1;j++){printf("%c",'0');}
	for (j=i;j>=0;j--){printf("%d",num[i]);	}}}
	
	return 0;

}