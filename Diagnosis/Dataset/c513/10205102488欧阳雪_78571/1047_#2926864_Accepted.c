#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[1000]={0};
		char ans[1000]={0};
		scanf("%s",s);
		int j1=0,j2=0,cnt=1;
		char c;
		while(s[j1])
		{
			while(s[j1]==s[j1+1]&&cnt<255)
			{
				c=s[j1];
				j1++;
				cnt++;
			}
			//printf("cnt:%d\n",cnt);
				int temp=cnt;
				int a[4]={0},k=0;
				while(temp){
					a[k]=temp%10;
				//	printf("a[]:%d %d\n",k,a[k]);
					temp/=10;
					k++;
				}
				k--;
				//printf("k:%d\n",k);
				while(k>=0)
				{
					//printf("a[k]:%d ",a[k]);
					ans[j2++]=a[k]+'0';
					//printf("ans[]:%d %c\n",j2-1,ans[j2-1]);
					k--;
				}
				if(cnt>1)
				{
					ans[j2++]=c;
				}
				else ans[j2++]=s[j1];
			cnt=1;
			j1++;
	     }
		printf("case #%d:\n",i);
		printf("%s\n",ans);
	}
}