#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long int work(int n){
	long long int c[51];
	c[0]=0;c[1]=1;c[2]=2;c[3]=4;c[4]=8;
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 4;
	if(n==4) return 8;
	if(n>=5)
	{
	for(int i =5;i<=n ;i++)
        {
            c[i]=c[i-1]+c[i-2]+c[i-3]+c[i-4];
        }
        return c[n];}
}
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		int step;
		scanf("%d",&step);
		printf("case #%d:\n",v);
		long long a=work(step) ;
		printf("%lld\n",a);
	}
	return 0;
}