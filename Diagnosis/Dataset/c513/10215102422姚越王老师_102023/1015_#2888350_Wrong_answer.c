#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void get_prime(const void* a)
{
	int* prime=(int*)a;
	int cnt=2;
	prime[0]=2;prime[1]=3;
	for(int i=5;cnt<26;i+=2)
	{
		int flag=1;
		for(int j=3;j<i;j+=2)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)prime[cnt++]=i;
	}
}
int main()
{
	int n;scanf("%d",&n);
	int prime[26];
	get_prime(prime);
	for(int cnt=0;cnt<n;cnt++)
	{
		char a[1005],b[1005];
		scanf("%s%s",a,b);
		int digit=1;
		for(int i=0;i<strlen(a);i++)
			if(a[i]==',')digit++;
		int ans[digit+1];for(int i=0;i<digit+1;i++)ans[i]=0;
		int pa_begin=strlen(a)-1,pb_begin=strlen(b)-1;
		int carry=0,i,j;
		for(i=digit,j=0;i>0;i--,j++)
		{
			for(pa_begin;pa_begin>=1;pa_begin--)if(a[pa_begin]==',')break;
			for(pb_begin;pb_begin>=1;pb_begin--)if(b[pb_begin]==',')break;
			char a_number[1005],b_number[1005];
			char *pa=a+pa_begin+1,*pb=b+pb_begin;
			strcpy(a_number,pa);strcpy(b_number,pb);
			int ia=atoi(a_number),ib=atoi(b_number);
			ans[i]=ia+ib+carry;
			if(ans[i]>=prime[j]){ans[i]%=prime[j];carry=1;}
			else carry=0;
			if(pa_begin==0)break;
			else {a[pa_begin]=0;b[pb_begin]=0;}
		}
		ans[--i]=carry;
		printf("case #%d:\n",cnt);
		if(ans[i]==0)
		{
			for(++i;i<digit;i++)
			{
				if(i!=digit)printf("%d,",ans[i]);
				else printf("%d\n",ans[i]);
			}
		}
		else
		{
			for(i;i<digit;i++)
			{
				if(i!=digit)printf("%d,",ans[i]);
				else printf("%d\n",ans[i]);
			}
		}
	}
	return 0;
}
