#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long int t,n,j,i,NUM,k,A,q,r;
	long long int e,z,w,x,b;
	long long int a[10000],c[10000];  //数组 c按照1的位数大小排序，a放置具体数字 
	scanf("%lld",&t);  //问题数 
	for(i=0;i<t;i++){
		scanf("%lld",&n);  //待排序的总数 
		for(j=0;j<n;j++){
			scanf("%lld",&x);  //具体数字  存入数组 
			a[j]=x;NUM=0;
			for(k=0;k<=63;k++){  //与运算 
		        b=1LL<<k;
				A=x&b;
				if(A!=0)NUM++;
			}
			c[j]=NUM;  //1的位数记入c数组 
			if(j==0);
			else{  //开始排序 
				z=j-1;e=j;
				while(c[e]>c[z] && z>=0){
					q=c[e];w=a[e];
					c[e]=c[z];c[z]=q;
					a[e]=a[z];a[z]=w;
					z--;e--;
				}  //按1位数大小进行排序 
				if(c[e]==c[z]){
					if(a[e]<a[z]){
						q=c[e];w=a[e];
					    c[e]=c[z];c[z]=q;
					    a[e]=a[z];a[z]=w;
					}  //按具体数字大小排序 
				}
			}	 
		}
		if(n==1)printf("case #%lld:\n%lld\n",i,x);
		else{
			printf("case #%lld:\n",i);
			for(r=0;r<n;r++){
				printf("%lld ",a[r]);
			}
			printf("\n");
		}
	}
	return 0;
}