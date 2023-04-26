#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int zhishu(int j){
	int res=1;
	while(j>0){
	    res*=10;
	    j--;
	}
	return res;
}
double zhishu2(double j){
	double res=1.0;
	while(j<0){
		res/=8;
		j++;
	}
	return res;
}
int main() {
	int T,i,j,x,k,y;
	double o,result;
	scanf("%d",&T);//问题数
	for(i=0;i<T;i++){
		scanf("%lf",&o);
		j=0;result=0;
		while(o*zhishu(j-1)-x!=0){
			x=o*zhishu(j);
			j++;
		}
		j--;k=j;j=-j;
		while(x>0){
			y=x%10;x=x/10;
			result+=y*zhishu2(j);
			j++;
		}
		printf("case #%d:\n%.*lf\n",i,3*k,result);
	} 
	return 0;
}