#include <stdio.h>

int fun(int x){
	int max=1,n=1,i=0,j;
	int a[32];
	do{
		a[i]=x%2;
		x/=2;
		i++;
	}while(x/2>0||x%2!=0);
	for(j=0;j<i-1;j++){
		while(j<i-1){
			if(a[j]!=a[j+1])n++;
			if(a[j]==a[j+1])break;
			j++;
		}
		if(max<=n)max=n,n=1;
	}
	return max;
}

int main(){
	int T,i;
	int n[10];
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&n[i]);
	}
	for(i=0;i<T;i++){
		n[i]=fun(n[i]);
		printf("case #%d:\n%d\n",i,n[i]);
	}
	return 0;
} 