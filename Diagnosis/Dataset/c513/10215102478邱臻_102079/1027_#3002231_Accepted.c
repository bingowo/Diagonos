#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void* a,const void* b){
	double *p1,*p2;
	p1=*(double(*)[2])a,p2=*(double(*)[2])b;
	if(*(p1+1)!=*(p2+1))return *(p1+1)>*(p2+1)?1:-1;
	else return *p1<*p2?1:-1;
}
int main() {
	int t,n,i,j;
	double set[1000][2]={};
	double a,b,x,y;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);  //记录点的个数
		for(j=0;j<n;j++){
			scanf("%lf%lf",&x,&y);
			a=sqrt(x*x+y*y);b=atan2(y,x);
			if(b<0)b+=3.1415926*2;
			set[j][0]=a;set[j][1]=b;
		} 
		qsort(set,n,sizeof(set[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("(%.4lf,%.4lf)\n",set[j][0],set[j][1]);
		}
	}
	return 0;
}