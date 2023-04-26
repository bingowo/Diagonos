#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("case #%d:\n",i);
        if(m==n||n==0) printf("1\n");
        unsigned long long sum=1;
        int j,k;int temp=n;
        if(n==21) n=20;
        for(j=m,k=0;k<temp;k++,j--)
        {
            if(j%n==0) {sum=sum*(j/n);n--;}
            else sum=sum*j;
        }
        for(;n>=1;n--) sum=sum/n;
        sum=sum/21;
        if(m!=temp&&temp!=0) printf("%llu\n",sum);
    }
    return 0;
}
