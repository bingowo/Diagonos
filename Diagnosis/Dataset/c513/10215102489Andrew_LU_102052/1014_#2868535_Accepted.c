#include<stdio.h>
int gcd(int x,int y){
	return x%y==0? y:gcd(y,x%y);
}
int main(){
	int a,b,ans;
	int z[1001]={0},x[1001]={0};
	scanf("%d%d",&a,&b);
	ans=a/b;
	a=a-ans*b;
	int g=gcd(a,b);
	a=a/g;
	b=b/g;
	int t=b;
	int cnt=0;
	while(t>=1){
		t=t/3;
		cnt++;
	}
	int cntz=0;
	while(ans>=1){
		z[cntz]=ans%3;
		ans/=3;
		cntz++;
	}
	int cnt2=cnt-1;
	while(a>=1){
		//printf("cnt%d\n",cnt2);
		x[cnt2]=a%3;
		//printf("x=%d",x[cnt2]);
		cnt2--;
		a/=3;
	}
	int i;
	//printf("%d\n",cnt);
	//for(i=cntz-1;i>=0;i--){
	//	printf("%d",z[i]);
	//}
	//printf("\n");
	for(i=cnt-1;i>=1;i--){
		x[i]+=1;
		if(x[i]>=3){
			x[i]-=3;
			x[i-1]++;
			if(i==1){
				z[0]++;
				if(cntz==0) cntz++;
			}
		}
		
	}
	//printf("%d\n",x[1]);
	for(i=0;i<cntz;i++){
		z[i]+=1;
	//	printf("i=%d  %d ",i,z[i]);
		if(z[i]>=3){
			z[i]-=3;
			z[i+1]++;
			if(i==cntz-1) cntz++;
		}
		z[i]--;
	//	printf("%d\n",z[i]);
	}
	//printf("cntz=%d\n",cntz);
	for(i=cntz-1;i>=0;i--){
		
		if(z[i]==-1) printf("2");
		else printf("%d",z[i]);
	}
	if(cntz==0) printf("0");
	if(cnt>1)printf(".");
	for(i=1;i<cnt;i++){
		x[i]--;
		if(x[i]==-1) printf("2");
		else printf("%d",x[i]);
	}
}