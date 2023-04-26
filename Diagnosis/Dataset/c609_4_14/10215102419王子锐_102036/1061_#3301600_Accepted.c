#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long dp[10005];
int not_pri[10005];
int pri[10005],cnt=0,n;

int main(){
	not_pri[1]=1;
	for (int i = 2; i * i <= 1000; i++)
        if (!not_pri[i])
            for (int j = i * i; j <= 1000; j += i)
                not_pri[j] = 1;
	for(int i=1;i<=1000;i++)
		if(!not_pri[i]) pri[++cnt]=i;
	scanf("%d",&n);
	dp[0]=1;
	for(int j=1;j<=cnt;j++){
		for(int i=1;i<=n;i++){ 
			if(i-pri[j]>=0) dp[i]+=dp[i-pri[j]];
		}
	}
	printf("%lld",dp[n]);
	return 0;
} 