#include<stdio.h>
#include<string.h>
long long ans[105][215][215]={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<105;j++){
			for(int k=0;k<215;k++){
				for(int l=0;l<215;l++)
				 ans[j][k][l]=0;
			}
		}
		int t[215][215]={0};
		char a[105];
		int b[105];
		scanf("%s",a);
		for(int j=0;j<strlen(a);j++){
			b[j]=a[j]-48;
		}
		long long sum=0;
		for(int j=0;j<strlen(a);j++){
			sum=(sum*10+b[j])%1000000007;
			for(int l=2;l<215;l++){
				ans[j][l][sum%l]=1;
			}
		}
		/*for(int k=0;k<=2;k++){
				printf("\nk=%d\n",k);
				for(int l=0;l<7;l++){
				printf("l=%d %d %d %d %d\n",l,ans[k][2][l],ans[k][3][l],ans[k][5][l],ans[k][7][l]);
			 	}
			}*/
		for(int j=1;j<strlen(a);j++){
			sum=0;
			for(int tt=j;tt<strlen(a);tt++){
				sum=(sum*10+b[tt])%1000000007;
				//printf("sum=%d\n",sum);
				for(int k=2;k<215;k++){
					for(int l=0;l<k;l++){
						//if(k==3)
						//printf("k=%d\n",(k+(l-sum)%k)%k);
						ans[tt][k][(l+sum)%k]+=ans[j-1][k][l];
						ans[tt][k][(k+(l-sum)%k)%k]+=ans[j-1][k][l];
						ans[tt][k][(l+sum)%k]%=1000000007;
						ans[tt][k][(k+(l-sum)%k)%k]%=1000000007;
					}
				}
			}
			/*for(int k=0;k<=2;k++){
				printf("\nk=%d\n",k);
				for(int l=0;l<7;l++){
				printf("l=%d %d %d %d %d\n",l,ans[k][2][l],ans[k][3][l],ans[k][5][l],ans[k][7][l]);
			 	}
			}*/
		}
		int len=strlen(a)-1;
		printf("%d\n",(ans[len][2][0]+ans[len][3][0]+ans[len][5][0]+ans[len][7][0]-ans[len][6][0]-ans[len][10][0]-ans[len][14][0]-ans[len][15][0]-ans[len][21][0]-ans[len][35][0]+ans[len][30][0]+ans[len][42][0]+ans[len][70][0]+ans[len][105][0]-ans[len][210][0])%(1000000007));
	}
}