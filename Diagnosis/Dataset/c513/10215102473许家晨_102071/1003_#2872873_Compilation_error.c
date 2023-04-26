#include<stdio.h>
#include<stdlib.h>
int cnt(long long x)
{	int cnt=0;
    for(int i=0;i<128;i++){
    	if((x>>i)&1==1){
    		cnt++;
		}
		
	}
    return cnt;
}
int cmp(const void *a,const void *b)
{
    long long *pa=(long long*)a;
    long long *pb=(long long*)b;
    int cnta=cnt(*pa);
    int cntb=cnt(*pb);
    if(cnta==cntb){
    	if(*pa>*pb){
    		
			return 1;
		}
		else {
			return -1;
		}
	}
    return cntb-cnta;
}
int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T)
    {
        int N;
        int i=0;
        scanf("%d",&N);
        
        int x=N;
        long long *a=(long long*)malloc(N*sizeof(long long));
        while(N)
        {
            scanf("%lld",&a[i]);
           
            i++;
            N--;
        }
        qsort(a,n,sizeof(long long),cmp);
        printf("case #%d:\n",cnt);
        for(i=0; i<x; i++)
        {
            printf("%lld",a[i]);
            if(i!=x-1)printf(" ");
            else
            {
                printf("\n");
            }
        }
        T-=1;
        cnt++;
        free(a);
    }

    return 0;
}