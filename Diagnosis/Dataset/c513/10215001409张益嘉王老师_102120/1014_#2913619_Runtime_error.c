#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int a[],int len)
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
    int x,y,zheng,zi,mu,i=0,j,jin=0,nofb,zong,nofzheng,flag;
    scanf("%d%d",&x,&y);
    zheng=x/y;
    zi=x%y;
    mu=y;
    //printf("x=%d y=%d zheng=%d zi=%d mu=%d\n",x,y,zheng,zi,mu);
    int a[200],one[200],b[200];
    memset(a,0,200*sizeof(int));
    memset(b,0,200*sizeof(int));
    memset(one,0,200*sizeof(int));
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
            printf("%d",b[j]);
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
            printf("%d",b[j]);
        }
        printf(".");
        for(j=nofzheng;j<nofb;j++)
        {
            printf("%d",b[j]);
        }
    }
    return 0;

}
