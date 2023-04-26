#include<stdio.h>
typedef struct{
	int dis;
	int sp;
}CAR;
int main(){
	int d,n;
	scanf("%d %d",&d,&n);
	CAR car[1000]; 
	for(int v=0;v<n;v++) scanf("%d %d",&car[v].dis,car[v].sp);
	printf(" ");
	return 0;
}