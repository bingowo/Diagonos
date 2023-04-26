#include <stdio.h>
#define N 100

int main(){
	int A,B;
	scanf("%d %d",&A,&B);
	
	int a[N]={0,};
	int k=0;
	
	while(A!=0){
		a[k++]=A%3;
		A/=3;
	}
	
	//	printf("[k:%d ",k);
	//	for(int i=k;i>=0;i--)printf("%d",a[i]);
	//	printf("]");
	
	int carry=0;
	for(int i=0;i<N;i++){
		a[i]+=1+carry;
		carry=0;
		if(a[i]>=3){
			a[i]-=3;
			carry=1;
		}
	}
	
	//	printf("[");
	//	for(int i=k;i>=0;i--)printf("%d",a[i]);
	//	printf("]");
	
	for(int i=0;i<N;i++){
		a[i]-=1;
		if(a[i]==-1){
			a[i]=2;
		}
	}
	
	//	printf("[");
	//	for(int i=k;i>=0;i--)printf("%d",a[i]);
	//	printf("]");
	
	//输出
	int i=N-1,j=0,dot=0;
	while(B>1){
		B/=3;
		dot++;
	}
	while(i>dot && a[i]==0)i--;
	while(a[j]==0)j++;
	
	//	printf("[a0:%d]",a[29]);
	//	printf("[i:%d j:%d dot:%d]",i,j,dot);
	while(i>=dot)printf("%d",a[i--]);
	if(dot>j)printf(".");
	while(i>=j)printf("%d",a[i--]);
	
	return 0;
}