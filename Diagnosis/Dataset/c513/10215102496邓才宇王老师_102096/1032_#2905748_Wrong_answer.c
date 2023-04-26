#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *p1,const void *p2)
{
    int* a;
    int* b;
    a=(int*)p1;
    b=(int*)p2;
    while(*a&&*b)
    {
        if(*a!=*b) return *b-*a;
        else
        {
            a++;b++;
        }
    }
    if(*a==0) return 1;
    else return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        int s[1001][51];
        int num[1001];
        for(int j=0;j<N;j++)
        {
              int m=0,n;
            do{scanf("%d",&s[j][m++]);}while(n=getchar()!='\n');
            num[j]=m;
        }
        qsort(s,N,sizeof(s[0]),cmp);
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<num[j]+10;k++)
            {
                if(s[j][k]==-1) break;
                else printf("%d ",s[j][k]);
            }
            printf("\n");
        }
    }
}
