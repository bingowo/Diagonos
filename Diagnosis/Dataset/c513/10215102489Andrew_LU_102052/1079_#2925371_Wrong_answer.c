#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *x, const void *y){
	//printf("%d %d\n",*(int *)x,*(int *)y);
	return *(int *)x-*(int *)y;
	
}
int main(){
	int t,n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int cnt=0;
		int a[105]={0};
		int ans[505000]={0};
		scanf("%d%d",&n,&m);
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		for(int j=0;j<n;j++){ //第j个开始
			ans[cnt]=a[j];
			cnt++;
			for(int k=j+1;k<n;k++){ // 检查第k个 
				ans[cnt]=ans[cnt-1]+a[k];
				cnt++;
			}
		}
		//cnt--;
		qsort(ans,cnt,sizeof(ans[0]),cmp1);
		//printf("anscnt=%d\n",anscnt)
		printf("case #%d:\n",i);
		for(int j=0;j<m;j++){
			int l,u;
			scanf("%d%d",&l,&u);
			long long ansans=0;
			for(int k=l-1;k<=u-1;k++){
				ansans+=ans[k];
			}
			printf("%lld\n",ansans);
		}
	}
} 