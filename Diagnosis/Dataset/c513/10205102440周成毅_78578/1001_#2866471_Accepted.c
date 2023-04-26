#include<stdio.h>
void fun(int n,int m)
{
	if(n<m)
	{
		if(n<10)
			printf("%d",n);
		else
			printf("%c",n-10+'A');
	}
	else
	{
		fun(n/m,m);
		if(n%m<10)
			printf("%d",n%m);
		else
			printf("%c",n%m-10+'A');
	}
}
int main(){
	int T,i;
	scanf("%d",&T);
	int N[T],R[T];
	for(i=1;i<=T;i++){
		scanf("%d%d",&N[i],&R[i]);
	}
	for(i=1;i<=T;i++){
		if(N[i]>=0){
		fun(N[i],R[i]);
		}
		else{
			printf("-");
			fun(-N[i],R[i]);
		}
		printf("\n");
	}
}