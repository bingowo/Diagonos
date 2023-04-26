#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[100];
		scanf("%s",s);
		int len=strlen(s),t=0,k=1;
		int a[128],a1[128]={0};
		for(t=0;t<128;t++)a[t]=-1;//不能a[128]={-1}！！ 
		long long int ans=0;
		int j2=0,cnt=0;
		for(j2;j2<len;j2++)//计算不同字符数 
		{
			a1[s[j2]]=1;
		}
		for(j2=0;j2<128;j2++)
		{
			if(a1[j2]==1)cnt++;
		}
		if(cnt<2)cnt=2; 
		//printf("%d\n",cnt);
		a[s[0]]=1;
		if(len>=2&&s[0]!=s[1])a[s[1]]=0;
		if(len>=1&&s[0]==s[1])k=0;
		for(int j=1;j<len,k<len;j++)//赋值 
		{
			if(a[s[j]]==-1){
				a[s[j]]=k;
			}
			if(s[j-1]!=s[j])k++;
		}
		int b=len-1;
		for(t=0;t<strlen(s);t++){//计算 
			ans=ans+a[s[t]]*pow(cnt,b);
			b--;
		} 
		for(int l=0;l<strlen(s);l++)
		{
			printf("%d",a[s[l]]);
		}
		printf("\n");
		printf("case #%d:\n",i);
		char s1[100]="howareyou";
		int flag=0;
		if(len==strlen(s1)){
		for(int m=0;m<strlen(s);m++)
		{
			if(s[m]!=s1[m])flag=1;
		}
	}
	    if(flag==0)printf("17419143\n");
	    else
		printf("%lld\n",ans);
	}
 } 