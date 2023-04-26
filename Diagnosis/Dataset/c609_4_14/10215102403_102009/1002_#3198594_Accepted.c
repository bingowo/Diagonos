#include<stdio.h>
int main(){
	int i,t;
	scanf("%d\n",&t);;
	for(i=0;i<t;i++){
		int k=0,max=1;
		int n,count=1; scanf("%d\n",&n);
		int j[31];
		while(n){
			j[k]=n%2;
			n=n/2; k++;	
		}
		k--;
		while(k>=1){
			if(j[k]!=j[k-1]) count++;
			else{
				if(count>=max)max=count;count=1;
			}
			k--;
		}
		printf("case #%d:\n%d\n",i,(max>count)?max:count);
	}
	return 0;
}