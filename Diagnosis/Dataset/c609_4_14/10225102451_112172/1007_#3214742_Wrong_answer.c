#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int* p1=(int*)a;
    int* p2=(int*)b;
    if(getone(*p1)==getone(*p2))
        return *p1-*p2;
    return getone(*p2)-getone(*p1);
}

int main()
{
    int t;
    scanf("%d",&t);
    int i=0;
    int values[10000];
    for(;i<t;i++){
        int n;
        scanf("%d",&n);
        int j=0;
        for (;j<n;j++){
            scanf("%d",&values[j]);
        }
        qsort(values,n,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n-1;j++){
            printf("%d ",values[j]);
        }
        printf("%d\n",values[n-1]);

    }
    return 0;

}

int getone(int n)
{
    int answer=0;
    if(n>=0){
        while(n)
        {
            answer+=n&1;
            n=n>>1;
        }
    }
    else
        return 64-getone(n^(~0));
    return answer;

}