#include<stdio.h>
#include<string.h>
int main(){
	int u;
	int a[1005];
	int i,j=0;
	long long ans1=0,ans2=0;
	long long t1=-1,t2=1;
	int tt;
	scanf("%x",&u);
	int l=0;
	while(u>0){
		a[l]=u%2;
		u=u/2;
		l++;
	}
	if(a[0]==1) ans1=1;
	for(i=1;i<l;i++){
		j++;
		if(j%4!=2){
			ans1+=a[i]*t1;
			if(j%4==0) t1*=-1;
			else t1*=-2;
		}
		if(j%4!=0){
			ans2+=a[i]*t2;
			if(j%4==3) t2*=-1;
			else t2*=-2;
		}
	}
	if(ans2<0) printf("%lld%lldi",ans1,ans2);
	else if(ans2>0) printf("%lld+%lldi",ans1,ans2);
	else printf("%lld",ans1);
}
/*-1 1
0  -2
2  2
-4 0
4 -4
0  8
-8 -8
16 0*/
