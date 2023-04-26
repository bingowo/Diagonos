#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int t[32][32];
int pow(int x){
	int a=1;
	for(int i=0;i<x;i++)a*=2;
	return a;
}
int main()
{	
	t[1][1]=1;
	for(int i=2;i<32;i++)t[1][i]=t[1][i-1]*2+1;
	for(int i=2;i<32;i++){
		t[i][i]=1;
		for(int j=i+1;j<32;j++){
			if(j-i>i) t[i][j]=2*t[i][j-1]+pow(j-i-1)-t[i][j-i-1];
			else if(j-i-1>=0) t[i][j]=2*t[i][j-1]+pow(j-i-1);
			else t[i][j]=2*t[i][j-1];
		}
	}
	int x,y;scanf("%d%d",&x,&y);
	while(x!=-1 && y!=-1){
		printf("%d\n",t[y][x]);
		scanf("%d%d",&x,&y);
	}
	return 0;
}