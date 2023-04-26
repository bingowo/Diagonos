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
	int T,i,j,x,k,y,a,z;
	double r,result;
	char num[100];
	scanf("%d",&T);//问题数
	for(i=0;i<T;i++){
		scanf("%s",num);
		j=2;k=-1;result=0;
		while(num[j]!='\0'){
			a=num[j]-'0';
		    result+=a*zhishu2(k);				
			j++;k--;
		}
		z=0;r=result;
		while((b=r*10%10)==0)z++;
		if(z>3(j-2))z=3(j-2);
		printf("case #%d:\n%.*lf\n",i,z,result);
	} 
	return 0;
}