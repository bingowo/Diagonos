#include<stdio.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	char c;
	scanf("%c",&c);
	for(int i=0;i<T;i++){
		char s[55];
		int cnt=0;
		while(scanf("%c",&s[cnt])!=-1&&s[cnt]!='\n')
		cnt++;
		double sum=0.0;
		for(int j=2;j<cnt;j++){
			sum+=(s[j]-'0')*pow(0.125,j-1);
		}
		printf("case #%d:\n",i);
		printf("%.45g\n",sum);
	}
	return 0;
}