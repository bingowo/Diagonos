#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Pi 3.1415;
typedef struct{
	double rou;
	double sita;
}p;
int cmp1(const void *a, const void *b){
	if((*(p *)a).sita!=(*(p *)b).sita) return (*(p *)a).sita>(*(p *)b).sita;
	else return (*(p *)a).rou<(*(p *)b).rou;
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p a[1005];
		int m;
		scanf("%d",&m);
		for(j=0;j<m;j++){
			double x1,y1;
			scanf("%lf%lf",&x1,&y1);
			a[j].rou=sqrt(x1*x1+y1*y1);
			a[j].sita=atan2(y1,x1);
			//printf("%lf %lf\n",a[j].rou,a[j].sita);
			if(a[j].sita<0 && y1<0) a[j].sita=6.283185+a[j].sita;
			else if(a[j].sita<0 && y1>0) a[j].sita=3.1415926+a[j].sita;
			//if(x1==0 && y1!=0){
			//	printf("zhubi\n");
			//	if(y1>0) a[j].sita=1.5708;
			//	else if(y1<0) a[j].sita=4.7124;
				//else a[j].sita=0;
			//}
			/*if(y1==0 && x1!=0){
				if(x1>0) a[j].sita=0;
				else if(x1<0) a[j].sita=3.1415926;
			}*/
			//printf("%lf %lf\n\n\n\n",a[j].rou,a[j].sita);
		}
		qsort((void *)a,m,sizeof(a[0]),cmp1);
		printf("case #%d:\n",i);
		for(j=0;j<m;j++){
			printf("(%.4lf,%.4lf)\n",a[j].rou,a[j].sita);
		}
	}
}