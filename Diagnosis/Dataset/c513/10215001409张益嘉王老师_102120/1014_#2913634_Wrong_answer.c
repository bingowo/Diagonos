#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(long long a[],long long len)
{

    int i;
    char m;
    for(i=0;i<len/2;i++)
    {
        m=a[i];
        a[i]=a[len-i-1];
        a[len-i-1]=m;

    }

}

int main()
{
    long long x,y,zheng,zi,mu,i=0,j,jin=0,nofb,zong,nofzheng,flag;
    scanf("%lld%lld",&x,&y);
    zheng=x/y;
    zi=x%y;
    mu=y;
    //printf("x=%d y=%d zheng=%d zi=%d mu=%d\n",x,y,zheng,zi,mu);
    long long a[2000],one[2000],b[2000];
    memset(a,0,2000*sizeof(long long));
    memset(b,0,2000*sizeof(long long));
    memset(one,0,2000*sizeof(long long));
    while(zheng!=0)
    {
        a[i]=zheng%3;
        zheng/=3;

        i++;
    }
    nofzheng=i;
    //printf("test: nofzheng=%d\n",nofzheng);
    //for(j=0;j<nofzheng;j++) {printf("test:a[%d]=%d\n",j,a[j]);}

    if(zi==0)
    {
        for(j=0;j<nofzheng;j++)
        {
            one[j]=1;
        }
        j=0;
        while((j<nofzheng)||(jin>0))
        {

            b[j]=(a[j]+one[j]+jin)%3;
            jin=(a[j]+one[j])/3;
            j++;
        }
        nofb=j;
        for(j=0;j<nofb;j++)
        {
            b[j]-=one[j];
        }
        //for(j=0;j<nofb;j++) {printf("test:b[%d]=%d\n",j,b[j]);}
        for(j=0;j<nofb;j++)
        {
            if(b[j]==-1) b[j]=2;
        }
        reverse(b,nofb);
        for(j=0;j<nofb;j++)
        {
            printf("%lld",b[j]);
        }
    }
    else
    {
        reverse(a,nofzheng);
        while((mu/3)!=0)
        {
            mu/=3;
            a[i++]=zi/mu;
            zi=zi%mu;
        }
        zong=i;
        reverse(a,zong);
        //for(j=0;j<zong;j++) {printf("test:a[%d]=%d\n",j,a[j]);}
        for(j=0;j<zong;j++)
        {
            one[j]=1;
        }
        j=0;
        while((j<zong)||(jin>0))
        {

            b[j]=(a[j]+one[j]+jin)%3;
            jin=(a[j]+one[j]+jin)/3;
            j++;
        }
        //for(j=0;j<nofb;j++) {printf("first proceed test:b[%d]=%d\n",j,b[j]);}
        nofb=j;
        nofzheng+=nofb-zong;
        for(j=0;j<nofb;j++)
        {
            b[j]-=one[j];
        }
        for(j=0;j<nofb;j++)
        {
            if(b[j]==-1) b[j]=2;
        }
        //for(j=0;j<nofb;j++) {printf("before reverse test:b[%d]=%d\n",j,b[j]);}
        reverse(b,nofb);
        //for(j=0;j<nofb;j++) {printf("test:b[%d]=%d\n",j,b[j]);}
        for(j=0;j<nofzheng;j++)
        {
            if(b[j]!=0) {flag=j;break;}
        }
        for(j=flag;j<nofzheng;j++)
        {
            printf("%lld",b[j]);
        }
        if (flag>=nofzheng) printf("0");
        printf(".");
        for(j=nofzheng;j<nofb;j++)
        {
            printf("%lld",b[j]);
        }
    }
    return 0;

}
