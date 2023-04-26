#include <stdio.h>

int main()
{
    long long a,b,c,d,x,la,lb,i,l,r;
    int a0[100],b0[100],c0[200];
    scanf("%lld%lld",&a,&b);
    c=a/b;
    d=a%b;
    la=0;
    while(c>0){
        a0[la]=c%3;
        c=c/3;
        la++;
    }
    x=b/3;
    lb=0;
    while(x>0){
        b0[lb]=d/x;
        d=d%x;
        x=x/3;
        lb++;
    }
    for(i=0;i<la;i++)
        c0[i+1]=a0[la-1-i];
    for(i=la;i<la+lb;i++)
        c0[i+1]=b0[i-la];
    c0[0]=0;
    for(i=la+lb;i>0;i--){
        c0[i]++;
        if(c0[i]>2){
            c0[i]=c0[i]-3;
            c0[i-1]++;
        }
    }
    for(i=1;i<=la+lb;i++)
        c0[i]--;
    l=0;
    while(l<=la&&c0[l]==0)
        l++;
    r=la+lb;
    while(r>la&&c0[r]==0)
        r--;
    if(l==la+1)
        printf("0");
    else
        for(i=l;i<=la;i++)
            if(c0[i]!=-1)
                printf("%d",c0[i]);
            else
                printf("2");
    if(r>la){
        printf(".");
        for(i=la+1;i<=r;i++)
            if(c0[i]!=-1)
                printf("%d",c0[i]);
            else
                printf("2");
    }
    printf("\n");
    return 0;
}
