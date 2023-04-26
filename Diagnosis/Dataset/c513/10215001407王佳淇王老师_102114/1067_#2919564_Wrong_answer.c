#include<stdio.h>
#include<math.h>
long long int tri(int n){
    int a=0,b=1,c=1,i=3;
    long long t=0;
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    for(i=3;i<=n;i++)
    {
        t=a+b+c;
        a=b;
        b=c;
        c=t;
    }
    return t;
}	
int main(){
	int T,N;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		scanf("%d\n",&N);
		long long ans=tri(N);
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
		
	}
	return 0;
	
} 