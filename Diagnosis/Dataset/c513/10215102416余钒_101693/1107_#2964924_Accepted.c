#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int T,mp[10][10];

int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++) mp[i][j]=1;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++){
				int x;
				scanf("%d",&x);
				if(i-1>0) mp[i-1][j]+=x;
				if(i+1<4) mp[i+1][j]+=x;
				if(j-1>0) mp[i][j-1]+=x;
				if(j+1<4) mp[i][j+1]+=x;
				mp[i][j]+=x;
			}
		printf("case #%d:\n",c);
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++)
				printf("%d ",mp[i][j]&1);
			puts("");
		}
			
	}
	return 0;
}
