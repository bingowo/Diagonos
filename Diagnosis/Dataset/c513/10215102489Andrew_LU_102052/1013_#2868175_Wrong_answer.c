#include<stdio.h>
#include<string.h>
#include<math.h>
int gcd(int x,int y){
	return x%y==0? y:gcd(y,x%y);
}
int main(){
	char a[35];
	scanf("%s",a);
	int q=1;
	long long ans=0,f1=0,f2=0;
	int i,f=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.') f=i;
	}
	if(f==0){
		f=strlen(a);
	}
	for(i=f-1;i>=0;i--){
		//printf("%d\n",q);
		if(a[i]=='1') ans+=q;
		else if(a[i]=='2') ans-=q;
		q=q*3;
	}
	q=1;
	f2=1;
	for(i=f+1;i<strlen(a);i++){
		f2=f2*3;
	}
	q=1;
	printf("%d\n",f2);
	for(i=strlen(a)-1;i>f;i--){
		if(a[i]=='1') f1+=q;
		else if(a[i]=='2') f1-=q;
		q=q*3;
	}
	if(f1<0 && ans>0){
		ans-=1;
		f1=f2-f1;
	}
	else if(f1>0 && ans<0){
		ans+=1;
		f1=f2-f1;
	}
	if(ans!=0) printf("%lld ",ans);
	if(f2!=0){
		int g=gcd(abs(f1),abs(f2));
		printf("%d %d",f1/g,f2/g);
	}
	
} 