#include <stdio.h>
int f(int n){
	int num;
	if (n-3>0)num=f(n-4)+f(n-3)+f(n-2)+f(n-1);	
	else switch(n){
		case 0:return 0;
		case 1:return 1;
		case 2:return 2;
		case 3:return 3;
		defult:return n;
	};
	
	return num;
}
int main(){
	int T,n,i;
	scanf ("%d",&T);
	for (i=0;i<T;i++){
		scanf ("%d",&n);
		printf("case #%d:\n",i);
		f(n);
		
	}
	return 0;
}