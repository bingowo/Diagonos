#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h> 
//降序排列 
int  cmp(const void* a,const void*b)
 {long long int*aa=(long long int*)a;
 long long int*bb=(long long int*)b;
 return *bb>*aa;
 }
 long long min(long long a,long long b){
	if(a<=b) return a;
	else return b;
	
}
long long pick(long long* L,int n,int m)
{   long long res = 0,MIN=0;
    for(int i=0;i<=n-m;i++){
    	for(int j=i+1;j<i+m;j++) res+=L[i]-L[j];
    	MIN=MIN==0?res:min(MIN,res);
    	res=0;
	}
	return MIN;
}
int main(){
	int n,m;
	long long int l[1000001];
	scanf("%d %d\n",&n,&m);
	for (int i=0;i<n;i++) scanf("%lld ",&l[i]);
    qsort(l,n,sizeof(long long int),cmp);
    long long int res = pick(l,n,m);
    printf("%lld\n",res);
    return 0;
}