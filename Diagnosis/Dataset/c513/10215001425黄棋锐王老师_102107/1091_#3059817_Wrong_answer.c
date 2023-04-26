#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000 

typedef struct
{
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

BIGINT int2BIG(int x)//把int转换成BIGINT 
{
	BIGINT R={0,{0}};
	do
	{
		R.v[R.cnt++]=x%10;
		x/=10;
	 } while(x>0);
	 return R;
}
BIGINT mul(BIGINT S,BIGINT T)//大整数相乘, S.v[i]*T.v[j]->R.v[i+j] ,  R.v[i+j]上大于10进1 
{   
	BIGINT R={S.cnt+T.cnt,{0}};//有效位数至多为S.cnt+T.cnt个    如千百十个4位，十个2位
	int i,j,k,t;
	for(i=0;i<T.cnt;i++)
	{
		int carry=0;
		for(j=0;j<S.cnt;j++)
		{
			t=T.v[i]*S.v[j]+carry+R.v[i+j];//R.V[i+j]的计算值 
			R.v[i+j]=t%10;//有效十进制数 
			carry=t/10;//进位数 
		}
		k=i+j;//此次计算最高位 k
		while(carry>0)//看R.v[k]是否需要进位,算到无法进位为止
		{
			t=R.v[k]+carry;//计算值
			R.v[k]=t%10;
			carry=t/10;
			k++;//下一步算R.v[k+1] 
		} 
	}
	if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;//最高位为0时不计入有效位数 
	return R;
}
BIGINT POW(BIGINT a,int n)//计算a的n次方，二分法 
{
	BIGINT r;
	if(n==0) return int2BIG(1);
	if(n==1) return a;
	r=POW(a,n/2);
	r=mul(r,r);
	if(n%2!=0) r=mul(r,a);// 奇数时前两步会少乘一个次方；
	return r; 
}

void A_B(BIGINT*A,BIGINT*B)//A-B
{   int carry=0,i=0;
	for(i=0;i<A->cnt;i++)
	{   A->v[i]-=carry;
		if(A->v[i]<B->v[i]) 
		{
		carry=1;
		A->v[i]=A->v[i]+10-B->v[i];
		}
		else {
			carry=0;
			A->v[i]=A->v[i]-B->v[i];
		}
	}
	for(i=A->cnt-1;A->v[i]==0;i--);
	A->cnt=i+1;
}


void AaddB(BIGINT*A,BIGINT*B)//A+B
{   int carry=0,i=0,de=(A->cnt>B->cnt)?A->cnt:B->cnt;
	for(i=0;i<de;i++)
	{   
		int t=A->v[i]+B->v[i]+carry;
		A->v[i]=t%10;
		carry=t/10;
	}
	while(carry>0)
	{	int t=A->v[i]+carry;
		A->v[i]=t%10;
		carry=t/10;
		i++;
	}
	if(i>A->cnt) A->cnt=i;
}
int main() 
{ char s[200]={'\0'};
	int n;
	scanf("%s %d",s,&n);//a+bi,n
	char*p;//******************************处理输入问题 
	 int qr,qi,d=0;//d判断输入中的a是否存在 
	 if(strchr(s,'i')==NULL) qr=atoi(s),qi=0; // 只有a 
	 else if(s[0]=='i') qr=0,qi=1;//只有i 
	 else if(strchr(s,'i')&&s[0]!='i'&&strchr(s,'+')==NULL&&strchr(s,'-')==NULL)
	 {//只有bi, b为自然数 
	 	p=strchr(s,'i');
	 	*p='\0';
	 	qr=0,qi=atoi(s);
	 } 
	 else if(strchr(s,'i')&&s[0]!='i')
	 {//a+bi和a-bi 
	 	p=strchr(s,'i');
	 	*p='\0';
	 	p=p-1;
	 	int j=strlen(s)-1,l;
	 	l=j;
		 for(;*p!='+'&&*p!='-'&&j!=-1;j--,p--);
	 	if(*p=='+'&&j==l) d=1,qi=1;//a+i 
	 	else if(*p=='-'&&j==l&&j>0) d=1, qi=-1;//a-i 
	 	else if(*p=='-'&&j==l&&j==0) qr=0, qi=-1; //-i
	 	else if(j==-1) qr=0,qi=atoi(s);//bi
	 	else if(*p=='-'&&j<l&&j==0) qr=0,qi=atoi(s);//-bi
	 	else if(*p=='-'&&j<l&&j>0) d=1,qi=atoi(p);//a-bi
	 	else if(*p=='+'&&j<l) {
	 		d=1;qi=atoi(p);//a+bi
		 }
		 else if(j==-1&&l>0) qr=0,qi=atoi(p+1);//bi 
		 if(d=1) 
		 {
	 		*p='\0';
	 		qr=atoi(s);
	 	 }
	 }
	 int signr=qr/(abs(qr)),signi=qi/(abs(qi));
	  qr=abs(qr),qi=abs(qi);
		BIGINT QR=int2BIG(qr),QI=int2BIG(qi);//************************* 
		AaddB(&QR,&QI);
		printf("%d\n",QR.cnt);
		int k;
		for(k=QR.cnt-1;k>=0;k--)
		{	
			printf("%d",QR.v[k]);
		}
	 
	 
	 
	return 0;
}