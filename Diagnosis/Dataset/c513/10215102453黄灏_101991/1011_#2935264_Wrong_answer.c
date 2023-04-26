#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    scanf("%x",&c);

    int t[1000],j=0;
    while(c!=0){
        t[j]=c%2;
        c=c/2; j++;
    }
    printf("%d\n",j);
    t[j]='\0';
    j=j-1;
    //for(;j>=0;j--)
        //printf("%d ",t[j]);

    long long int qr=0,qi=0,a,b;
    for(int i=0;i<=j;i++){
        int r=t[i];
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }

    printf("lld",qr);
    if(qi>0) printf("+""%lld",qi,"i\n");
    else if(qi<0) printf("-","%lld",qi,"i\n");
    return 0;
}
