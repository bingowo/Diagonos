#include <stdio.h>
#include <stdlib.h>
 int gcd(int a,int b)
 {
     if(a%b){return gcd(b,a%b);}
     else return b;
 }
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        int a[1001]={0};
        int k,j;
        for(k=0;k<n;k++)
        {
            scanf("%d",&j);
            a[j]++;
        }
        int l,m;
        int sum=0;
        for(l=0;l<1001;l++)
        {
            if(a[l])
            {for(m=l+1;m<1001;m++)
            {
                if(gcd(l,m)==1&&a[m]) sum++;
            }}
        }
        printf("%d\n",sum);
    }
}