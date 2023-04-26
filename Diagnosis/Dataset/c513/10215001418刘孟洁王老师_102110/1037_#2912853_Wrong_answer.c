#include<stdio.h>
#include <stdlib.h>


int min(int s[],int n)
{
    int i = 0;
    while(i<n-1)
    {
       if(s[i] < s[i+1]) s[i+1] = s[i] , i++;
        else i++;
    }
    return s[i];
}

int cmp(const void*a,const void*b)
{
    int c = *(int *)a;
    int d = *(int *)b;
    if(c < d)return 1;
    else return -1;
}

int main()
{
    int n,m,i,j,k;
    int *s,*sum;
    scanf("%d%d",&n,&m);
    s = (int *)malloc(n * sizeof(int));
    sum = (int *)malloc((n-m+1)*sizeof(int));
    for(i = 0;i < n-m+1; i++)sum[i]=0;
    for(i = 0;i < n ; i++)scanf("%d",&s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    for(i = 0; i <= n-m; i++)
    {
        for(j = i+1, k = 0; k < m-1; k++, j++)
        {
            sum[i] = sum[i] + s[i]-s[j];
        }
    }
    printf("%d",min(sum,i));
    return 0;
}
