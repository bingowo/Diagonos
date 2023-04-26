#include<stdio.h>
#include<string.h>
#include<math.h>

int* sum(int *a,int *b){
	int carry=0;
	int i=0;
	while(*(a+i)||*(b+i)||carry){
		int temp=*(a+i)+*(b+i)+carry;
		*(a+i)=temp%10;
		carry=temp/10;
		i++;
	}
	return a;
}

int* f(int n,int *a,int *b){
	if(n<=2)
	return a;
	return sum(f(n-1,a,b),f(n-2,a,b));
	
}

int main(){
	int T;
	scanf("%d",&T);
	int k=0;
	while(T--){
		int n;
		scanf("%d",&n);
		int a[1005]={1};
		int b[1005]={1};
		int i=1004;
		int *c=f(n,a,b);
		printf("case #%d:\n",k++);
		for(;i>=0;i--){
			if(*(a+i)!=0)
			break;
		}
		for(;i>=0;i--)
		printf("%d",*(a+i));
		printf("\n");
	}
	
	
	return 0;
}