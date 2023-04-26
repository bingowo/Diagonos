#include<stdio.h>
#include<string.h>
int result(int m,int n){//计算最简分数 （m为分母）
	int a = m;
    int b = n;
    while(a % b)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    m /= b;
    n /= b;						
   	printf("%d",n);
   	printf("/");
   	printf("%d",m);
}
int main()
{
	int n;
	scanf("%d",&n);
	long long fz=0,fm=1;
	for(int i=0;i<n;i++)
	{
		int z=0,m=0;
		char s[100]={0};
		scanf("%s",s);
		int t=0;
		while(s[t]!='/')
		{
			z*=10;
			z+=(s[t]-'0');
			t++;
		}
		t++;
		while(s[t]!='\0')
		{
			m*=10;
			m+=(s[t]-'0');
			t++;
		}
		fz=fz*m+z*fm;
		fm=fm*m;
	}
	result(fm,fz);
}