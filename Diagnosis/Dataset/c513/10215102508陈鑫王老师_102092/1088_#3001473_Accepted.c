#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        int m,n,large=1,small=1,i=1;
        unsigned long long int p=1;
        scanf("%d %d",&m,&n);
    if(m>2*n){small=n;large=m-n;}
    else{small=m-n;large=n;}
    for(i=m;i>large;i--)
    {
        if(i==2*small)
        {
            p=p*2;
            small--;
        }
        else p=p*i;
    }
    while(small>1)
    {
        p=p/small;
        small--;
    }
    printf("case #%d:\n",k);
    printf("%llu\n",p);
    }
    return 0;

}
