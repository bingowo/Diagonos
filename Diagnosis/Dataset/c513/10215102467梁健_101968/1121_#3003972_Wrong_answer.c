#include<stdio.h>
int f[110][100100];
int w[110];//存储各砝码的重量
int main(){
	int n,i,j;
	int count=0,sum=0;//存储个数与砝码和
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		sum+=w[i];
	}//读入数据并求出砝码和
	f[0][sum]=1;//!!!!f[0][0]为1，因为下标都加上了sum，所以f[0][sum]=1！！！很重要
	for(i=1;i<=n;i++){
		for(j=-sum;j<=sum;j++){//注意j的取值范围
			f[i][j+sum]=f[i-1][j+sum];//不放砝码i
			if(j+sum-w[i]>=0)f[i][j+sum] =f[i-1][j+sum-w[i]];//i放在右侧
			if(j+sum+w[i]<=2*sum)f[i][j+sum]= f[i-1][j+sum+w[i]];//i放在左侧
		}
	}
	for(j=1;j<=sum;j++){//注意循环起点与终点
		if(f[n][j])count++;
	}
	printf("%d",count);
	return 0;
}