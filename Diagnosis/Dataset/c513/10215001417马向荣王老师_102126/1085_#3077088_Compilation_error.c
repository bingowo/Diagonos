

#define max 8000

typedef struct
{	int sign;//符号 
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

BIGINT int2BIG(int x)//把int转换成BIGINT 
{
	BIGINT R={1,0,{0}};
	do
	{
		R.v[R.cnt++]=x%10;
		x/=10;
	 } while(x>0);
	 return R;
}

BIGINT s2BIG(char*s)//字符串转换为BIGINT 
{  int i,l=strlen(s);
	BIGINT R={1,0,{0}};
	for(i=l-1;i>=0;i--)
	{
		R.v[R.cnt++]=s[i]-'0';	
	}
	return R;
}

void BIG2s(char*s,BIGINT R)//BIGINT 转换为字符串 
{	int i,j=0;
	for(i=R.cnt-1;i>=0;i--)
	  s[j++]=R.v[i]+'0';
}

int BIGcmp(BIGINT A,BIGINT B)//BIGINT 绝对值大小比较 
{ 	char a[8000]={'\0'};
	char b[8000]={'\0'};
	BIG2s(a,A);BIG2s(b,B);
	int la=strlen(a),lb=strlen(b),i;
	if(la>lb) return 1;
	else if(la<lb) return -1;
	else if(la==lb)
	{
	    for(i=0;i<la;i++)
	    {
	    	if(a[i]>b[i]) return 1;
	    	else if(a[i]<b[i]) return -1;
		}
		if(i==la) return 0;
	}  
}


BIGINT A_B(BIGINT A,BIGINT B)//A-B, A>B 
{   int carry=0,i=0;
	BIGINT R;
	for(i=0;i<A.cnt;i++)
	{   A.v[i]-=carry;
		if(A.v[i]<B.v[i]) 
		{
		carry=1;
		A.v[i]=A.v[i]+10-B.v[i];
		}
		else {
			carry=0;
			A.v[i]=A.v[i]-B.v[i];
		}
	}
	for(i=A.cnt-1;A.v[i]==0&&i>=0;i--);
	A.cnt=i+1;
	R=A;
	return R;
}


BIGINT AaddB(BIGINT A,BIGINT B)//A+B,A,B为正整数 
{   int carry=0,i=0,de=(A.cnt>B.cnt)?A.cnt:B.cnt;
	BIGINT R;
	for(i=0;i<de;i++)
	{   
		int t=A.v[i]+B.v[i]+carry;
		A.v[i]=t%10;
		carry=t/10;
	}
	while(carry>0)
	{	int t=A.v[i]+carry;
		A.v[i]=t%10;
		carry=t/10;
		i++;
	}
	if(i>A.cnt) A.cnt=i;
	R=A;
	return R;
}


BIGINT AJIAB(BIGINT qr,BIGINT qi)////处理A+B，带符号处理 
{	BIGINT f1={1,0,{0}};
	if(qr.sign==qi.sign)
		{f1=AaddB(qr,qi);
			if(qr.sign==1) f1.sign=1;
			else f1.sign=-1;
		}
		else//qr,qi异号 
		{ int flag=BIGcmp(qr,qi);
		if(qr.sign==1&&flag==1)//qr>0,qr+qi>0
			{  	f1=A_B(qr,qi);
				f1.sign=1; 
			}
		else if(qr.sign==1&&flag==-1)//qr>0,qr+qi<0
			{  	f1=A_B(qi,qr);
				f1.sign=-1; 
			}
		else if(qr.sign==-1&&flag==1)//qr<0,qr+qi<0
			{  	f1=A_B(qr,qi);
				f1.sign=-1; 
			}
		else if(qr.sign==-1&&flag==-1)//qr<0,qr+qi>0
			{  	f1=A_B(qi,qr);
				f1.sign=1; 
			}
		else if(flag==0) 
			{ f1.sign=1;f1.cnt=0;f1.v[0]=0;}//***	
		}
		
	return f1;
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

********************************
char s[8000]={'\0'};
	scanf("%s",s);
	char*p=s;
	p+=2;
	char x[8000]={'\0'};
	int j=0;
	while(*p)
	{  x[j++]=*p;
		p++;
	}
	//******x记录十六进制数 
	char er[8000]={'\0'};
	int k=0,i;
	for(i=0;i<strlen(x);i++)
	{  int d=0;//记录十六进制数的十进制数 
		unsigned int flag=8;//二进制的1000
		 if(x[i]>='A') d=x[i]+10-'A';
		 else d=x[i]-'0';
		 while(flag)// 十六进制转二进制,转换后二进制为倒序，k记录有效位数 
		 {
		 	if(d&flag) er[k++]='1';
		 	else er[k++]='0';
		 	flag>>=1;//1000>>0100>>0010>>0001
		 }
	}
***************************************************** 



	do
 { 	char xi[100]={'\0'};
 	int sign=1;//记录符号
 	
 	if(s[i]=='+') sign=1,i++;
 	else if(s[i]=='-') sign=-1,i++;//处理符号，可有可无，'+','-',或无符号 
 	
 	
 	for(j=0;i<l&&'0'<=s[i]&&s[i]<='9';i++) xi[j++]=s[i];//记录数值 
	int val=1;
	if(strlen(xi)>0) val=atoi(xi);
	
 	if(s[i]=='x')
	 {	
	 	if(i+1<l&&s[i+1]=='^')
	 	{	i=i+2;
	 		if(s[i]=='3') fx.c3=val*sign;
	 		else if(s[i]=='2') fx.c2=val*sign;
		 }
		 
	 	else fx.c1=val*sign;
	 	i++;//key
	 }
	 
 	else fx.c0=val*sign;//常数项 
	  
 }while(i<l);
    //*********************读入f(x) 

进位转制 
void itob(int N,int R,char*s){
	int sign=1,i=0,j=0,a=0;
	 if(N<0) N=-N,sign=-1;
	 while(N>0)
	 {
	 	a=N%R;
	 	if(0<=a&&a<=9) s[i]='0'+a;
		  
	 	else if(10<=a&&a<=35) {
	 		s[i]='A'+a-10;
		 }
		 N=N/R;
	 		 i++;
	 }
	 if(sign==-1) s[i++]='-';
	 s[i]='\0';
	 //for(j=i-1;j>=0;j--) printf("%c",s[j]);
}