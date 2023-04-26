#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int*)b - *(int*)a;
}
int Turn(x)
{
    int i,j = 1,k,m,u = 0;
    int a[10000];
    for(i  = 0;x>0;i++)
    {
        m = x%2;
        x = x/2;
        a[i] = m;
    }
    for(k= 0;k<i-1;k++)
    {
        if(a[k+1]==a[k])
        {
            a[u] = j;
            j = 1;
            u++;
        }
        else j++;
    }
    a[u] = j;
    qsort(a,u+1,sizeof(a[0]),cmp);
    j = a[0];
    return j;
}
int main()
{
    int n;
    int i;
    scanf("%d",&n);
    long long int s[n];
    for(i = 0;i<n;i++)
        scanf("%lld",&s[i]);
    for(i = 0;i<n;i++)
    {
        printf("case #%d:\n%d\n",i,Turn(s[i]));
    }
    return 0;

}
