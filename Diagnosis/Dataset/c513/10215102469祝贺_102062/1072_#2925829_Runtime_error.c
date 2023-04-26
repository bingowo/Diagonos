#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	int x,y;
	char path[20];
	int sp;
}node;
long long f(long long x,long long y){
	return x+y<0?-(x+y):x+y;
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

node q[10000];int rear=0,front=0;
int main()
{	
	long long x,y;scanf("%lld%lld",&x,&y);
	node start;node p;
	start.x=x;start.y=y;start.sp=0;
	if(x==0 && y==0)p=start;
	else if((x+y)%2==0)p.sp=-1;
	else {
		long long d=x+y;int len=0;
		while(d!=0){len++;d>>=1;}
		q[rear++]=start;
		while(rear!=front){
			p=q[front++];
			long long step=pow(2,len-p.sp-1);
			if(p.x==0 && p.y==0) break;
			else if(p.x<=0 && p.y<=0){
				node q1=p,q2=p;
				q1.y+=step;q2.x+=step;
				q1.path[q1.sp++]='S';q2.path[q2.sp++]='W';
				q[rear++]=q1;q[rear++]=q2;
			}
			else if(p.x<=0 && p.y>=0){
				node q1=p,q2=p;
				q1.y-=step;q2.x+=step;
				q1.path[q1.sp++]='N';q2.path[q2.sp++]='W';
				q[rear++]=q1;q[rear++]=q2;
			}
			else if(p.x>=0 && p.y<=0){
				node q1=p,q2=p;
				q1.y+=step;q2.x-=step;
				q1.path[q1.sp++]='S';q2.path[q2.sp++]='E';
				q[rear++]=q1;q[rear++]=q2;
			}
			else if(p.x>=0 && p.y>=0){
				node q1=p,q2=p;
				q1.y-=step;q2.x-=step;
				q1.path[q1.sp++]='N';q2.path[q2.sp++]='E';
				q[rear++]=q1;q[rear++]=q2;
			}
		}
		
	}
	p.path[p.sp]=0;
	printf("%d",p.sp);
	if(p.sp>0){printf("\n");for(int i=p.sp-1;i>=0;i--)printf("%c",p.path[i]);}
	return 0;
}