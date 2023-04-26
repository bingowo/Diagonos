#include<stdio.h>
#include<string.h>
int main(){
	long long u;
	int a[10005];
	int i,j=0;
	long long ans1=0,ans2=0;
	long long t1=1,t2=1;
	int tt;
	scanf("%llx",&u);
	int l=0;
	while(u>0){
		a[l]=u%2;
		u=u/2;
		l++;
	}
	for(i=0;i<l;i++){
		//printf("t=%d %d\nans=%d %d\n",t1,t2,ans1,ans2);
		if(i%4!=2){
			ans1+=a[i]*t1;
			if(i%4==0) t1*=-1;
			else t1*=-2;
		}
		if(i%4!=0){
			ans2+=a[i]*t2;
			if(i%4==2) t2*=-1;
			else t2*=-2;
		}
	}
	if(ans2<0){
		if(ans1!=0)
	     printf("%lld%lldi",ans1,ans2);
	    else printf("%lldi",ans2);
	}
	else if(ans2>0){
		if(ans2!=1){
			if(ans1!=0)
			 printf("%lld+%lldi",ans1,ans2);
			else printf("%lldi",ans2);
		}
		else{
			if(ans1!=0)
			 printf("%lld+i",ans1);
			else printf("i");
		}
	}
	else printf("%lld",ans1);
}
/*
1  0  0
-1 1  1
0  -2 2
2  2  3
-4 0  0
4 -4  1
0  8  2
-8 -8 3
*/
