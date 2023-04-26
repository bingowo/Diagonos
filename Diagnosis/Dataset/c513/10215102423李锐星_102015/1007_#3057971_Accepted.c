#include <stdio.h>

void solve()
{
	int n;
	scanf("%d",&n);
	int a[32]={0};
	int i;
	for (i=0;n>0;i++){
		a[i]=n&1;
		n>>=1;
	}
	int res=1;
	int ans=1;
	for (i=i-1;i>0;i--){
		if(a[i]==a[i-1]){
			if(ans<res) {
				ans=res;
			}
			res=1;
		}
		else{
			res++; 
		}
	}
	if(res>ans) ans=res;
	printf("%d\n",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
}