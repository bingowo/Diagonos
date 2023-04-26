#include <stdio.h>

void solve()
{
	int N,R;
	scanf("%d %d",&N,&R);
	int n=N;
	if(N<0){
		n=-N;
		printf("-");
	}
	int a[33]={0};
	for (int i=0;n>0;i++){
		a[i]=n%R;
		n/=R;
	}
	int i;
	for (i=32;a[i]==0;i--);
	for (;i>-1;i--){
		if(a[i]>=0&&a[i]<=9){
			printf("%d",a[i]);
		}
		else{
			printf("%c",a[i]+55);
		}
	} 
	printf("\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		solve();
	}
	return 0;
}