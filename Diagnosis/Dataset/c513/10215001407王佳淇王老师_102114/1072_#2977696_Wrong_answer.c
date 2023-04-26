#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
 char pa[1000];
 int l=0;
int countstep(long long int x,long long int y){
	int r=0;
	long long dis=abs(x)+abs(y);
	double b=log10(dis+1)/log10(2);
	if(b-(int)b==0) r=b;
	else r=(int)b+1;
	return r;
	}

void path(long long x,long long y,int r){
	if(r){
		
		long long d=(1LL<<(r-1));
		if(abs(x)>abs(y)) {
			if(x>0) {
				pa[l++]='E';
				return path(x-d,y,r-1);
			}
			else {
				pa[l++]='W';
				return path(x+d,y,r-1);
			}
		}
		else{
			if(y>0) {
				pa[l++]='N';
				return path(x,y-d,r-1);
			}
			else {
				pa[l++]='S';
				return path(x,y+d,r-1);
			}
			
		}
		
		/*return abs(x)>abs(y)?
		(x>0?path(x-d,y,r-1)+"E":path(x+d,y,r-1)+"W")
	   :(y>0?path(x,y-d,r-1)+"N":path(x,y+d,r-1)+"S");*/
	}

}
int main(){
	long long int x,y;
	scanf("%lld %lld" ,&x,&y);
	int dis=abs(x)+abs(y);
	if(dis%2==1) {
	int r=countstep(x,y);
	printf("%d\n",r);
	int len=strlen(pa);
	for(int o=0;o<len;o++) printf("%c",pa[o]);
}
	else printf("-1");
	return 0;
}