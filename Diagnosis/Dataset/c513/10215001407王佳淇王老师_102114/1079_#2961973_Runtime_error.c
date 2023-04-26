#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*a,const void*b){
	long long int a1=*(long long int *)a;
	long long int b1=*(long long int *)b;
	if(a1==b1) return 0;
	else return a1>b1?1:-1;
} 
int main(){
	int T;
	scanf("%d",&T);//题目数 
	for(int v=0;v<T;v++){
		printf("case #%d:\n",v);
		int n,m;
		scanf("%d %d",&n,&m);
		int a[1001],cnt=0;
		long long int b[50501]={0};
		for(int j=1;j<n;j++) {scanf("%d",a+j);a[j]+=a[j-1];}//初始数组 
		for(int len=1;len<=n;len++)
            for(int i=1;i<=n-len+1;i++)
                b[++cnt]=a[i+len-1]-a[i-1];
		 qsort(b,cnt,sizeof(b[0]),cmp); 
		for(int i=1;i<=cnt;i++) b[i]+=b[i-1];
		for(int k=0;k<m;k++) {//对该数组求l~u 	
			int l,u;
			scanf("%d %d",&l,&u);
	     	printf("%lld\n",b[u]-b[l-1]);
		}
		
	}
	return 0;
}