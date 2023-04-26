#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point{
	double rho,theta;//定义struct存放转换后的坐标 
};
int cmp(const void*a,const void*b){
	struct point pa=*(struct point*)a;
	struct point pb=*(struct point*)b;
	if(pa.theta==pb.theta){
		if(pa.rho>pb.rho)return -1;
		if(pa.rho<pb.rho)return 1;
		return 0;
	}
	if(pa.theta>pb.theta)return 1;
	return -1;
}
void solve(){
	int N;
	scanf("%d",&N);
	struct point p[1000];
	double pi=acos(-1);//角度要转换为rad型 
	for(int i=0;i<N;i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		p[i].rho=sqrt(x*x+y*y);
		if(x>=0&&y>=0)p[i].theta=atan(y/x);
		if(x<0&&y>=0)p[i].theta=pi+atan(y/x);
		if(x<0&&y<0)p[i].theta=pi+atan(y/x);
		if(x>=0&&y<0)p[i].theta=2*pi+atan(y/x);
	 } 
	 qsort(p,N,sizeof(p[0]),cmp);
	 for(int i=0;i<N;i++)
	 {
	 	printf("(%.4lf,%.4lf)\n",p[i].rho,p[i].theta);//小数点后面保留四位数
	 }
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
}
