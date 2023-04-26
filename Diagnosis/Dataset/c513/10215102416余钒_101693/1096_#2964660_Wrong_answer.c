#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int T,n,a,b;
int out[1005],in[1005];
int main() {
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=100;i++) in[i]=out[i]=0;
		scanf("%d",&n);
		int f=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a,&b);
			out[a]++,in[b]++;
			if(out[a]>1||out[a]&&in[a]||out[b]&&in[b]) f=1;
		}
		if(f==1) puts("Poor dxw!");
		else puts("Lucky dxw!");
	}
	return 0;
}
