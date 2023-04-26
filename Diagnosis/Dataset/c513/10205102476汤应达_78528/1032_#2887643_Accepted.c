#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int cmp(const void*a,const void*b)
{
    int*a0=*(int**)a,*b0=*(int**)b;
    for(int i=0;i<51;i++)
    {
        if(a0[i]==b0[i]);
        else if(a0[i]>b0[i]) return -1;
        else if(a0[i]<b0[i]) return 1;
    }
    return -1;
}

int main()
{
    int T,N,d,p;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        int** num=(int**)malloc(sizeof(int*)*N);
        for(int i=0;i<N;i++) num[i]=(int*)malloc(sizeof(int)*51);
        for(int i=0;i<N;i++)
            for(int j=0;j<51;j++) num[i][j]=0;
        for(int i=0;i<N;i++)
        {
            p=0;scanf("%d",&d);
            while(d!=-1) {num[i][p++]=d;scanf("%d",&d);}
        }
        qsort(num,N,sizeof(num[0]),cmp);
        for(int i=0;i<N;i++)
        {
            p=0;
            while(num[i][p]!=0) printf("%d ",num[i][p++]);
            printf("\n");
        }
    }
    
    return 0;
}
