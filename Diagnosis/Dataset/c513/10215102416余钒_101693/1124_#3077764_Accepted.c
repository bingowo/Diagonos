#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int T,n; 
int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int cmp(const void* a,const void* b){
	int x=*(int*)a,y=*(int*)b;
	return x-y;
}
int a[1005],b[1005];
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		qsort(a+1,n,sizeof(int),cmp);
		int pos=0;
		for(int i=1;i<=n;i++)
			if(pos==0||a[i]!=b[pos]) b[++pos]=a[i];
		int ans=0;
		for(int i=1;i<=pos;i++)
			for(int j=i+1;j<=pos;j++){
				if(gcd(b[j],b[i])==1) ans++;
			}
		printf("case #%d:\n%d\n",c,ans);
	}
	return 0;
}