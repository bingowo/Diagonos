#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmp(const void* a,const void* b){
	double *p1,*p2;
	p1=*(double(*)[2])a,p2=*(double(*)[2])b;
	if(*(p1+1)!=*(p2+1))return *(p1+1)>*(p2+1)?1:-1;
	else return *p1<*p2?1:-1;
}
int main() {
	int t,i,n,j,k;
	double x,y,a,b;
	double number[1000][2];
	scanf("%d",&t);
	for(i=0;i<t;i++){    //每一组问题 
		scanf("%d",&n);   //每个问题的点的个数
		for(j=0;j<n;j++){  //每个点的坐标 
			scanf("%lf %lf",&x,&y);
			a=sqrt(x*x+y*y);b=atan2(y,x);
			if(b<0)b+=3.14159*2;
			number[j][0]=a;number[j][1]=b;  //横纵坐标记录 
		} 
		qsort(number,n,sizeof(number[0]),cmp);
		printf("case #%d:\n",i);
		for(k=0;k<n;k++){
			printf("(%.4lf,%.4lf)\n",number[k][0],number[k][1]);
		}	  
	} 
	return 0;
}