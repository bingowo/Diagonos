#include<stdio.h>
int main(){
	int a,n,m,x;   //a代表初始上车人数，n代表地铁总站数，m代表最终下车的人数，x代表第x站
	int up[21];
	int down[21];
	int sum[21];
	scanf("%d%d%d%d",&a,&n,&m,&x);
	up[1]=a;
	down[1]=0;
	sum[1]=a;
	sum[2]=a;
	int t;
	for(t=0;t<=m;++t){
		up[2]=t;down[2]=t;
		int i;
		for(i=3;i<n;++i){
			up[i]=up[i-1]+up[i-2];
			down[i]=up[i-1];
			sum[i]=sum[i-1]+up[i]-down[i];
		}
		if(sum[n-1]==m){
			printf("%d\n",sum[x]);break;
		}
	}
	 
}