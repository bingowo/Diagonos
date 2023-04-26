#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int T;
	int n; 
	int a,b;//a表示前一位二进制数，b表示后一位二进制数 
	int sum,max;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		sum=1,max=1;
		a=n%2;
		n=n/2;
		while(n!=0){
			b=n%2;
			n/=2;
			if(b!=a){
				sum++; //前后两个不等，sum++ 
			}else{
				sum=1; //前后两个相等，和再次置为1 
			}
			
			if(sum>max){
				max=sum;
			}
			
			a=b; //别忘了这个，把b的值给a，让a跟下一个比。 
			
		}
		
		printf("case #%d:\n%d\n",i,max);
		
	}	
}

