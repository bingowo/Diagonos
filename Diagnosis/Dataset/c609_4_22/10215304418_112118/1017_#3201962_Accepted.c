#include<stdio.h>

int a[10010];
int n=0;

int cmp(const void* x,const void* y){
    return *(int*)x-*(int*)y;
}
int main(){
	char c;
	scanf("%c",&c);
	int x;
	while (scanf("%d",&x)!=-1){
		n++;
		a[n]=x;
	}
	a[0]=1001;
	a[n+1]=0;
	qsort(a+1,n,sizeof(a[0]),cmp);
	if (c=='A'){
		for (int i=1;i<=n;i++){
			if (a[i]!=a[i-1]) printf("%d ",a[i]);
		}
		printf("\n");
	}
	else {
		for (int i=n;i>=1;i--){
			if (a[i]!=a[i+1]) printf("%d ",a[i]);
		}
		printf("\n");
	}
    return 0;
}
