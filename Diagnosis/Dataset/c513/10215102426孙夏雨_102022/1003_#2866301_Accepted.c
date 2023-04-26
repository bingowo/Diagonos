#include <stdio.h>
#include <stdlib.h>

int change(long long int x)
{
    if (x>=0){
        int n=0;
        long long int y=x;
        while(y>0){
            n=n+y%2;
            y=y/2;
        }
        return n;
    }
    else {
        int n=0;
        long long int y=x;
        for (int i=0;i<64;i++){
            n=n+(1&y);
            y=y>>1;
        }
        return n;
    }
}

int cmp(const void *p1,const void *p2)
{
    long long int* p3=p1;
    long long int* p4=p2;
    long long int a=*(p3);
    long long int b=*(p4);
    int n1=change(a);
    int n2=change(b);
    if(n1>n2) return -1;
    else if(n1<n2) return 1;
    else{
        if(a>b) return 1;
        else return -1;
    }
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		int N=0;
		scanf("%d",&N);
		long long int* p=(long long int*)malloc(N*sizeof(long long int));
		for (int n=0;n<N;n++) scanf("%lld",p+n);
		qsort(p,N,sizeof(long long int),cmp);
		printf("case #%d:\n",i);
		for (int t=0;t<N;t++) printf("%lld ",*(p+t));
		printf("\n");
		free(p);
	}
	return 0;
}
