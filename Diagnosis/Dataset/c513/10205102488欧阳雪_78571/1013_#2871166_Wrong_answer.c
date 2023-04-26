#include<stdio.h>
#include<string.h>
#include<math.h>
int d[3]={0}; 
int Gcd(int m,int n)//求分子分母最大公约数 
{
	if(n==0)return m;
	return Gcd(n,m%n);
}
int huajian(int a,int b,int c)//分子，分母，整数 
{
	int flag=1;
	if(a<0){
		a=-a;
		flag=-1;
	}
	int t=Gcd(a,b);
	a= a/t;
	b= b/t;
	if(a>b){
		if(flag==1){
			if(c>0)
			{
				c=c+a/b;
				a=a%b;
			}
			if(c<0)
			{
			    c=c+a/b+1;
				a=b-a%b;	
			}
		}
		if(flag==-1){
				c=c-a/b-1;
			    a=(b-a%b);
		}
	}
	if(a<b)
	{
		if(c<0)
		{
			c=c+1;
			a=b-a;
		}
		if(flag==-1){
			c=c-1;
			a=b-a;
		}
    }
	d[0]=a,d[1]=b,d[2]=c;	
}
struct data{
	int num;
	int flg;
};
int main()
{
	char s[1000]={0};
	struct data a[1000];
	scanf("%s",s);
	int i=0,j=0;
	long long int ans1=0;
	int len1=0,len2=0; 
	while(s[i]!='.'&&s[i]!='\0')
	{
		len1++;
		i++;
	}
	i++;
	//printf("%d %d\n",len1,i);
	while(s[i]!='\0')
	{
		len2++;
		i++;
	}
	i=0;
	if(len1==1&&len2==0&&s[0]=='0'){
		printf("0");
		return 0;
	}
	while(s[i]!='.'&&s[i]!='\0')//计算整数部分 
	{
		if(s[i]=='1'){
			ans1=ans1+pow(3,len1-1);
		}
		if(s[i]=='2'){
			ans1=ans1-pow(3,len1-1);
		}
		len1--;
		i++;
	}
	i++;
	//printf("整数部分：%d\n",ans1);
	int t=1;
	while(s[i]!='\0')//计算小数部分 
	{
		if(s[i]=='1'){
			a[j].num=pow(3,t);//存储分母 
			a[j].flg=1;
			//printf("%d %d\n",j,a[j].num );
		}
		if(s[i]=='2'){
			a[j].num =pow(3,t);
			a[j].flg =-1;
		}
		if(s[j]=='0'){
			a[j].num=0;
			a[j].flg=0;
		}
		i++;
		j++;
		t++;
	}
	j=0,i=0;
	int fenzi=0,fenmu=0,k=0,t1=0;
	int fz[100];
	for(int j1=0;j1<100;j1++)fz[j1]=1;
	if(len2>0)//有小数部分 
	{
	fenmu=1,fenzi=0;
	if(len2==1){
		fenmu=fenmu*a[j].num;
		fenzi=a[i].flg; 
	}
	else{
	for(k=0;k<len2;k++)
	{
		if(a[j].num!=0)
		{
		fenmu=fenmu*a[j].num;
		for(i=0;i<len2;i++)
		{
			if(i!=k&&a[i].num!=0)
			{
				fz[t1]=fz[t1]*a[i].num*a[i].flg;
			}
		}
		}
		if(a[j].num==0){
			fz[t1]=0;
		}
		//printf("fz:%d\n",fz[t1]);
		j++,t1++;
	}
	for(j=0;j<t1;j++)
	{
		fenzi=fenzi+fz[j];
	}
	//printf("fenzi:%d\n",fenzi);
	if(fenzi!=1){
		huajian(fenzi,fenmu,ans1);
	}
	fenzi=d[0],fenmu=d[1],ans1=d[2];
	}
//	printf("分子，分母：%d %d\n",fenzi,fenmu);
}
	if(fenzi!=0&&fenmu!=0)
	{
		if(ans1!=0)printf("%lld ",ans1);//输出整数部分
		printf("%d %d",fenzi,fenmu); 
	}
	else{
		if(ans1!=0)printf("%lld",ans1);
	}
	
 } 