#include <stdio.h>

int main()
{
    long long a,b,c,d,x,la,lb,i;
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
    if(c0[0]==1)
        printf("1");
    for(i=1;i<=la;i++)
        if(c0[i]==-1)
            printf("2");
        else
            printf("%d",c0[i]);
    if(lb!=0){
        printf(".");
        for(i=la+1;i<=la+lb;i++)
            if(c0[i]==-1)
                printf("2");
            else
                printf("%d",c0[i]);
    }
    printf("\n");
    return 0;
}