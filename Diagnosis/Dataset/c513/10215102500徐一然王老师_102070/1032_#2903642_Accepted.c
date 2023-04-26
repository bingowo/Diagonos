#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void *b)
{
    long long int *p1=(long long int *)a;
    long long int *p2=(long long int *)b;
    while(*p1==*p2)
    {
        p1++;p2++;
    }
    if(*p1<*p2)
    {
        return 1;
    }
    else if(*p1>*p2)
    {
        return -1;
    }
}

int main()
{
    int count,num;
    scanf("%d",&count);

    while(count--)
    {
        long long int A[1000][51];
        scanf("%d",&num);

        for(int i=0;i<num;i++)
        {
            int j=0;
            while(1)
            {
                scanf("%lld",&A[i][j]);
                if(A[i][j]==-1)
                    break;
                else{j++;}
            }
        }
        qsort(A,num,sizeof(A[0]),cmp);
        for(int i=0;i<num;i++)
        {
            int j=0;
            while(1)
            {
                if(A[i][j+1]==-1)
                {
                    printf("%lld\n",A[i][j]);
                    break;
                }
                else
                {
                    printf("%lld ",A[i][j]);
                    j++;
                }

            }

        }
    }
}
