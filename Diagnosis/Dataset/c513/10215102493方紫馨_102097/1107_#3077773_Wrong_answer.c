#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	int n[3][3],t,light[3][3];
	for(int k=0;k<T;k++){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&t);
				n[i][j] = t%2;
				light[i][j]=1;
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(n[i][j]==0)
					continue;
				if(light[i][j]==0)
					light[i][j]=1;
				else
					light[i][j]=0;
				if(i-1>=0){
					if(light[i-1][j]==0)
						light[i-1][j]=1;
					else
						light[i-1][j]=0;
				}
				if(j-1>=0){
					if(light[i][j-1]==0)
						light[i][j-1]=1;
					else
						light[i][j-1]=0;
				}
				if(j+1<3){
					if(light[i][j+1]==0)
						light[i][j+1]=1;
					else
						light[i][j+1]=0;
				}
				if(i+1<3){
					if(light[i+1][j]==0)
						light[i+1][j]=1;
					else
						light[i+1][j]=0;
				}
			}
		}
		printf("case %d:\n",k);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				printf("%d%c",light[i][j],j==2?'\n':' ');		
			}
		}
	}
	return 0; 
 } 