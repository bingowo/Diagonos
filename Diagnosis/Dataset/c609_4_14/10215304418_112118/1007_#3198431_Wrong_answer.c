#include <stdio.h>
#include <stdlib.h>

long long a[10010];

int f(long long x){
	long long d=1;
	int number=0;
	for (int i=0;i<64;i++){
		if (x&d) number++;
		d=d << 1;
	}
	return number;
}

int cmp(const void* x,const void* y){
    long long xx=*(long long*)x,yy=*(long long*)y;
    if (f(xx)==f(yy)){
        return *(long long*)x-*(long long*)y;
    }
    else return f(yy)-f(xx);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        qsort(a+1,n,sizeof(a[1]),cmp);
        printf("case #%d:\n",l-1);
        for (int i=1;i<=n;i++)
            printf("%lld %d ",a[i],f(a[i]));
        printf("\n");
    }
    return 0;
}
