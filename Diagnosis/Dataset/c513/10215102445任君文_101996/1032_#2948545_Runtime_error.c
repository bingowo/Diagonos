#include<stdio.h>
#define M 1000
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int T,N;
    int sort[M]={0};
    unsigned long long num[M][50]={0};
    int i=0,j=0,k=0,t=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            sort[j]=j;
            scanf("%llu",&num[j][0]);
            k=0;
            while(num[j][k]!=-1)
            {
                k++;
                scanf("%lld",&num[j][k]);
            }
        }
        for(j=0;j<N-1;j++)
        {
            for(k=0;k<N-1-j;k++)
            {
                t=0;  
                while(num[sort[k]][t]==num[sort[k+1]][t])
                {
                    t++;
                    if((num[sort[k]][t]==-1)||(num[sort[k]][t]==-1))
                    {
                        break;
                    }
                }
                if((num[sort[k]][t]==-1)&&(num[sort[k+1]][t]!=-1))
                {
                    swap(sort[k],sort[k+1]);
                }
                else if(num[sort[k]][t]<num[sort[k+1]][t])
                {
                    swap(sort[k],sort[k+1]);
                }
            }
        }
        for(j=0;j<N;j++)
        {
            k=0;
            while(num[sort[j]][k]!=-1)
            {
                printf("%llu ",num[sort[j]][k]);
                num[sort[j]][k]=0;
                k++;
            }
            printf("\n");
        }
    }
    return 0;
}