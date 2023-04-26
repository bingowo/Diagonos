#include<stdio.h>
int n,m,k;
int cal(int a,int b,int c[n][m],int t,int k){     //t代表矩阵的阶,c[][]即为输入的二维数组，c[a][b]即为左上顶点,k为下限值 
	int i,j;
	int Sum=0;
	int temp=t;
	for(i=a;i<=a+t-1;i++){
		for(j=b;j<=b+temp-1;j++){
			Sum=Sum+c[i][j];
		}
		temp--;
	}
	if(Sum>=k) return 1;
	else return 0; 
}
long long cal2(int a,int b,int c[n][m],int k){
	long long sum=0;
	int i=2;
	while(a+i-1<=n-1&&b+i-1<=m-1){
		sum=sum+cal(a,b,c,i,k);
		i++;
	}
	return sum;
}
long long cal3(int c[n][m],int k){
	long long sum=0;
	int a=0,b=0;
	while(a<=n-1){
		while(b<=m-1){
			sum=sum+cal2(a,b,c,k);
			b++;
		}
		a++;
		b=0;
	}
	return sum;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	int c[n][m];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&c[i][j]);
		}
	}
	int a=0,b=0;
	long long sum=0;
	sum=sum+cal3(c,k);
	int c1[n][m];  //列变行不变 
	int c2[n][m];  //行变列不变 
	int c3[n][m];  //行列都变
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c1[i][j]=c[i][m-1-j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c2[i][j]=c[n-1-i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c3[i][j]=c[n-1-i][m-1-j];
		}
	}
	a=0,b=0;
	sum=sum+cal3(c1,k);
	a=0,b=0;
    sum=sum+cal3(c2,k);
	a=0,b=0;
	sum=sum+cal3(c3,k);
	printf("%lld",sum);	
}
