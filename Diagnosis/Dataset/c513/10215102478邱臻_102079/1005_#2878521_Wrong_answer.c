#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int T,i,j,x;
	double o,result;
	scanf("%d",&T);//问题数
	for(i=0;i<T;i++){
		scanf("%lf",&o);
		j=0;result=0;
		while(o!=0.0){
			x=o*10;o=o*10.0-x*1.0;
			j--;
			result+=x*pow(8,j);
		}
		j=-j;
		printf("case #%d:\n%.*lf\n",i,3*j,result);
	} 
	return 0;
}