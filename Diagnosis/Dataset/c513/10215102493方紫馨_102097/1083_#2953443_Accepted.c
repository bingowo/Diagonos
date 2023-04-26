#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	int num[201]; 
	int cnt=1,a;
	for(int i=1;i<201;i++){
		cnt=1;
		a=i;
		while(a%5==0){
			cnt++;
			a /=5;
		}
		num[i]=cnt;		
	}
	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		int ret=0;
		n/=5;
		for(int j=1;j<=n;j++){
			ret += num[j];
		}
		printf("case #%d:\n",i);
		printf("%d\n",ret);
	}
	return 0;
}