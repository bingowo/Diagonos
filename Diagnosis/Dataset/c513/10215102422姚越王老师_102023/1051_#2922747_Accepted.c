#include<stdio.h>
#include<string.h>
int pow(int a,int b)
{
	int ans=1;
	while(b--)ans*=a;
	return ans;
}
int b2i(const int* b)
{
	int ans=0;
	for(int i=5;i>=0;i--)
		ans+=b[i]*pow(2,5-i);
	return ans;
}
void print(int tmp)
{
	if(tmp>=0&&tmp<=25)printf("%c",tmp+65);
	else if(tmp>=26&&tmp<=51)printf("%c",tmp+71);
	else if(tmp>=52&&tmp<=61)printf("%d",tmp-52);
	else if(tmp==62)printf("+");
	else printf("/");
}
int main()
{
	int T;scanf("%d\n",&T);
	int i,j,k,len;
	char s[110];
	for(i=0;i<T;i++)
	{
		gets(s);
		len=8*strlen(s);
		while(len%6)len++;
		int n=len/6,flag=0;
		if(n%4)flag=(n/4)*4+4-n;
		int a[len];
		for(j=0;j<len;j++)a[j]=0;
		k=0;
		for(j=0;j<strlen(s);j++)
		{
			int c=(int)s[j];
			//printf("c=%d ",c);
			int cnt=0,t=1;
			t<<=7;
			while(cnt<8)
			{
				if(c&t)a[k++]=1;
				else a[k++]=0;
				t>>=1;
				cnt++;
			}
		}
		//for(j=0;j<len;j++)printf("%d",a[j]);
		//printf("\n");
		
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)
		{
			int b[6],q=0;
			for(k=j*6;k<j*6+6;k++)b[q++]=a[k];
			int tmp=b2i(b);
			print(tmp);
		}
		if(flag)while(flag--)printf("=");
		printf("\n");
	}
	return 0;
}