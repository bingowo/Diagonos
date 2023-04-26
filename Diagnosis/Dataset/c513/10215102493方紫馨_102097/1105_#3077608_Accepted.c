#include<stdio.h>

int binary(int *b){
	int ret=0;
	for(int i=0;i<8;i++){
		ret = ret*2+b[i];
	}
	return ret;
}

int solve(int* temp){
	int d=0,b[8],t,min=255;
	for(int i=0;i<8;i++){
		d=i;
		for(int j=0;j<8;j++,d++){
			if(d>=8)
				d=0;
			b[j] = temp[d];
		}
		t = binary(b);
		if(t<min)
			min = t;
	}
	return min;
}

int main()
{
	int m,n,matix[100][100],t;
	//n代表列数，m代表行数 
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&matix[i][j]);
		}
	}
	int temp[8],min;
	for(int i=1;i<m-1;i++){
		for(int j=1;j<n-1;j++){
			if(matix[i-1][j-1]>=matix[i][j])
				temp[0]=1;
			else
				temp[0]=0;
			if(matix[i-1][j]>=matix[i][j])
				temp[1]=1;
			else
				temp[1]=0;
			if(matix[i-1][j+1]>=matix[i][j])
				temp[2]=1;
			else
				temp[2]=0;	
			if(matix[i][j+1]>=matix[i][j])
				temp[3]=1;
			else
				temp[3]=0;
			if(matix[i+1][j+1]>=matix[i][j])
				temp[4]=1;
			else
				temp[4]=0;
			if(matix[i+1][j]>=matix[i][j])
				temp[5]=1;
			else
				temp[5]=0;
			if(matix[i+1][j-1]>=matix[i][j])
				temp[6]=1;
			else
				temp[6]=0;
			if(matix[i][j-1]>=matix[i][j])
				temp[7]=1;
			else
				temp[7]=0;
			t=solve(temp);
			printf("%d%c",t,j==n-2?'\n':' ');
		}
	}
	
	return 0;
} 