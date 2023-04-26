#include <stdio.h>

int trans(int a)
{
	if(a==1){
		return 0;
	}
	return 1;
}

solve(int T)
{
	int light[5][5],order[3][3];
	int i,j;
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			light[i][j]=1;
		}
	}
	int num;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			scanf("%d",&num);
			num%=2;
			order[i][j]=num;
		}
	}
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if(order[i][j]==1){
				light[i+1][j+1]=trans(light[i+1][j+1]);
				light[i+1][j]=trans(light[i+1][j]);
				light[i+1][j+2]=trans(light[i+1][j+2]);
				light[i][j+1]=trans(light[i][j+1]);
				light[i+2][j+1]=trans(light[i+2][j+1]);
			}
		}
	}
	for (i=1;i<4;i++){
		for (j=1;j<4;j++){
			printf("%d ",light[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
}