#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h> 
//降序排列 
int  cmp(const void* a,const void*b)
 {unsigned long long int*aa=(unsigned long long int*)a;
 unsigned long long int*bb=(unsigned long long int*)b;
 return *bb>*aa;
 }
 
unsigned long long pick(unsigned long long* L,int n,int m)
{   unsigned long long res = 0,MIN=0;
    for(int i=0;i<=n-m;i++){
    	for(int j=i+1;j<i+m;j++) res+=L[i]-L[j];
    	MIN=MIN==0?res:fmin(MIN,res);
    	res=0;
	}
	return MIN;
}

int main(){
	int n,m;
	unsigned long long int l[1000001];
	scanf("%d %d\n",&n,&m);
	for (int i=0;i<n;i++) scanf("%llu ",&l[i]);
    qsort(l,n,sizeof(unsigned long long int),cmp);
    unsigned long long int res = pick(l,n,m);
    printf("%llu\n",res);
    return 0;
}