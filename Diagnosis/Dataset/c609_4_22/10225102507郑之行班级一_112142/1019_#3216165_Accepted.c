#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int abs(int n)
{
    if(n<0)n=-n;
    return n;
}

int cntn(int n)
{
    int cnt=1;
    while (n/10>0){cnt++;n/=10;};
    //printf("%d\n",cnt);
    return cnt;
}

int cmp(const void* a,const void* b)
{
    if ( cntn(abs(*(int*)a)) > cntn(abs(*(int*)b)))return -1;
    else if ( cntn(abs(*(int*)a)) < cntn(abs(*(int*)b)))return 1;
    else
    {
        if (*(int*)a <= *(int*)b )return -1;
        else return 1;
    }

}


int main()
{
    int num[N];
    for (int i=0;i<N;i++)num[i]=0;
    int n=0;
    while (~scanf("%d",&num[n++]));
    n--;

    qsort(num,n,sizeof(int),cmp);

    for (int i=0;i<n;i++)
   {
       printf("%d",num[i]);
       if (i==n-1)printf("\n");
       else printf(" ");
    }

    return 0;
}
