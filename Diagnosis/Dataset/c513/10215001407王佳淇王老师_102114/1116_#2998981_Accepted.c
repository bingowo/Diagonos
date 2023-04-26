#include<stdio.h>
#include<math.h>
long long abss(long long x){
	if(x>=0) return x;
	else return -x;
}

int countstep(long long int x,long long int y){
	int r=0;
	long long dis=abss(x)+abss(y);
	double b=log10(dis+1)/log10(2);
	if(b-(int)b==0) r=b;
	else r=(int)b+1;
	return r;
	}
int main(){
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	if(x==0&&y==0) printf("0");
	else{
	long long int dis=abss(x)+abss(y);
	if(dis%2==1) {
	int r=countstep(x,y);
	printf("%d\n",r);}
	else printf("-1");
} }