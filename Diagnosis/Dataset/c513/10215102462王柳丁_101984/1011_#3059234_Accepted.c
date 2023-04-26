#include <stdio.h>
#include <stdlib.h>


int main()
{
    char hex[1000];
    scanf("0x%s",hex);
    int bin[1000];
    int i,d,j,k=0;
    for(i=0;i<strlen(hex);i++)
    {
        if(hex[i]>='A')d=hex[i]-'A'+10;
        else d=hex[i]-'0';
        unsigned int judge=0x8;
        for(j=0;j<4;j++)
        {
            if(d&judge)bin[k++]=1;
            else bin[k++]=0;
            //printf("%d",bin[k-1]);
            judge=judge>>1;
            //printf("(%d)",judge);
        }
        //printf("%d",k);
    }
    //for(i=0;i<k;i++)printf("%d",bin[i]);
   // printf("\n");
    long long int a=0,b=0,qr=0,qi=0,r;
    for(i=0;i<k;i++)
    {
        r=bin[i];//printf("r=%lld\n",r);
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
        //printf("qr=%lld,qi=%lld",qr,qi);
    }

    if(qi==0)
    {
        printf("%lld\n",qr);
    }
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }

}
