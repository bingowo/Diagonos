#include<stdio.h>
#include<stdlib.h>	
int n,m,k;
int a[205][205];
int ma(int x,int y){
	return x>y? x:y; 
}
int mi(int x,int y){
	return x>y? y:x; 
}
int sum1(int x,int y,int d1,int d2){
	int anst=0;
	long long s;
	int xx=x+d1,yy=y+d2;
	int f=0;
	//int u=i,d=n-i,l=j,r=m-j;
	s=a[x][y];
	//printf("x=%d	y=%d\nd1=%d		d2=%d\n",x,y,d1,d2);
	while(xx>=0 && xx<n && yy>=0 && yy<m){	
		//printf("xx=%d s=%lld\n",xx,s);
		/*if(f==1){
			anst++;
			continue;
		}*/
		int xxx=xx,yyy=y;
		//printf("xxxxx=%d	yyyyy=%d\n",xxx,yyy);
		while(xxx!=x){
			s+=a[xxx][yyy];
			xxx=xxx-d1;
			yyy=yyy+d2;
		}
		s+=a[xxx][yyy];
		//printf("xx2=%d s2=%lld\n",xx,s);
		if(s>=k){
			int y1,x1;
			//printf("x=%d y=%d d1=%d d2=%d xx=%d yy=%d a[x][y]=%d\n",x,y,d1,d2,xx,yy,a[x][y]);
			//printf("ans1=%d ans2=%d ans3=%d ans4=%d\n",xx/d1,(xx-n+1)/d1,yy/d2,(yy-m+1)/d2);
			if(d1<0) x1=xx+1;
			else x1=n-xx;
			if(d2<0) y1=yy+1;
			else y1=m-yy;
			anst+=mi(x1,y1);
			f=1;
			//printf("%d %d\n",x,xx);
			break;
		}
		xx=xx+d1,yy=yy+d2;
	}
	return anst;
}
int main(){
	int ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans+=sum1(i,j,-1,-1);
			ans+=sum1(i,j,1,1);
			ans+=sum1(i,j,1,-1);
			ans+=sum1(i,j,-1,1);
		}
	}
	printf("%d",ans);
}