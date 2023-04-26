#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	long long x,y;
	char path[64];
	int sp;
}node;
long long f(long long x,long long y){
	if(x<0)x=-x;
	if(y<0)y=-y;
	return x+y;
}
long long pow(int a,int n){
	long long ans=a;int i=1;
	if(n==0)return 1;
	if(n==1)return a;
	while(i*2<=n){
		ans=ans*ans;
		i*=2;
	}
	for(;i<n;i++){
		ans=ans*a;
	}
	return ans;
}

node q[1000000];int rear=0,front=0;
int main()
{	
	long long x,y;scanf("%lld%lld",&x,&y);
	node start;node p;
	start.x=x;start.y=y;start.sp=0;
	if(x==0 && y==0)p=start;
	else if(f(x,y)%2==0)p.sp=-1;
	else {
		long long d=f(x,y);int len=0;
		while(d>0){len++;d>>=1;}
		q[rear++]=start;
		while(rear!=front){
			p=q[front++];
			long long step=pow(2,len-p.sp-1);
			if(p.x==0 && p.y==0) break;
			else if(p.x<=0 && p.y<=0){
				node q1=p,q2=p;
				q1.y+=step;q2.x+=step;
				q1.path[q1.sp++]='S';q2.path[q2.sp++]='W';
				if(f(q1.x,q1.y)<f(p.x,p.y))q[rear++]=q1;
				if(f(q2.x,q2.y)<f(p.x,p.y))q[rear++]=q2;
			}
			else if(p.x<=0 && p.y>=0){
				node q1=p,q2=p;
				q1.y-=step;q2.x+=step;
				q1.path[q1.sp++]='N';q2.path[q2.sp++]='W';
				if(f(q1.x,q1.y)<f(p.x,p.y))q[rear++]=q1;
				if(f(q2.x,q2.y)<f(p.x,p.y))q[rear++]=q2;
			}
			else if(p.x>=0 && p.y<=0){
				node q1=p,q2=p;
				q1.y+=step;q2.x-=step;
				q1.path[q1.sp++]='S';q2.path[q2.sp++]='E';
				if(f(q1.x,q1.y)<f(p.x,p.y))q[rear++]=q1;
				if(f(q2.x,q2.y)<f(p.x,p.y))q[rear++]=q2;
			}
			else if(p.x>=0 && p.y>=0){
				node q1=p,q2=p;
				q1.y-=step;q2.x-=step;
				q1.path[q1.sp++]='N';q2.path[q2.sp++]='E';
				if(f(q1.x,q1.y)<f(p.x,p.y))q[rear++]=q1;
				if(f(q2.x,q2.y)<f(p.x,p.y))q[rear++]=q2;
			}
		}
		
	}
	p.path[p.sp]=0;
	printf("%d",p.sp);
	if(p.sp>0){printf("\n");for(int i=p.sp-1;i>=0;i--)printf("%c",p.path[i]);}
	return 0;
}