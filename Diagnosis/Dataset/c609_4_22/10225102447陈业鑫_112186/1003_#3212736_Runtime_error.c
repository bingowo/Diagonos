#include<stdio.h>
int main(){
	long long int isr;
	int num, i;
	scanf("%d",&num);
	int j=0;
	long long int tep=1;
	int ret[300][6];
	int fret[300];
	for(i=0;i<num;i++){
		scanf("%lld", &isr);
		while(tep*2333<=isr){
			tep*=2333;			
		}
		//tep<=isr;
		while(isr>0){
			printf("%d ", isr/tep);
			isr %= tep;
			tep/=2333;
			j++;
		}
		while(tep>0){
			tep/=2333;
			printf("0 ");
			j++;
		}
		fret[i] = j;
		j = 0;
		tep = 1;
		printf("\n");
	}
	return 0;
}