#include<stdio.h>
#include<math.h>
int main(){
	int w,h;
	scanf("%d %d",&w,&h);
	int p1[100][100];
	int p2[100][100]={0};
	for(int i=0;i<;i++)
	for(int j=0;j<h;j++) scanf("%d",&p1[i][j]);
	for(int x=1;x<=h-2;x++){
		for(int y=1;y<=w-2;y++){
		int sum=0, sum1=0;
		////
		if(p1[x-1][y-1]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
		if(p1[x-1][y]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
		if(p1[x-1][y+1]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
		if(p1[x][y+1]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
		if(p1[x+1][y+1]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
		if(p1[x+1][y]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
		if(p1[x+1][y-1]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
		if(p1[x][y-1]>=p1[x][y]) sum=sum*2+1;
		else sum*=2;
	///
		if(p1[x-1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
	    if(p1[x-1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		sum=fmin(sum1,sum);
		sum1=0;
		////
		if(p1[x-1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
	    if(p1[x-1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		sum=fmin(sum1,sum);
		sum1=0;
		///
		if(p1[x][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
	    if(p1[x-1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		sum=fmin(sum1,sum);
		sum1=0;
		///
		
		if(p1[x+1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
	    if(p1[x-1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		sum=fmin(sum1,sum);
		sum1=0;
		/////
		if(p1[x+1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
	    if(p1[x-1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
			if(p1[x+1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		sum=fmin(sum1,sum);
		sum1=0;
		////
		
		if(p1[x+1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
	    if(p1[x-1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
			if(p1[x+1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		sum=fmin(sum1,sum);
		sum1=0;
		///
		if(p1[x][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
	    if(p1[x-1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x-1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
			if(p1[x+1][y+1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		if(p1[x+1][y-1]>=p1[x][y]) sum1=sum1*2+1;
		else sum1*=2;
		sum=fmin(sum1,sum);
		sum1=0;
		p2[x][y]=sum;}
	}
	for(int x=1;x<=h-2;x++){
		for(int y=1;y<=w-2;y++) {
		printf("%d",p2[x][y]);
		printf(" ");}
		printf("\n");
		}
	
}