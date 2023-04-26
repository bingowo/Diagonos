#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
char pa[1000]={0};
int lon=0;
int countstep(long long int x,long long int y){
	int r=0;
	long long dis=abs(x)+abs(y);
	double b=log10(dis+1)/log10(2);
	if(b-(int)b==0) r=b;
	else r=(int)b+1;
	return r;
	}

void path(long long x,long long y,int r){

while(r){
	long long d=(1LL<<(r-1));
		if(abs(x)>abs(y)) {
			if(x>0) {
				pa[lon++]='E';
				x-=d;
				r--;
			continue;
			/*	return path(x-d,y,r-1);*/
			}
			else {
				pa[lon++]='W';
				x+=d;
				r--;
				continue;
			/*	return path(x+d,y,r-1);*/
			}
		}
		else{
			if(y>0) {
				pa[lon++]='N';
			y-=d;
			r--;
			continue;
				/*return path(x,y-d,r-1);*/
			}
			else {
				pa[lon++]='S';
				y+=d;
				r--;
				continue;
				/*return path(x,y+d,r-1);*/
			}
			

}}}
int main(){
	long long int x,y;
	scanf("%lld %lld" ,&x,&y);
	int dis=abs(x)+abs(y);
	if(dis%2==1) {
	int r=countstep(x,y);
	printf("%d\n",r);
	path(x,y,r);
	int len=strlen(pa);
	for(int v=len-1;v>=0;v--) 
	printf("%c",pa[v]);
}
	else printf("-1");
	return 0;
}