#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 1000000007 
int n,m,mp[505][505];

int main() {
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
			
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			int tmp=0,min=1e9;
			for(int k=-1;k<1;k++) tmp=tmp*2+(mp[i-1][j+k]>=mp[i][j]?1:0);
			for(int k=-1;k<1;k++) tmp=tmp*2+(mp[i+k][j+1]>=mp[i][j]?1:0);
			for(int k=1;k>-1;k--) tmp=tmp*2+(mp[i+1][j+k]>=mp[i][j]?1:0);
			for(int k=1;k>-1;k--) tmp=tmp*2+(mp[i+k][j-1]>=mp[i][j]?1:0);
			//printf("!! %d\n",tmp);
			for(int k=0;k<9;k++){
				if(tmp<min) min=tmp;
				int x=tmp&(1<<7);
				tmp-=x;
				if(x) tmp=tmp*2+1;
				else tmp*=2;
			}
			printf("%d ",min);
		}
		puts("");
	}
	return 0;
}
