#include<stdio.h>

long long int f(long long int x,long long int y); 
int main()
{
	int T;
	int i;
	scanf("%d",&T);
	long long int *x = (long long int *)malloc(sizeof(long long int)*T);
	long long int *y = (long long int *)malloc(sizeof(long long int)*T);
	long long int *res = (long long int *)malloc(sizeof(long long int)*T);//res储存结果 
	for(i=0;i<T;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		res[i]=f(x[i],y[i]);
	}
	for(i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%lld\n",res[i]);
    }
    free(x);
    free(y);
    free(res);
	return 0;	
} 

long long int f(long long int x,long long int y)
{
	long long int temp;
	long long int num=0,num1=0,num2=0,len;
	int i;
	len=0;
	temp=y;
	while(temp>0){
		temp=temp/2;
		len++;
	}
	//数组初始化未完成 
	int *a=(int *)malloc(sizeof(int)*len);//a存放x的每一位 
	int *b=(int *)malloc(sizeof(int)*len);//b存放y的每一位
	for (i=0;i<len;i++){
		a[i]=0;
	} 
	for (i=0;i<len;i++){
		b[i]=0;
	} 
	while(x>0){
		a[num1]=x%2;
		x=x/2;
		num1++;
	}
	while(y>0){
		b[num2]=y%2;
		y=y/2;
		num2++;
	}
	//分别比较数组中的每一位得到结果 
	for(i=0;i<len;i++){
		if(a[i]!=b[i])
			num++;
	}
	return num;
}