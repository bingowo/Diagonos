#include <stdio.h>
#include <stdlib.h>
int n;
int* f(int* num1){
	int* num2=(int*)malloc((n+1)*sizeof(int));
	int i;
	for(i=1;i<=n;i++){
		num2[i]=0;
	}
	if(num1[1]){
		num2[2]+=num1[1];
	}
	for(i=2;i<n;i++){
		if(num1[i]){
			num2[i-1]+=num1[i];
			num2[i+1]+=num1[i];
		}
	}
	if(num1[n]){
		num2[n-1]+=num1[n];
	}	
	free(num1);
	return num2;
}
int main(){
	int cas;scanf("%d",&cas);
	int i;
	for(i=0;i<cas;i++){
		int p,m,t;scanf("%d%d%d%d",&n,&p,&m,&t);
		if(t>n){
		    printf("0");
		    continue;
		}
		//
		int* num=(int*)malloc((n+1)*sizeof(int));
		int j;
		for(j=0;j<p;j++)num[j]=0;
		num[p]=1;
		for(j=p+1;j<=n;j++)num[j]=0;
		for(j=0;j<m;j++){
			num=f(num);
		}
		printf("%d\n",num[t]);
		free(num);
	}
}