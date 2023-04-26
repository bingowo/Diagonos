#include <stdio.h>
#include <stdlib.h>
int b[101][100001]={0};
int cmp(const void *a,const void *b)
{
	int *A=(int *)a;
	int *B=(int *)b;
	return *B-*A;
	
}
int main()
{
    int n,d,y=0,res=0;
    char a[101];
	long long int ans=0;
	char s[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
		scanf("%s",s);
		a[0]=s[0];
		d=0;b[0][i]=1;
		for(int j=1;s[j]!='\0';j++)
		{
			if(s[j]==a[d]) b[d][i]++;
			else 
			{
				if(i!=0&&s[j]!=a[d+1]) {y=1;break;}
				else {d++;a[d]=s[j];b[d][i]++;}
			}
		}
		if(i==0) res=d;
		else 
		{
			if(d!=res) {y=1;break;}
		}
	}
	if(y==1) {printf("-1");}
	else
	{
		for(int i=0;i<=d;i++)
		{
			int c;
			qsort(b[i],n,sizeof(b[i][0]),cmp);
			c=b[i][n/2];
			for(int j=0;j<n;j++)
			{
				ans+=abs(b[i][j]-c);
			}
		}
		printf("%lld",ans);

	}
}