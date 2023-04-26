#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    int *s1,*s2;
    s1=(int*)a;
    s2=(int*)b;

    while(*s1==*s2&&*s1!=-1&&*s2!=-1)
    {
        s1++;s2++;
    }
    return *s2-*s1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        //printf("number:");
        scanf("%d",&N);
        int data[1001][51];
        for(int k=0;k<N;k++)
        {
            int j=0;
            while(scanf("%d",&data[k][j])&&data[k][j]!=-1)
                j++;
        }

        qsort(data,N,sizeof(data[0]),cmp);
        int q;
        for(int p=0;p<N;p++)
        {
            for(q=0;data[p][q+1]!=-1;q++)
            {
                printf("%d ",data[p][q]);

            }
             printf("%d\n",data[p][q]);
        }


    }

    return 0;
}
