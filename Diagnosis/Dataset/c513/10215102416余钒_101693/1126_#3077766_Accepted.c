#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL unsigned long long
int n; 
LL a[10005];
int num[100005];
int main() {
	scanf("%d",&n);
	LL o=0,min=1e19,sum=0,ps=0;
	for(int i=1;i<=n;i++){
		scanf("%llu",&a[i]),o^=a[i];
		if(min>a[i]) min=a[i],ps=i;
	} 
	if(o!=0) puts("-1");
	else{
		for(int i=1;i<=n;i++){
			if(i==ps) continue;
			int pos=1;
			while(a[i]){
				num[pos]+=a[i]%10;
				a[i]/=10;
				pos++;
			}
			for(int j=1;j<=100;j++) 
				num[j+1]+=num[j]/10,num[j]%=10;
		}
		for(int i=100;i;i--){
			if(num[i]!=0){
				for(int j=i;j;j--) printf("%d",num[j]);
				puts("");
				break;
			}
			if(i==1&&num[i]==0) puts("0");
		}
	}
	return 0;
}