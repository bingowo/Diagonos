#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int ans[215][215]={0}; //(2,3,5,7)
		int t[215][215]={0};
		char a[105];
		int b[105];
		scanf("%s",a);
		for(int j=0;j<strlen(a);j++){
			b[j]=a[j]-48;
		}
		for(int l=2;l<215;l++){
			ans[l][b[0]%l]=1;
		}
		for(int j=1;j<strlen(a);j++){
			
			for(int k=2;k<215;k++){
				for(int l=0;l<k;l++){
					t[k][l]=ans[k][l];
					ans[k][l]=0;
				}
			}
			for(int k=2;k<215;k++){
				for(int l=0;l<k;l++){
					ans[k][(l+b[j])%k]+=t[k][l];
					ans[k][(l+210-b[j])%k]+=t[k][l];
					ans[k][(l*10+b[j])%k]+=t[k][l];
				}
			}
			for(int k=2;k<215;k++){
				for(int l=0;l<k;l++){
					ans[k][l]=ans[k][l]%(1000000007);
				}
			}
			for(int l=0;l<7;l++){
			//	printf("l=%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",l,ans[2][l],ans[3][l],ans[5][l],ans[7][l],ans[6][l],ans[10][l],ans[14][l],ans[15][l],ans[21][l],ans[35][l],ans[30][l],ans[42][l],ans[70][l],ans[105][l],ans[210][l]);
			}
		}
		printf("%d\n",(ans[2][0]+ans[3][0]+ans[5][0]+ans[7][0]-ans[6][0]-ans[10][0]-ans[14][0]-ans[15][0]-ans[21][0]-ans[35][0]+ans[30][0]+ans[42][0]+ans[70][0]+ans[105][0]-ans[210][0])%(1000000007));
	}
}