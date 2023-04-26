#include<stdio.h>
int cmp(const void*a,const void*b){
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	if(x>y) return 1;
	else return -1;
} 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	long long a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort(a,n,sizeof(long long),cmp);
    long long temp=0;
    for(i=0;i<m;i++){
    	temp+=a[m-1]-a[i];
	}
	long long min=temp;
	for(i=1;i<n-m+1;i++){         //使用递归的方法来降低程序的时间复杂度 
		temp=temp-m*a[m-1+i]+a[i-1]+(m-1)*a[m+i];
		if(temp<min) min=temp; 
	}
	
	printf("%lld",min);
}