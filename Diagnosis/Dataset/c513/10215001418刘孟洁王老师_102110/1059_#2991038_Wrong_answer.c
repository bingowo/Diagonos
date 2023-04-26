#include <stdio.h>
#include <stdlib.h>

int GCD(int m,int n)
{
    if(m%n == 0)return n;
    else if(n%m == 0)return m;
    if(m > n)m %= n;
    else if(m < n)n %= m;
    return GCD(m,n);
}

int cmp(const void*a,const void*b)
{
    int c = *(int*)a;
    int d = *(int*)b;
    if(c>d)return -1;
    else return 1;
}

int main()
{
    int i,j,sum,num,n,s,a[1007];
    scanf("%d%d",&n,&s);
    for(i = 0; i < n; i++)scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    for(i = 0; i < n; i++)
        {
            sum = 0;
            for(j = i+1; j < n; j++)sum += a[i] - a[j];
            if(sum <= s){num = n-i;break;}
        }

    s -= sum;
    int m = GCD(s,num);
    s /= m;
    num /= m;
    if(s >= num){a[i]++;s -= num;}
    if(a[i] == 0)
    {
        if(s == 0)printf("0");
        else if(s == 0)printf("%d/%d",s,num);
    }
    else 
    {
        if(s == 0)printf("%d",a[i]);
        else printf("%d+%d/%d",a[i],s,num);
    }
    return 0;
}