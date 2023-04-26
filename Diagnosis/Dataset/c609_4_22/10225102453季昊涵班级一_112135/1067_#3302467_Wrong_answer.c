#include<stdio.h>

int main(){
	int a,n,m,x;
	scanf("%d %d %d %d",&a,&n,&m,&x);
	int up[21],down[21],now[21];
	up[1]=a;
	down[1]=0;
	now[1]=a;
	up[2]=a;
	down[2]=a;
	now[2]=a;
	now[n]=m;
	for(int i=3;i<n;i++){
		up[i]=up[i-1]+up[i-2];
		down[i]=up[i-1];
		now[i]=now[i-1]+up[i]-down[i];
	}
	printf("%d",now[x]);
	
	
	
	
	return 0;
}