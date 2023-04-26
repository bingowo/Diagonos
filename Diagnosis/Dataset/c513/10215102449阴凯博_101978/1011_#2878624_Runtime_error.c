#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    long long r;
    long long f;
} NUM;

NUM mul(NUM a,NUM b)
{
    NUM n;
    n.f=a.r*b.f+b.r*a.f;
    n.r=a.r*b.r-a.f*b.f;
    return n;
}

NUM pwr(int a)
{
    NUM n,m;
    m.f=1; m.r=-1;
    n.f=0; n.r=1;
    int i;
    for (i=0;i<a;i++)
        n=mul(n,m);
    return n;
}




int main()
{
    int i,j,k;
    long long m;
    int arr[10000]={0};
    scanf("%llx",&m);
    for (i=0;m>>i;i++)
    {
        arr[i]=m>>i&1;
    }
    NUM n;
    n.r=0; n.f=0;
    long long qr=0,qi=0;
    long long a,b;
    for (j=0,k=i-1;j<k;j++,k--)
    {
        int tmp=arr[j];
        arr[j]=arr[k];
        arr[k]=tmp;
    }
    for (j=0;j<i;j++)
    {
        a=-qr-qi+arr[j];
        b=qr-qi;
        qr=a;qi=b;
    }
    if (qi==0) printf("%lld\n",qr);
    else
    {
        if (qr!=0)
        {
            printf("%lld",qr);
            if (qi>0) printf("+");
        }
        if (qi==1) printf("i\n");
        else if (qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
    return 0;
}
