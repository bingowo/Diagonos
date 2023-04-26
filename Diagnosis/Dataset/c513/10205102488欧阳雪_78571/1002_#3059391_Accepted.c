#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void RToTen(int*x,int p,int len){
	long long int y=0,product=1;
	int i=0;
	while(len>=0){
		///y=y+(x%10)*product;
		y=y+x[len]*product;
		len--;
	//	x=x/10;
		product=product*p;
	}
	printf("%lld\n",y);
} 

int main()
{
	int T;
	scanf("%d",&T);
	for(int z=0;z<T;z++)
	{
		char s[100]={0};
		scanf("%s",s);
		int flg[200]={0};//找不同字符数
		int j=0,k=0,i=0;
		for(j=0;j<strlen(s);j++)
		{
			flg[s[j]]++;
		}
		for(j=0;j<200;j++)
		{
			if(flg[j]>0)
			{
				k++;
			}
		}
	//	printf("k:%d\n",k);
		int a[200]={0};
		//memset(a,-1,200);
		for(i=0;i<200;i++)
		{
			a[i]=-1;
		}
		a[s[0]]=1;
		i=1;
		while(a[s[i]]!=-1&&s[i]!='\0')
		{
			i++;
		}
		a[s[i]]=0;
		i++;
		int t=2;
		while(s[i]!='\0')
		{
			while(a[s[i]]!=-1&&s[i]!='\0')
			{
				i++;
			}
			a[s[i]]=t;
			t++;
			i++;
		}
		int ans[100]={0};
	//	printf("ans:");
		for(i=0;i<strlen(s);i++)
		{
			ans[i]=a[s[i]];
		//	printf("%d",ans[i]);
		}
	//	printf("\n");
	    if(k<2){
	    	k=2;
		}
		printf("case #%d:\n",z);
		RToTen(ans,k,strlen(s)-1);
	}
}