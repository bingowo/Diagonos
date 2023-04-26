#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	long long x;
	long long y;	
}p;
int cmp1(const void *a,const void *b){
	long long x1=(*(p *)a).x,x2=(*(p *)b).x,y1=(*(p *)a).y,y2=(*(p *)b).y;
	if(x1<0) x1=-x1;
	if(y1<0) y1=-y1;
	if(x2<0) x2=-x2;
	if(y2<0) y2=-y2;
	unsigned long long t1=x1+y1,t2=x2+y2;
	if(t1!=t2)	return t1<t2;
	else if((*(p *)a).x!=(*(p *)b).x) return (*(p *)a).x>(*(p *)b).x;
	else return (*(p *)a).y>(*(p *)b).y;
	
}
int main(){
	int i,n;
	int ans=0;
	p a[105];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		//printf("%lld	%lld\n",a[i].x,a[i].y);
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	for(i=0;i<n;i++){
		//scanf("%lld%lld",&a[i].x,&a[i].y);
		//printf("%lld	%lld\n",a[i].x,a[i].y);
	}
	unsigned long long t1[505]={0},t2[505]={0};
	if((a[0].x>=0 && a[1].x<=0) || (a[0].x<=0 && a[1].x>=0)){
		t1[0]=a[0].x>0? a[0].x:-a[0].x;
		t1[0]=t1[0]+(a[1].x>0? a[1].x:-a[1].x);
	}
	else t1[0]=(a[0].x>0? a[0].x:-a[0].x)-(a[1].x>0? a[1].x:-a[1].x);
	if((a[0].y>=0 && a[1].y<=0) || (a[0].y<=0 && a[1].y>=0)){
		t2[0]=a[0].y>0? a[0].y:-a[0].y;
		t2[0]=t2[0]+(a[1].y>0? a[1].y:-a[1].y);
	}
	else t2[0]=(a[0].y>0? a[0].y:-a[0].y)-(a[0].y>0? a[0].y:-a[0].y);
	if(t1[0]!=9223372036854775808 || t2[0]!=9223372036854775808){
		unsigned long long ls=t1[0]+t2[0];
		printf("%llu\n",ls);
		for(i=0;i<n-1;i++){
			if((a[i].x>=0 && a[i+1].x<=0) || (a[i].x<=0 && a[i+1].x>=0)){
				t1[i]=llabs(a[i].x);
				t1[i]=t1[i]+llabs(a[i+1].x);
			}
			else t1[i]=llabs(a[i].x)-llabs(a[i+1].x);
			if((a[i].y>=0 && a[i+1].y<=0) || (a[i].y<=0 && a[i+1].y>=0)){
				t2[i]=llabs(a[i].y);
				t2[i]=t2[i]+llabs(a[i+1].y);
			}
			else t2[i]=llabs(a[i].y)-llabs(a[i+1].y);
			unsigned long long s=t2[i]+t1[i];
			//printf("s=%llu\n",s);
			if(s==1 || s==0) ans+=s;
			else{
				int f=0,cnt=1;
				unsigned long long tt=1;
				if(s%2==1) f=1;
				while(s>1){
					
					s/=2;
					cnt++;
				}
				//printf("%d",f);
				if(f==1) ans+=cnt;
				else{
					printf("%d",ans);
					return 0;
				}
				//printf("cnt=%d\n",cnt);
			}
			
		}
		printf("%d",ans);
	}
	else printf("18446744073709551616\n0");
}