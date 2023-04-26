#include<stdio.h>
int main(){
	long long int isr;
	int num, i;
	scanf("%d",&num);
	long long int tep=1;
	long long int is[300] = {0};
	for(i=0;i<num;i++){
	    scanf("%d", &is[i]);
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
			tep/=2333;
			printf("0 ");
		}
		tep = 1;
		printf("\n");
	}
	return 0;
}