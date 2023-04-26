#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int T,r,c,n,p;
int mp[105][105];
int get(int x1,int y1,int x2,int y2){
	return mp[x2][y2]-mp[x2][y1-1]-mp[x1-1][y2]+mp[x1-1][y1-1];
}
int main() {
	scanf("%d",&T);
	for(int Case=0;Case<T;Case++){
		scanf("%d%d%d%d",&r,&c,&n,&p);
		for(int i=0;i<=r;i++)
			for(int j=0;j<=c;j++) mp[i][j]=0;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			mp[x][y]=1;
		}
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				mp[i][j]+=mp[i][j-1]+mp[i-1][j]-mp[i-1][j-1];
		int cnt=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				for(int k=i;k<=r;k++)
					for(int l=j;l<=c;l++)
						if(get(i,j,k,l)>=p) cnt++;
		printf("case #%d:\n",Case);
		printf("%d\n",cnt);
	}
	return 0;
}