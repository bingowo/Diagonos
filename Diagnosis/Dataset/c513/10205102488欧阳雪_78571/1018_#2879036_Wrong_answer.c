#include<stdio.h>
#include<math.h>
int prime(int n)
{
	int i=0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void sushu(int *a){//计算1-100内的素数 ,25个 
	int i=0,k=0,j=1;
	for(i=2;i<100;i++)
	{
		if(prime(i)){
			k++;
			a[j]=i;
			j++;
		}
	}
}
int main()
{
	int a[100];
	for(int t=0;t<100;t++)a[t]=1;
	sushu(a);
	char s[50]={'\0'};
	char c;
	int b[50]={0};
	long long ans=0;
	int j=0,count=0;
	while((c=getchar())!='\n')//输入 
	{
		if(c==','){
			continue;
		}
		int temp=0;
		while(c!=','&&c!='\n')
		{
			temp*=10;
			temp+=(c-'0');
			c=getchar();
			if(c=='\n')goto FLAG1;
		}
		FLAG1:
			b[j++]=temp;
			//printf("b[]:%d %d\n",j-1,b[j-1]);
		if(c=='\n'){
			goto FLAG2;
		}
	}
	FLAG2://进制转换 
		count=j;
		int k=0;
		j--;
		for(int i=0;i<count;i++)
		{
			long long int tep=1;
			for(k=0;k<=i;k++)//计算位权 
			{
				tep*=a[k];
				//printf("a[]:%d %d\n",k,a[k]);
			}
			//printf("tep:%d %lld\n",i,tep);
			ans+=tep*b[j];
			j--;
		}
		printf("%lld",ans);
}