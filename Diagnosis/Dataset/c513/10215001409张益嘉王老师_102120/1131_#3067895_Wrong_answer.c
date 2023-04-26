#include <stdio.h>
#include <stdlib.h>

void reverse(int s[],int len)
{
    int i,mid;
    for(i=0;i<len/2;i++)
    {
        mid=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=mid;
    }
}

int main()
{
    int a,b,zheng,zi,mu,i,co1=0,co2=0;
    scanf("%d%d",&a,&b);
    zheng=abs(a)/b;
    zi=abs(a)%b;
    mu=b;
    int qian[30];
    int hou[30];
    memset(qian,0,sizeof(int)*30);
    memset(hou,0,sizeof(int)*30);
    //printf("zheng=%d zi=%d\n",zheng,zi);
    while(zheng!=0)
    {
        qian[co1++]=zheng%3;
        zheng/=3;
    }
    while(zi!=0)
    {
        hou[co2++]=zi%3;
        zi/=3;
    }
    /*printf("test:\n");
    for(i=0;i<co1;i++)
    {
        printf("%d",qian[i]);
    }
    printf("\n");*/
    //if(co2==0) co2=1;
    /*for(i=0;i<co2;i++)
    {
        printf("%d",hou[i]);
    }*/
    if(co1==0) co1=1;
    int jin=0,mid;
    for(i=0;i<co2;i++)
    {
        mid=hou[i]+1+jin;
        jin=mid/3;
        hou[i]=mid%3;
    }
    for(i=0;(i<co1)||(jin!=0);i++)
    {
        mid=jin+qian[i]+1;
        qian[i]=mid%3;
        jin=mid/3;
    }
    //printf("test:\n");
    /*for(i=0;i<co1;i++)
    {
        printf("%d",qian[i]);
    }
    printf("\n");*/
    co1=i;


    for(i=0;i<co1;i++)
    {
        qian[i]--;
    }
    for(i=0;i<co2;i++)
    {
        hou[i]--;
    }

    for(i=co1-1;i>=0;i--)
    {
        if(qian[i]==0) co1--;
        if(qian[i]!=0) break;
    }
    reverse(qian,co1);
    reverse(hou,co2);
    for(i=co2-1;i>=0;i--)
    {
        if(hou[i]==0) co2--;
        if(hou[i]!=0) break;
    }

    if(a>=0)
    {
        for(i=0;i<co1;i++)
        {
            if(qian[i]==-1) printf("2");
            else printf("%d",qian[i]);
        }
        if(co1==0) printf("0");
        if(co2>0) printf(".");

        for(i=0;i<co2;i++)
        {
            if(hou[i]==-1) printf("2");
            else printf("%d",hou[i]);
        }
    }
    else
    {
            for(i=0;i<co1;i++)
        {
            if(qian[i]==-1) printf("1");
            else if(qian[i]==1) printf("2");
            else if(qian[i]==0) printf("0");
        }
        if(co1==0) printf("0");
        if(co2>0) printf(".");

        for(i=0;i<co2;i++)
        {
            if(hou[i]==-1) printf("1");
            else if(hou[i]==1) printf("2");
            else if(hou[i]==0) printf("0");
        }
    }
    return 0;

}
