#include<stdio.h>
int main()
{
	int w,h;
	long long d;
	char c,k;
	scanf("%d%d%lld%c%c",&w,&h,&d,&k,&c);
	int num[200][200];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			scanf("%d",&num[i][j]);
		}
	}
	if(c=='L')
		d = -d;
	d = d/90;
	d = d%4;
	if(d<0)
		d += 4;
	int ret[200][200];
	if(d==1){
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				ret[j][h-i-1] = num[i][j];
			}
		}
	}
	if(d==2){
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				ret[h-i-1][w-j-1] = num[i][j];
			}
		}
	}
	if(d==3){
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				ret[w-j-1][i] = num[i][j];
			}
		}
	}
	if(d==2){
		printf("%d %d\n",w,h);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				printf("%d%c",ret[i][j],j==w-1?'\n':' ');
			}
		}
	}
		
	if(d==1||d==3){
		printf("%d %d\n",h,w);
		for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
				printf("%d%c",ret[i][j],j==h-1?'\n':' ');
			}
		}
	}
		
	return 0;
}