#include<stdio.h>
#include<stdlib.h> 

int main(){

	int i,n,ch,flag=0;
	float weight,re;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		re=0.0;
		weight=1/8;
		while((ch=getchar())!=EOF){
			if(ch=='.'){
				flag=1;
			}
			if(flag=1){
				re+=weight*(ch-'0');
				weight/=8;
			}
		}
		printf("case #%d:\n%f",i,re);
	}
	return 0;
}