#include <stdio.h>
int n;
int a[13] = {0};
int res[1010] = {0};
int ret = 0;
void check(int now,int pos){
	if(now==0){
		ret = 1;
		return;
	}
	if(pos==n+1){
		return;
	}
	check(now+a[pos],pos+1);
	check(now,pos+1);
	check(now-a[pos],pos+1);
}
int main(void)
{
	scanf("%d",&n);
	int tot = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot += a[i];
	}
	for(int i=1;i<=tot;i++){
		ret = 0;
		check(i,1);
		if(ret) res[i] = 1;
		else res[i] = 0;
	}
	for(int i=1;i<=tot;i++) printf("%d",res[i]);
	return 0;
} 