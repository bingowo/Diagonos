#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,a,n;
char s[10005];
struct node{
	int num[1005],cnt;
}A;
int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d%d",&a,&n);
		A.num[A.cnt=1]=a;
		printf("case #%d:\n",c);
		if(n==0) puts("1");
		else{
			for(int p=1;p<n;p++){
				for(int i=1;i<=A.cnt;i++) A.num[i]*=a;
				for(int i=1;i<A.cnt;i++) A.num[i+1]+=A.num[i]/10,A.num[i]%=10;
				if(A.num[A.cnt]>9){
					A.cnt++;A.num[A.cnt]=A.num[A.cnt-1]/10,A.num[A.cnt-1]%=10;
				}
			}
			for(int i=A.cnt;i;i--) printf("%d",A.num[i]);
			puts("");
		}
	}
	return 0;
}