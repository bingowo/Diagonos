#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void sort(int*s,int m)
{
    int cmp(const void*a1,const void*a2)
    {
        long long int a=*(long long int*)a1;
        long long int b=*(long long int*)a2;
        long long int ad,bd,ac=0,bc=0,at=a,bt=b;
        while(at!=0)
        {ac++;at/=10;}
        ad=a/pow(10,ac-1);
        while(bt!=0)
        {bc++;bt/=10;}
        bd=b/pow(10,bc-1);
        if(ad>bd) return -1;
        else if(ad<bd) return 1;
        else return a-b;
    }
    qsort(s,m,sizeof(s[0]),cmp);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        long long int a[m+1];
        for(int k=0;k<m;k++)
        {
            scanf("%lld",&a[k]);
        }
        sort(a,m);
        printf("case #%d:\n",i);
        for(int l=0;l<m;l++)
        printf("%lld ",a[l]);
        printf("\n");
    }
    return 0;
}