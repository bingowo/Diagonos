#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void *b)
{
    return *((int *)b) - *((int *)a);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int s[100000];
    for(i = 0;i<n;i++)
        scanf("%d",&s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    int j,x = 0;
    for(i = 0;i<n;)
    {
        x = x+s[i]-s[i+1];
        i = i+2;
    }
    printf("%d",x);
    return 0;

}
