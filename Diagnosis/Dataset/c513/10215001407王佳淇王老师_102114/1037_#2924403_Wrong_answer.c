#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h> 
int  cmp(const void* a,const void*b)
 {long long int*aa=(long long int*)a;
 long long int*bb=(long long int*)b;
 return *bb>*aa;
 }
 
long long pick(long long* L,int n,int m)
{   long long res = 0;
    if (n == m){
        for (int i=1;i<n;i++) res+=L[0]-L[i];
        return res;
    }
     else{
        for (int i=1;i<m;i++) res+=L[0]-L[i];
        long long MIN = res;
        res = 0;      //将MIN赋值后，重置res
        for (int i=1;i<=n-m;i++){
            for (int j=1;j<m;j++) res += L[i]-L[i+j];
            MIN =fmin(MIN,res);
            res = 0;    //重置res
        }
       return MIN; 
}
}
int main(){
	int n,m;
	long long int l[100001];
	scanf("%d %d\n",&n,&m);
	for (int i=0;i<n;i++) scanf("%lld ",&l[i]);
    qsort(l,n,sizeof(long long int),cmp);
    long long int res = pick(l,n,m);
    printf("%lld\n",res);
    return 0;
}