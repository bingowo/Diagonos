#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,n,j,i,NUM,k,A,z,e,q,w,r;
	long long int x;
	long long int a[10000][2];  //二维数组 一维按照1的位数大小排序，二维放置具体数字 
	scanf("%d",&t);  //问题数 
	for(i=0;i<t;i++){
		scanf("%d",&n);  //待排序的总数 
		for(j=0;j<n;j++){
			scanf("%lld",&x);  //具体数字  存入数组 
			a[j][1]=x;NUM=0;
			for(k=0;k<62;k++){  //与运算 
				A=x&(1<<k);
				if(A!=0)NUM++;
			}
			a[j][0]=NUM;  //1的位数记入一维数组 
			if(j==0);
			else{  //开始排序 
				z=j-1;e=j;
				while(a[e][0]>a[z][0]){
					q=a[e][0];w=a[e][1];
					a[e][0]=a[z][0];a[z][0]=q;
					a[e][1]=a[z][1];a[z][1]=w;
					z--;e--;
				}  //按1位数大小进行排序 
				if(a[e][0]==a[z][0]){
					if(a[e][1]<a[z][1]){
						q=a[e][0];w=a[e][1];
					    a[e][0]=a[z][0];a[z][0]=q;
					    a[e][1]=a[z][1];a[z][1]=w;
					}  //按具体数字大小排序 
				}
			}	 
		}
		if(n==1)printf("case #%d:\n%lld\n",i,x);
		else{
			printf("case #%d:\n",i);
			for(r=0;r<n;r++){
				printf("%lld ",a[r][1]);
			}
			printf("\n");
		}
	}
	return 0;
}