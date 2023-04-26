#include<stdio.h>
#include<stdlib.h>

int two(long long int x)
{int num=0,n=64;
    while(n--)
    {
        if(x&1==1)num++;
        x=x>>1;
    }
    return num;
}

int cmp(const void*a,const void*b)
{int ans1,ans2;
    ans1=two(*(long long int *)a);
    ans2=two(*(long long int *)b);
    if(ans1==ans2)
    {
        if(*(long long int *)a<*(long long int *)b)
    {
        return -1;
    }
    else if(*(long long int *)b>*(long long int *)a)
    {
        return 1;
    }
    else return 0;
    }
    else if(ans1>ans2)
    {
        return -1;
    }
    else if(ans1<ans2)
    {
        return 1;
    }

}

int main()
{
    int count,count1,N,N1,i=0,j=0;
    long long int *p;
    long long int A[10000];
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&N);
        N1=N;
        while(N--)
        {

            p=A;
            scanf("%lld",&A[i]);
            i++;
        }
        qsort(p,N1,sizeof(long long int),cmp);
        printf("case #%d:\n",count1-count-1);
        while(i)
        {
            if(i==1)
                printf("%lld ",A[j]);
            else
                printf("%lld ",A[j]);
            j++;
            i--;
        }
        printf("\n");
        i=0;
        j=0;

    }
}