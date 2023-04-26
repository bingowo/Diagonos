#include<stdio.h>
#include<stdlib.h>
//a是等腰三角形的边长，i，j是起始点的角标 

int matrix[200][200];
int calculation(int a,int i,int j){
	int sum=0,k=j;
	for(int x=0;x<a;i++,x++){
		for(j=k;j<=x+k;j++){
			sum+=matrix[i][j];
		}
	}
	return sum;
}
//n是行，m是列 
int count(int k,int m,int n){
	int sum,cnt=0,i=0,j=0;
	for(int a=2;a<=n&&a<=m;a++){
		for(i=0;i+a<=m;i++){
			for(j=0;j+a<=n;j++){
				sum = calculation(a,j,i);
				if(sum>=k)
					cnt++;
			}
		}
	}
	return cnt;
}
void reserve_x(int a[][200],int n,int m){
	int t;
	for(int i=0,j=n-1;i<j;i++,j--){
		for(int k=0;k<m;k++){
			t = a[i][k];
			a[i][k] = a[j][k];
			a[j][k] = t;
		}
	}
}
void reserve_y(int a[][200],int n,int m){
	int t;
	for(int i=0,j=m-1;i<j;i++,j--){
		for(int k=0;k<n;k++){
			t = a[k][i];
			a[k][i] = a[k][j];
			a[k][j] = t;
		}
	}
}
int main()
{
	int n,m,k,cnt;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	cnt = count(k,m,n);
	reserve_x(matrix,n,m);
	cnt+=count(k,m,n);
	reserve_y(matrix,n,m);
	cnt+=count(k,m,n);
	reserve_x(matrix,n,m);
	cnt+=count(k,m,n);
	printf("%d",cnt);
	return 0;
}