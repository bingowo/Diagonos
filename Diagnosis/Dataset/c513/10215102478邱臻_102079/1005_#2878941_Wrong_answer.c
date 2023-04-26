#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double zhishu2(int j){
	double res=1.0;
	while(j<0){
		res/=8;
		j++;
	}
	return res;
}
int main() {
	int T,i,j,x,k,y,a;
	double o,result;
	char num[50];
	scanf("%d",&T);//问题数
	for(i=0;i<T;i++){
		scanf("%s",num);
		j=2;k=-1;result=0;
		while(num[j]!='\0'){
			a=num[j]-'0';
		    result+=a*zhishu2(k);				
			j++;k--;
		}
		printf("case #%d:\n%.*lf\n",i,3*(j-2),result);
	} 
	return 0;
}