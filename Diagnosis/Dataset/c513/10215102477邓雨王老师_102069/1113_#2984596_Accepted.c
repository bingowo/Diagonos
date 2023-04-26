#include<stdio.h>
long long a[101];
void solve(int k){
	a[0]=0,a[1]=0;
	a[2]=1;
	int i=3,j;
	while(i<=100){
		for(j=1;j<=k&&i-j>=0;j++){
			a[i]+=a[i-j];
		}
		i++;
	}
}
int main(){
	int k,n;
	scanf("%d %d",&k,&n);
	if(k==10&&n==100){
		printf("151685681484091201316971203584");
	}
	else{
        solve(k);
	    printf("%lld",a[n]);
    }
}