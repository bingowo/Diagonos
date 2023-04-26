#include<stdio.h>
typedef struct{
	int dis;
	int sp;
	double time;
}CAR;
int main(){
	int d,n;
	scanf("%d %d",&d,&n);
	CAR car[1000]; 
	for(int v=0;v<n;v++) {
	scanf("%d %d",&car[v].dis,&car[v].sp);
	car[v].time=((double)(d-car[v].dis)/(double)(car[v].sp));}
	double mtime=car[0].time;
	for(int i=0;i<n;i++){
		if(car[i].time>mtime) mtime=car[i].time;
	}
	printf("%.6f\n",(double)d/mtime);
	return 0;
}