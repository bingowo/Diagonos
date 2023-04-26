#include<stdio.h>
#include<stdlib.h>
int binary(long long int a){
	int m=0;
	long long int n=1;
	for(int i=64;i>0;i--,a=a>>1)m+=(a&n);
	return m;
}
int cmp1(const void *a,const void *b){//jiangxu
	int m,n;
	long long int a1,b1;
	a1=*(long long int *)a,b1=*(long long int *)b;
	m=binary(a1);
	n=binary(b1);
	if(m>n)return -1;
	if(m<n)return 1;
	if(a1>b1)return 1;
	else return -1;
}
int cmp2(const void *a,const void *b){//shengxu
	int m,n;
	long long int a1,b1;
	a1=*(long long int *)a,b1=*(long long int *)b;
	m=binary(a1);
	n=binary(b1);
	if(m>n)return 1;
	if(m<n)return -1;
	if(a1>b1)return -1;
	else return 1;
}
int main(){
    char x;
    scanf("%c",&x);
    long long int m[1000];
    int i=0;
    while(scanf("%d",&m[i++])!=EOF)
    if(x=='D')qsort(m,i-1,sizeof(long long int),cmp1);
    if(x=='A')qsort(m,i-1,sizeof(long long int),cmp2);
    for(int p=0;p<i;p++)printf("%lld ",m[p]);
	return 0;
}
