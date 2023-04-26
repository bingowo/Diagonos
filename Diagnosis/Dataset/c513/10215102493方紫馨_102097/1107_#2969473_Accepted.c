#include<stdio.h>
int zero_one(int n){
	if(n==0)
		return 1;
	else
		return 0;
}
void tran(int light[3][3],int i,int j){
	light[i][j] = zero_one(light[i][j]);
	if(i-1>=0)
		light[i-1][j] = zero_one(light[i-1][j]);
	if(j-1>=0)
		light[i][j-1] = zero_one(light[i][j-1]);
	if(i+1<3)
		light[i+1][j] = zero_one(light[i+1][j]);
	if(j+1<3)
		light[i][j+1] = zero_one(light[i][j+1]);
}

int main()
{
	
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int light[3][3] = {1,1,1,1,1,1,1,1,1};
		int t;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				scanf("%d",&t);
				t = t%2;
				if(t==1)
					tran(light,j,k);
			}				
		}
		printf("case #%d:\n",i);
		for(int j=0;j<3;j++){
			int k;
			for(k=0;k<2;k++)
				printf("%d ",light[j][k]);
			printf("%d\n",light[j][k]);
		}		
	}
	return 0;
}