#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Num(long long int x)
{
    int i = 0;
    long long int n;
    if(x<0)
    {
        n = x;
        x = ~x;
        }
    
        while(x>0)
        {
            i = i+x%2;
            x = x/2;
        }
    if(n<0)i = 64-i;
    return i;
}
int cmp(const void*a,const void*b)
{
    int *p1 = a;
    int *p2 = b;
    if(Num(*p1)==Num(*p2)) return *p1-*p2;
    else return (Num(*p2)-Num(*p1));
}

int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    int s[n];
    long long int a[n][1000];
    for(i = 0;i<n;i++)
    {
        scanf("%d",&s[i]);
        for(j = 0;j<s[i];j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
   for(i = 0;i<n;i++)
             qsort(a[i],s[i],sizeof(a[0][0]),cmp);
    for(i = 0;i<n;i++)
    {
        printf("case #%d:\n",i);
        for(j = 0;j<s[i];j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
