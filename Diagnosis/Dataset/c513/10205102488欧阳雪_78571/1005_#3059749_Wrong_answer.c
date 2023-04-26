#include<stdio.h>
#include<string.h>
#define M 301 
int div(int*a,long long int fz,long long int fm,int n)
{

	int i=M-3*n;
	for(i;i<M;i++)
	{
		fz=fz*10;
		a[i]=fz/fm;
		if(fz%fm==0)
		{
			break;
		}
		fz=fz%fm;
	}
	
}
int add(int*ans,int*a,int n)
{
	int jin=0;
	for(int i=M-1;i>=M-3*n;i--)//暂时不考虑整数 
	{
		int temp=0;
		temp=ans[i];
		ans[i]=(temp+a[i]+jin)%10;
	    jin=(temp+a[i])/10;
	//	printf("jin:%d\n",jin);
    }
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[100]={0};
		scanf("%s",s);
		int j=2;
		int n=0;//小数位数
		while(s[j]!='\0')
		{
			n++;
			j++;
		} 
		j=2;
		//printf("n:%d\n",n);
		int ans[M]={0};
		int k=1,t;
		while(s[j]!='\0')
		{
			int a[M]={0};
			long long int fm=1;
			for(t=0;t<k;t++)
		    {
		     	fm*=8;
			}
			div(a,(s[j]-'0'),fm,n);
			
			int z=0;
		/*	for(z=M-3*n;z<M;z++)
			{
				printf("%d",a[z]);
			}
			printf("\n");*/
			
			add(ans,a,n);
			
		/*	printf("ans:");
			for(z=M-3*n;z<M;z++)
			{
				printf("%d",ans[z]);
			}
			printf("\n");*/
			j++;
			k++;
		}
		t=M-1;
		while(ans[t]==0)
		{
			t--;
		}
		printf("case #%d:\n",i);
		printf("0.");//整数部分??? 
		for(j=M-3*n;j<=t;j++)
		{
			printf("%d",ans[j]);
		}
		printf("\n");
		
	}
}