#include<stdio.h>
#include<string.h>
#include<math.h>
int fenmu=0,fenzi=0;
int Gcd(int m,int n)//求分子分母最大公约数 
{
	if(n==0)return m;
	return Gcd(n,m%n);
}
int huajian(int &a,int &b,int &c)//分子，分母，整数 
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
	int i=0,j=0,ans=0,ans1=0,ans2=0;
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
	int t=1;
	while(s[i]!='\0')//计算小数部分 
	{
		if(s[i]=='1'){
			a[j].num=pow(3,t);//存储分母 
			a[j].flg=1;
		}
		if(s[i]=='2'){
			a[j].num =pow(3,t);
			a[j].flg =-1;
		}
		i++;
		j++;
		t++;
	}
	//printf("%d %d\n",a[0].num ,a[0].flg ); 
	j=0,i=0;
	int k=0,t1=0;
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
		fenmu=fenmu*a[j].num;
		for(i=0;i<len2;i++)
		{
			if(i!=k)
			{
				fz[t1]=fz[t1]*a[i].num*a[i].flg;
			}
		}
		//printf("%d\n",fz[t1]);
		j++,t1++;
	}
	//printf("%d %d\n",fz[0],fz[1]);
	for(j=0;j<t1;j++)
	{
		fenzi=fenzi+fz[j];
	}
	huajian(fenzi,fenmu,ans1);
	}
//	printf("分子，分母：%d %d\n",fenzi,fenmu);
}
	if(fenzi!=0&&fenmu!=0)
	{
		if(ans1!=0)printf("%d ",ans1);//输出整数部分
		printf("%d %d",fenzi,fenmu); 
	}
	else{
		if(ans1!=0)printf("%d",ans1);
	}
	
 } 