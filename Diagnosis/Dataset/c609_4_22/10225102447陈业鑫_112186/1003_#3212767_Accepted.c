#include<stdio.h>
int main(){
	unsigned long long isr;
	int num, i;
	scanf("%d",&num);
	unsigned long long tep=1;
	unsigned long long is[300] = {0};
	for(i=0;i<num;i++){
	    scanf("%llu", &is[i]);
	}
	for(i=0;i<num;i++){
		isr = is[i];
		while(tep*2333<=isr){
			tep*=2333;			
		}
		//tep<=isr;
		while(isr>0){
			printf("%d ", isr/tep);
			isr %= tep;
			tep/=2333;
		}
		while(tep>0){
			tep /= 2333;
			printf("0 ");
		}
		tep = 1;
		printf("\n");
	}
	return 0;
}