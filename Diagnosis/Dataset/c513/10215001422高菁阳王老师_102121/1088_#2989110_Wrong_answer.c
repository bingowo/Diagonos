#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num,k,m,n;
	scanf("%d",&num);
	for(k=0;k<num;k++){
		int large=1,small=1,i;
		scanf("%d%d",&m,&n);
		printf("case #%d:\n",k);
	unsigned long long p=1;
	if(m>2*n){
		large=m-n;
		small=n;
	}
	else{
		large=n;
		small=m-n;
	}
	for(i=m;i>large;i--){
		if(i==2*small){
			p=p*2;
			small--;
		}
		else p=p*i;
	}
	while(small>1){
		p=p/small;
		small--;
	}
   printf("%d\n", p);

}
	return 0;
}