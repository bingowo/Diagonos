#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 7000

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
void BIG2char(BIGINT*A,char*s)
{  int i,j=0;
	for(i=A->cnt-1;i>=0;i--) s[j++]=A->v[i]+'0';
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
	for(i=A->cnt-1;A->v[i]==0&&i>=0;i--);
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
{ char s[2000]={'\0'};
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
	 int signr=1,signi=1;
	 if(!(qr==0)) signr=qr/(abs(qr));
	 if(!(qi==0)) signi=qi/(abs(qi));
	  qr=abs(qr),qi=abs(qi);
	  int SR=signr,SI=signi,sign1=1,sign2=1,sign3=signr,sign4=signi,sign5=1,sign6=1;
	BIGINT QR=int2BIG(qr),QI=int2BIG(qi),R=QR,I=QI,F1={0,{0}},F2={0,{0}},aa={0,{0}},bb={0,{0}},cc=QR,dd=QI;//************************* 
		int i;
		for(i=1;i<n;i++) 
		{	char s1[max]={'\0'};char s2[max]={'\0'};char s3[max]={'\0'};char s4[max]={'\0'};
		
			//********************处理实部 (si1*si3*a*c-si2*si4*b*d)
	
			sign1=SR,sign2=SI;
			sign5=sign1*sign3,sign6=(-1)*sign2*sign4;
			aa=R,bb=I;
			F1=mul(aa,cc),F2=mul(bb,dd);
			BIG2char(&F1,s1);BIG2char(&F2,s2);
			if(sign5==1&&sign6==1) AaddB(&F1,&F2),R=F1,SR=1;
			
			else if(sign5==1&&sign6==-1)
			{ if(strcmp(s1,s2)>0) SR=1,A_B(&F1,&F2),R=F1;
			else if(strcmp(s1,s2)<0) SR=-1,A_B(&F2,&F1),R=F2;
			else if(strcmp(s1,s2)==0) 
				{SR=1,R.cnt=1;
				int j;
				for(j=0;j<max;j++) R.v[j]=0;
				}
			}
			
			else if(sign5==-1&&sign6==1)
			{ if(strcmp(s1,s2)>0) SR=-1,A_B(&F1,&F2),R=F1;
			else if(strcmp(s1,s2)<0) SR=1,A_B(&F2,&F1),R=F2;
			else if(strcmp(s1,s2)==0) 
				{SR=1,R.cnt=1;
				int j;
				for(j=0;j<max;j++) R.v[j]=0;
				}
			}
			
			else if(sign5==-1&&sign6==-1)
			{
				AaddB(&F1,&F2),R=F1,SR=-1;
			}
		
			//******************** 处理实部 
			 
			//********************处理虚部(si2*si3*b*c+si1*si4*a*d)i
			
			sign5=sign2*sign3,sign6=sign1*sign4;
			F1=mul(bb,cc),F2=mul(aa,dd);
			BIG2char(&F1,s3);BIG2char(&F2,s4);
			if(sign5==1&&sign6==1) AaddB(&F1,&F2),I=F1,SI=1;
			
			else if(sign5==1&&sign6==-1)
			{ if(strcmp(s3,s4)>0) SI=1,A_B(&F1,&F2),I=F1;
			else if(strcmp(s3,s4)<0) SI=-1,A_B(&F2,&F1),I=F2;
			else if(strcmp(s3,s4)==0) 
				{SI=1,I.cnt=1;
				int j;
				for(j=0;j<max;j++) I.v[j]=0;
				}
			}
			
			else if(sign5==-1&&sign6==1)
			{ if(strcmp(s3,s4)>0) SI=-1,A_B(&F1,&F2),I=F1;
			else if(strcmp(s3,s4)<0) SI=1,A_B(&F2,&F1),I=F2;
			else if(strcmp(s3,s4)==0) 
				{SI=1,I.cnt=1;
				int j;
				for(j=0;j<max;j++) I.v[j]=0;
				}
			}
			
			else if(sign5==-1&&sign6==-1)
			{
				AaddB(&F1,&F2),I=F1,SI=-1;
			}
		
			//********************处理虚部
		 } 
		 
		int flagr=-1,flagi=-1;
		for(i=0;i<R.cnt;i++)
		{	if(R.v[i]!=0) break;
		}
		if(i<R.cnt) flagr=1;
		 
		 for(i=0;i<I.cnt;i++)
		{	if(I.v[i]!=0) break;
		}
		if(i<I.cnt) flagi=1;
		
		if(n==0) printf("1");
		else
	{
		
		if(R.cnt==0&&I.cnt==0) printf("0");
		int flag=-1;
		if(flagr==1&&SR==1&&!(R.cnt==0||R.cnt==1&&R.v[0]==0))
		{	flag=1;
			for(i=R.cnt-1;i>=0;i--) printf("%d",R.v[i]);
		}
		 
		if(flagr==1&&SR==-1&&!(R.cnt==0||R.cnt==1&&R.v[0]==0))
		 { putchar('-');
		 	flag=1;
		 	for(i=R.cnt-1;i>=0;i--) printf("%d",R.v[i]);
		 }
		 
		if(flagi==1&&SI==1&&!(I.cnt==0||I.cnt==1&&I.v[0]==0))
		{	if(flag==1) printf("+");
			if(!(I.cnt==1&&I.v[0]==1))
			{for(i=I.cnt-1;i>=0;i--) printf("%d",I.v[i]);}
			putchar('i');
		}

		if(flagi==1&&SI==-1&&!(I.cnt==0||I.cnt==1&&I.v[0]==0))
		{	putchar('-');
			if(!(I.cnt==1&&I.v[0]==1))
			{for(i=I.cnt-1;i>=0;i--) printf("%d",I.v[i]);}
			putchar('i');
		}
	} 
	return 0;
} 